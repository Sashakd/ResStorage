#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "dialog.h"
#include "ui_dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    tableWidget->setColumnCount(0);
    fin = NULL;
    fileBtn->setToolTip(
      "загрузить таблицу из файла на диске");
    bdCbx->setToolTip(
      "выводить в текущем порядке только список людей, у которых\n" \
                "   день рождения в ближайшую неделю");
    keyBtn->setToolTip(
      "отсортировать таблицу согласно ключу \"фамилия\"");
    timeBtn->setToolTip(
       "Перезагрузите файл для получения объективных результатов");

    dialog = new Dialog;
    dialog->setModal(true);
    connect(dialog->btnOk, SIGNAL(clicked()), this, SLOT(ok_but())); // подключаем диалог
    connect(dialog->btnCancel, SIGNAL(clicked()), this, SLOT(cancel_but()));
    connect(dialog->wrBtn, SIGNAL(clicked()), this, SLOT(wr_chb()));
    connect(dialog->prBtn, SIGNAL(clicked()), this, SLOT(pr_chb()));
    dialog->edtDD->setValidator(new QIntValidator(this));
    dialog->edtMM->setValidator(new QIntValidator(this));
    dialog->edtYYYY->setValidator(new QIntValidator(this));
    dialog->edtTel->setValidator(new QIntValidator(this));

    dialog->bdGb->hide();
}

MainWindow::~MainWindow()
{
    if (fin)
        fclose(fin);
}

int MainWindow::on_fileBtn_clicked() // загрузить из файла
{
    if (fin)
        fclose(fin);
    if (data.size()!=0)
        data.remove(0, data.size());
    if (keys.size()!=0)
        keys.remove(0, keys.size());

    tableWidget->setColumnCount(0);
    tableWidget->setRowCount(0);

    fname = QFileDialog::getOpenFileName(0, "Открыть таблицу",
                                                 "..\\lab2t", "Text (*.txt)");
    fin = fopen(fname.toStdString().data(), "r");
    if (!fin)
        return myInfoMsg("Файловая ошибка", "Не удалось открыть файл с таблицей");
    read_file(fin);
    fill_table();
    return 0;
}

int MainWindow::read_file(FILE *fin) // заполнить массив записей
{
    QString str = QString::fromStdString("личный\n").toUtf8();
    char next[10];

    while (!feof(fin))
    {
        struct group *at = new struct group;

        at->name.append(getQS(fin));
        at->surname.append(getQS(fin));
        at->tel.append(getQS(fin));
        at->address.append(getQS(fin));
        at->status.append(getQS(fin));
        if (QString::compare(at->status, str))
        {
            Ui::work w;
            w.org.append(getQS(fin));
            w.position.append(getQS(fin));
            at->v.setValue<Ui::work>(w);
        }
        else
        {
            Ui::privacy p;
            p.dd = getInt(fin);
            p.mm = getInt(fin);
            p.yyyy = getInt(fin);
            at->v.setValue<Ui::privacy>(p);
        }

        data.push_back(*at);
        delete at;
        fgets(next, 10, fin);
    }

    return 0;
}

int MainWindow::fill_table() // заполнение таблицы
{
    QString str = QString::fromStdString("личный\n").toUtf8();

    tableWidget->setRowCount(0);
    tableWidget->setColumnCount(0);
    if (data.size()==0)
        return myInfoMsg("Состояние таблицы", "Таблица пуста!");
    if (keys.size()==0)
        fill_keys();

    tableWidget->setColumnCount(10);
    create_table();
    qDebug() << "fill_table: создание таблицы";

    for (int i=0; i<data.size(); i++)
    {
        if (!((!bdCbx->isChecked()) || (birthday(i) && bdCbx->isChecked())))
            continue;

        QString fields[] = {data[keys[i].pos].name, data[keys[i].pos].surname,
            data[keys[i].pos].tel, data[keys[i].pos].address, data[keys[i].pos].status};
        tableWidget->setRowCount(tableWidget->rowCount()+1);

        for (int j=0; j<5; j++)
        {
            QTableWidgetItem *tj = new QTableWidgetItem;
            tj->setText(fields[j]);
            tableWidget->setItem(tableWidget->rowCount()-1, j, tj);
        }

        QTableWidgetItem *t6 = new QTableWidgetItem;
        QTableWidgetItem *t7 = new QTableWidgetItem;
        QTableWidgetItem *t8 = new QTableWidgetItem;
        QTableWidgetItem *t9 = new QTableWidgetItem;
        QTableWidgetItem *t10 = new QTableWidgetItem;
        if (QString::compare(fields[4], str)) // не личный
        {
            t6->setText("-");
            tableWidget->setItem(tableWidget->rowCount()-1, 5, t6);
            t7->setText("-");
            tableWidget->setItem(tableWidget->rowCount()-1, 6, t7);
            t8->setText("-");
            tableWidget->setItem(tableWidget->rowCount()-1, 7, t8);
            t9->setText(data[keys[i].pos].v.value<Ui::work>().position);
            tableWidget->setItem(tableWidget->rowCount()-1, 8, t9);
            t10->setText(data[keys[i].pos].v.value<Ui::work>().org);
            tableWidget->setItem(tableWidget->rowCount()-1, 9, t10);
        }
        else
        {
            t6->setText(QString::number(data[keys[i].pos].v.value<Ui::privacy>().dd));
            tableWidget->setItem(tableWidget->rowCount()-1, 5, t6);
            t7->setText(QString::number(data[keys[i].pos].v.value<Ui::privacy>().mm));
            tableWidget->setItem(tableWidget->rowCount()-1, 6, t7);
            t8->setText(QString::number(data[keys[i].pos].v.value<Ui::privacy>().yyyy));
            tableWidget->setItem(tableWidget->rowCount()-1, 7, t8);
            t9->setText("-");
            tableWidget->setItem(tableWidget->rowCount()-1, 8, t9);
            t10->setText("-");
            tableWidget->setItem(tableWidget->rowCount()-1, 9, t10);
        }
    }
    fill_keys();
    if (tableWidget->rowCount()==0)
        return myInfoMsg("Состояние таблицы", "Никого не нашлось!");
    return 0;
}

void MainWindow::fill_keys() // заполнение массива ключей
{
    if (keys.size()!=0)
        keys.remove(0, keys.size());

    qDebug() << "data размер: "<<data.size();
    for (int i = 0; i<data.size(); i++)
    {
        struct key *elem = new struct key;
        elem->pos = i;
        elem->surname.append(data[i].surname);
        keys.append(*elem);
        delete elem;
    }
}

void MainWindow::on_delCurBtn_clicked()
{
    if (data.size()!=0)
    {
        int pos = tableWidget->currentRow();
        if ((pos >= 0) && (pos < data.size()))
        {
            pos = find_pos(pos);
            data.remove(pos,1);
            qDebug() << "delCurBtn: удаление записи" << pos;
            fill_table();
        }
    }
    else
        myInfoMsg("Состояние таблицы", "Таблица пуста!");
}

int MainWindow::ok_but()
{
    int cur = tableWidget->currentRow();
    qDebug() << "ok_but: текущая строка" << cur;
    if (dialog->edtSurname->text()=="" || dialog->edtName->text()=="" ||
            dialog->edtAddr->text()=="" || dialog->edtTel->text()=="")
        return raisedialog();

    struct group *at = new struct group;
    if (dialog->prBtn->isChecked())
    {
        if (dialog->edtDD->text()=="" || dialog->edtMM->text()=="" ||
             dialog->edtYYYY->text()=="")
            return raisedialog();
        at->status.append(QString::fromStdString("личный\n").toUtf8());
        Ui::privacy p;
        p.dd = dialog->edtDD->text().toInt();
        p.mm = dialog->edtMM->text().toInt();
        p.yyyy = dialog->edtYYYY->text().toInt();
        at->v.setValue<Ui::privacy>(p);
    }
    else
    {
        if (dialog->edtPos->text()=="" || dialog->edtOrg->text()=="")
            return raisedialog();
        at->status.append(QString::fromStdString("рабочий\n").toUtf8());
        Ui::work w;
        w.org.append(dialog->edtOrg->text());
        w.position.append(dialog->edtPos->text());
        at->v.setValue<Ui::work>(w);
    }
    at->name.append(dialog->edtName->text());
    at->surname.append(dialog->edtSurname->text());
    at->tel.append(dialog->edtTel->text());
    at->address.append(dialog->edtAddr->text());

    qDebug() << "размер массива data" << data.size();
    qDebug() << "размер массива keys" << keys.size();
    if(cur>=0 && cur<data.size())
    {
        cur = find_pos(cur);
        data[cur] = *at;
    }
    else
    {
        struct key *elem = new struct key;
        elem->pos = data.size();
        elem->surname.append(at->surname);
        keys.push_back(*elem);
        data.push_back(*at);
        delete elem;
    }
    qDebug() << "размер массива data" << data.size();
    delete at;
    dialog->hide();
    fill_table();

    return 0;
}

int MainWindow::on_editCurBtn_clicked()
{
    int cur = tableWidget->currentRow();
    qDebug() << "редактируется запись №" << cur;
    if ((data.size()==0) || (cur<0) || (cur>=data.size()))
        return myInfoMsg("Состояние таблицы", "Нечего редактировать!");
    cur = find_pos(cur);
    dialog->show();
    setStr("редактировать", data[keys[cur].pos].name, data[keys[cur].pos].surname,
            data[keys[cur].pos].tel, data[keys[cur].pos].address);
    if (!QString::compare(data[keys[cur].pos].status,
                          QString::fromStdString("личный\n").toUtf8()))
    {
        pr_chb(); // в личный режим
        setVar("", "", QString::number(data[keys[cur].pos].v.value<Ui::privacy>().dd),
               QString::number(data[keys[cur].pos].v.value<Ui::privacy>().mm),
               QString::number(data[keys[cur].pos].v.value<Ui::privacy>().yyyy));
    }
    else
    {
        wr_chb(); // в рабочий режим
        setVar(data[keys[cur].pos].v.value<Ui::work>().position,
               data[keys[cur].pos].v.value<Ui::work>().org, "", "", "");
    }

    return 0;
}

int MainWindow::on_addBtn_clicked()
{
    tableWidget->setCurrentCell(-1,-1);
    qDebug() << "добавляется запись ";
    if (data.size()==0)
        return myInfoMsg("Состояние таблицы", "Не к чему добавлять!");
    dialog->show();
    setStr("Добавить", "", "", "", "");
    setVar("", "", "", "", "");
    pr_chb();

    return 0;
}
// 483
