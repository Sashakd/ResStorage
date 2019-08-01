#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    pic = new QPixmap(QSize(ui->imgLbl->width(), ui->imgLbl->height()));
    painter = new QPainter(pic);
    painter->setPen(QPen(Qt::white, 1));
    painter->setBrush(QBrush(Qt::white));
    painter->drawRect(-1, -1, ui->imgLbl->width(), ui->imgLbl->height());
    ui->imgLbl->setPixmap(*pic);

    ui->num_fromEdt->setValidator(new QIntValidator(this));
    ui->num_toEdt->setValidator(new QIntValidator(this));
    ui->val_edtEdt->setValidator(new QIntValidator(this));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_createBtn_clicked()
{
    FILE* fin;
    QString fname;

    painter->setPen(QPen(Qt::white, 1));
    painter->setBrush(QBrush(Qt::white));
    painter->drawRect(-1, -1, ui->imgLbl->width(), ui->imgLbl->height());
    ui->imgLbl->setPixmap(*pic);



    flag = -1;
    ui->infoLbl->setText("система дорог не загружена");
    fname = QFileDialog::getOpenFileName(this, "Открыть таблицу",
                                                 "..\\graph", "Text (*.txt)");
    if (!(fin = fopen(fname.toStdString().data(), "r")))
        QMessageBox::information(0, "Файловая ошибка", "Не удалось открыть файл с таблицей");
    else
        read_file(fin);
    fclose(fin);
    if (flag==1)
        ui->infoLbl->setText("система дорог загружена.");
    else
        return;
    print_graph();
}

int Widget::read_file(FILE* fin)
{
    int a, l;
    reb rebro;

    flag = 1;
    if (fscanf(fin, "%d", &a) != 1)
        return myInfoMsg("Файловая ошибка", "ошибка чтения файла");

    g_auto.resize(a);
    g_train.resize(a);
    g_sum.resize(a);

    for (int i=0; i<a; i++)
    {
        g_auto[i].resize(a);
        g_train[i].resize(a);
        g_sum[i].resize(a);
    }

    rebro.type = 1;
    for (int i=0; i<a; i++)
        for (int j=0; j<a; j++)
        {
            if (fscanf(fin, "%d", &l) != 1)
                return myInfoMsg("Файловая ошибка", "ошибка чтения файла");
            else
            {
                g_auto[i][j] = l;
                rebro.len = l;
                g_sum[i][j] = g_sum[j][i] = rebro;
            }
        }
    rebro.type = 0;
    for (int i=0; i<a; i++)
        for (int j=0; j<a; j++)
        {
            if (fscanf(fin, "%d", &l) != 1)
                return myInfoMsg("Файловая ошибка", "ошибка чтения файла");
            else
            {
                g_train[i][j] = l;
                if ((l>0) && ((l < g_sum[i][j].len) || (g_sum[i][j].len==0)))
                {
                    rebro.len = l;
                    g_sum[i][j] = g_sum[j][i] = rebro;
                }
            }
        }
    return 0;
}

int Widget::myInfoMsg(QString s1, QString s2)
{
    QMessageBox::information(this, s1, s2);
    flag = -1;
    return -1;
}

void Widget::on_addBtn_clicked()
{
    print_graph();
    if (ui->num_fromEdt->text().isEmpty() || ui->num_toEdt->text().isEmpty() ||
            ui->val_edtEdt->text().isEmpty() || (flag==-1))
        return;

    int i = ui->num_fromEdt->text().toInt();
    int j = ui->num_toEdt->text().toInt();
    if ((i > g_auto.size()-1) || (i<0) || (j > g_auto.size()-1) || (j<0))
        return;

    int num = ui->val_edtEdt->text().toInt();
    if (num<=0)
        return;

    ins_reb(i, j, num, ui->cmb->currentIndex());
}

void Widget::on_delBtn_clicked()
{
    print_graph();
    if (ui->num_fromEdt->text().isEmpty() || ui->num_toEdt->text().isEmpty() || (flag==-1))
        return;

    int i = ui->num_fromEdt->text().toInt();
    int j = ui->num_toEdt->text().toInt();
    if ((i > g_auto.size()-1) || (i<0) || (j > g_auto.size()-1) || (j<0))
        return;

    ins_reb(i, j, 0, ui->cmb->currentIndex());
}

void Widget::ins_reb(int i, int j, int num, int type)
{
    reb rebro;

    if (type == 0)
        g_train[i][j] = g_train[j][i] = num;
    else
        g_auto[i][j] = g_auto[j][i] = num;

    rebro.type = type;
    rebro.len = num;
    if ((num < g_sum[i][j].len || g_sum[i][j].type==type || g_sum[i][j].len==0) && num>0)
        g_sum[i][j] = g_sum[j][i] = rebro;

    if (num==0)
    {
        rebro.type = type == 0 ? 1 : 0;
        if (type)
            rebro.len = g_train[i][j];
        else
            rebro.len = g_auto[i][j];
        g_sum[j][i] = g_sum[i][j] = rebro;
    }

    print_graph();
    QMessageBox::information(0, "info", "действие выполнено успешно");
}

int AisMinOfThree(int a, int b, int c)
{
    if (a>b || a>c)
        return 0;

    return 1;
}

void Widget::on_shortBtn_clicked()
{
    ui->infoLbl->setText("маршрут недоступен.");
    print_graph();
    if (ui->otEdt->text().isEmpty() || ui->doEdt->text().isEmpty())
        return;
    int a = ui->otEdt->text().toInt(), b = ui->doEdt->text().toInt();
    if (a<0 || b<0 || a>g_auto.size()-1 || b>g_auto.size()-1)
        return;

    int min2 = dijkstra2(a, b), min1 = dijkstra1(a, b);
    int min = dijkstra(a, b);

    if (AisMinOfThree(min, min2, min1))
        dijkstra(a, b);
    if (AisMinOfThree(min2, min1, min))
        dijkstra2(a, b);
    if (AisMinOfThree(min1, min, min2))
        dijkstra1(a, b);

    draw_s();
}
