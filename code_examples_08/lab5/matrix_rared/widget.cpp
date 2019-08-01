#include "widget.h"
#include "ui_widget.h"
#include <ctime>

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    srand(time(NULL));
    flag = 0;

    pic1 = new QPixmap(QSize(imgLbl1->width(), imgLbl1->height()));
    pic2 = new QPixmap(QSize(imgLbl2->width(), imgLbl2->height()));
    pic3 = new QPixmap(QSize(imgLbl3->width(), imgLbl3->height()));
    p1 = new QPainter(pic1);
    p1->setPen(QPen(Qt::white, 1));
    p1->setBrush(QBrush(Qt::white));
    p1->drawRect(-1, -1, imgLbl1->width(), imgLbl1->height());
    p2 = new QPainter(pic2);
    p2->setPen(QPen(Qt::white, 1));
    p2->setBrush(QBrush(Qt::white));
    p2->drawRect(-1, -1, imgLbl2->width(), imgLbl2->height());
    p3 = new QPainter(pic3);
    p3->setPen(QPen(Qt::white, 1));
    p3->setBrush(QBrush(Qt::white));
    p3->drawRect(-1, -1, imgLbl3->width(), imgLbl3->height());
    imgLbl1->setPixmap(*pic1);
    imgLbl2->setPixmap(*pic2);
    imgLbl3->setPixmap(*pic3);

    rowEdt->setValidator(new QIntValidator(this));
    colEdt->setValidator(new QIntValidator(this));
    valEdt->setValidator(new QDoubleValidator(this));
    RAEdt->setValidator(new QIntValidator(this));
    RBEdt->setValidator(new QIntValidator(this));
    CAEdt->setValidator(new QIntValidator(this));
    CBEdt->setValidator(new QIntValidator(this));
    PAEdt->setValidator(new QDoubleValidator(this));
    PBEdt->setValidator(new QDoubleValidator(this));
}

Widget::~Widget() {}

//_________________________________________________________//
// обычные матрицы                                         //

double Widget::spec_sum(double **pb1, double **pb2, int ni, int nj, int b)
{
    double sum1=0;

    for (int i = 0; i < b; i++)
        sum1 += pb1[ni][i]*pb2[i][nj];

    return sum1;
}

int Widget::mul_matr(double **pb1, int a1, int b1, double **pb2, int a2, int b2,
             double **pb_buf)
{
    if (a2!=b1)
        return -1;

    for (int i = 0; i<a1; i++)
        for (int j = 0; j<b2; j++)
            pb_buf[i][j] = spec_sum(pb1, pb2, i, j, b1);

    return 0;
}

void Widget::init_norm_matrix(double **pb, int a, int b, double part)
{
    for (int i=0; i<a; i++)
        for (int j=0; j<b; j++)
            if (random(0, 1) < part/100 + 1E-6)
                pb[i][j] = random(1, 100);
            else
                pb[i][j] = 0;
}

double** Widget::allocate_matrix_solid(int n, int m)
{
    double **data = (double**)malloc(n * sizeof(double*) +
                              n * m * sizeof(double));
    if (!data)
        return NULL;

    for (int i = 0; i < n; i++)
        data[i] = (double*)((char*) data +
                          n * sizeof(double*) +
                                  i * m * sizeof(double));
    return data;
}

//________________________________________________________//

t_m_rare Widget::create_rared(int a, int b, double part)
{
    t_m_rare matrix;

    int count=0, cur; // число сгенерировнных ненулевых элементов
    double num;

    matrix.a = a;
    matrix.b = b;

    for (int i=0; i<a; i++)
    {
        cur = count;
        for (int j=0; j<b; j++)
            if (random(0, 1) < part/100 + 1E-6)
            {
                num = random(1, 100);
                matrix.A.push_back(num);
                matrix.JA.push_back(j);
                if (matrix.IA.size() == i+1)
                    matrix.IA.push_back(count);
                count++;
            }
        if (matrix.IA.size() == i)
            matrix.IA.push_back(cur);
    }
    matrix.IA.push_back(count);

    return matrix;
}

void Widget::description_m(t_m_rare m)
{
    qDebug() << "AxB - " << m.a << "x" << m.b;
    qDebug() << "\nA";
    qDebug() << m.A;
    qDebug() << "\nJA";
    qDebug() << m.JA;
    qDebug() << "\nIA";
    qDebug() << m.IA;
    qDebug() << "\nненулевых элементов в матрице" << m.A.size();
}

void Widget::transp_rared(t_m_rare m, t_m_rare &mt)
{
    QVector< QList<int> > i_v(m.b);
    QVector< QList<double> > d_v(m.b);

    for (int i=0; i<m.IA.size()-1; i++)
        for (int j=m.IA[i]; j<m.IA[i+1]; j++)
        {
            i_v[m.JA[j]].append(i);
            d_v[m.JA[j]].append(m.A[j]);
        }

    mt.A.clear();
    mt.IA.clear();
    mt.JA.clear();
    mt.a = m.b;
    mt.b = m.a;
    int s = 0;
    for (int i=0; i<i_v.size(); i++)
    {
        mt.IA.append(s);
        for (int j=0; j<i_v[i].size(); j++)
        {
            mt.A.append(d_v[i][j]);
            mt.JA.append(i_v[i][j]);
        }
        s += i_v[i].size();
    }
    mt.IA.append(s);
}

void Widget::mul_rared(t_m_rare m1, t_m_rare m2, t_m_rare &m3)
{
    if (m1.b != m2.a)
        return;

    t_m_rare mt;
    int rowNZ;

    m3.a = m1.a;
    m3.b = m2.b;

    transp_rared(m2, mt);

    m3.IA.push_back(0);
    for (int i=0; i<m1.IA.size()-1; i++)
    {
        rowNZ = 0;
        for (int j=0; j<mt.IA.size()-1; j++)
        {
            double sum1=0;

            for (int k = m1.IA[i]; k < m1.IA[i+1]; k++)
            {
                for (int l = mt.IA[j]; l < mt.IA[j+1]; l++)
                {
                    if (m1.JA[k]!=mt.JA[l])
                        continue;
                    sum1 += m1.A[k]*mt.A[l];
                    break;

                }
            }
            if (sum1 > 1E-4)
            {
                m3.A.push_back(sum1);
                m3.JA.push_back(j);
                rowNZ++;
            }
        }
        m3.IA.push_back(rowNZ + m3.IA[i]);
    }
}

void Widget::norm_matrix_to_rared(double **pb, int a, int b, t_m_rare &m)
{
    int count=0, cur; // число сгенерировнных ненулевых элементов

    m.A.clear();
    m.IA.clear();
    m.JA.clear();
    m.a = a;
    m.b = b;
    for (int i=0; i<a; i++)
    {
        cur = count;
        for (int j=0; j<b; j++)
            if (pb[i][j] > 1E-4)
            {
                m.A.push_back(pb[i][j]);
                m.JA.push_back(j);
                if (m.IA.size() == i+1)
                    m.IA.push_back(count);
                count++;
            }
        if (m.IA.size() == i)
            m.IA.push_back(cur);
    }
    m.IA.push_back(count);
}

void Widget::insert_rared(double num, int row, int col, t_m_rare &m)
{
    int j;

    if (m.IA[row] == m.IA[row+1])
    {
        m.JA.insert(m.IA[row], col);
        m.A.insert(m.IA[row], num);

        for (j=row+1; j<m.IA.size(); j++)
            m.IA[j]++;

        return;
    }

    for (j = m.IA[row]; j < m.IA[row+1]; j++)
    {
        if (m.JA[j] == col)
        {
            m.A.replace(j, num);
            return;
        }

        if (m.JA[j] > col)
            break;
    }

    m.JA.insert(j, col);
    m.A.insert(j, num);

    for (j=row+1; j<m.IA.size(); j++)
        m.IA[j]++;

}

void Widget::remove_rared(int row, int col, t_m_rare &m)
{
    for (int j = m.IA[row]; j < m.IA[row+1]; j++)
        if (m.JA[j] == col)
        {
            m.JA.remove(j, 1);
            m.A.remove(j, 1);
            for (j=row+1; j<m.IA.size(); j++)
                m.IA[j]--;
            break;
        }
}

void Widget::free_matrix_rared(t_m_rare &m)
{
    m.A.clear();
    m.JA.clear();
    m.a = m.b = 0;
    m.IA.clear();
}

void Widget::print_rared(t_m_rare m, QPainter *p, QPixmap *pm, QLabel *lbl)
{
    p->setPen(QPen(Qt::white, 4));
    p->setBrush(QBrush(Qt::white));
    p->drawRect(0, 0, lbl->width(), lbl->height());
    lbl->setPixmap(*pm);
    if ((m.b == 0) || (m.a == 0) || (m.a > 100) || (m.b >100))
    {
        qDebug() << "\nвизуализация" << lbl->objectName() << "не реализована\n";
        return;
    }

    double h = 100/m.a, w = 100/m.b;

    p->setPen(QPen(Qt::white, 4));
    p->setBrush(QBrush(Qt::white));
    p->drawRect(0, 0, lbl->width(), lbl->height());
    p->setPen(QPen(Qt::red, 1));

    p->save();
    p->scale(w, h);

    for (int i=0; i < m.IA.size()-1; i++)
        for (int j=m.IA[i]; j < m.IA[i+1]; j++)
             p->drawPoint(QPointF(m.JA[j]+0.5, i+0.5));

    lbl->setPixmap(*pm);
    p->restore();
}

void Widget::on_testBtn_clicked()
{
    test_mul_matrix();
}

void Widget::on_mulBtn_clicked()
{
    free_matrix_rared(m3);
    if (flag == 0)
    {
        QMessageBox::information(this, "Error", "нечего умножать", QMessageBox::Ok);
        return;
    }
    mul_rared(m1, m2, m3);
    qDebug() << "C = AxB";
    description_m(m3);
    print_rared(m3, p3, pic3, imgLbl3);
}

void Widget::on_insBtn_clicked()
{
    if (rowEdt->text().isEmpty() || colEdt->text().isEmpty() || valEdt->text().isEmpty())
    {
        QMessageBox::information(this, "Error", "заполните все поля", QMessageBox::Ok);
        return;
    }
    if (flag == 0)
    {
        QMessageBox::information(this, "Error", "не к чему добавлять", QMessageBox::Ok);
        return;
    }
    t_m_rare *m = &m2;
    if (cmb->currentIndex() == 0)
        m = &m1;

    double num = valEdt->text().replace(",",".").toDouble();
    int row = rowEdt->text().toInt(), col = colEdt->text().toInt();

    if ((row >= 0) && (row < m->a) && (col >= 0) && (col < m->b) && (fabs(num) > 1E-4))
        insert_rared(num, row, col, *m);
    else
        QMessageBox::information(this, "Error", "некорректно заданы параметры", QMessageBox::Ok);

    qDebug() << "\nm1";
    description_m(m1);
    print_rared(m1, p1, pic1, imgLbl1);
    qDebug() << "\nm2";
    description_m(m2);
    print_rared(m2, p2, pic2, imgLbl2);
}

void Widget::on_delBtn_clicked()
{
    if (rowEdt->text().isEmpty() || colEdt->text().isEmpty())
    {
        QMessageBox::information(this, "Error", "заполните все поля", QMessageBox::Ok);
        return;
    }
    if (flag == 0)
    {
        QMessageBox::information(this, "Error", "нечего удалять", QMessageBox::Ok);
        return;
    }
    t_m_rare *m = &m2;
    if (cmb->currentIndex() == 0)
        m = &m1;

    int row = rowEdt->text().toInt(), col = colEdt->text().toInt();

    if ((row >= 0) && (row < m->a) && (col >= 0) && (col < m->b))
        remove_rared(row, col, *m);
    else
        QMessageBox::information(this, "Error", "некорректное положение для вставки/удаления", QMessageBox::Ok);

    qDebug() << "\nm1";
    description_m(m1);
    print_rared(m1, p1, pic1, imgLbl1);
    qDebug() << "\nm2";
    description_m(m2);
    print_rared(m2, p2, pic2, imgLbl2);
    print_rared(m3, p3, pic3, imgLbl3);
}

void Widget::on_createBtn_clicked()
{
    if (PAEdt->text().isEmpty() || RAEdt->text().isEmpty() || CAEdt->text().isEmpty()
            || PBEdt->text().isEmpty() || RBEdt->text().isEmpty() || CBEdt->text().isEmpty())
    {
        QMessageBox::information(this, "Error", "заполните все поля", QMessageBox::Ok);
        return;
    }

    double perA = PAEdt->text().replace(",",".").toDouble();
    double perB = PBEdt->text().replace(",",".").toDouble();
    int rowA = RAEdt->text().toInt(), colA = CAEdt->text().toInt();
    int rowB = RBEdt->text().toInt(), colB = CBEdt->text().toInt();

    free_matrix_rared(m1);
    free_matrix_rared(m2);
    free_matrix_rared(m3);

    if ((rowA >= 0) && (colA >= 0) && (rowB >= 0) && (colB >= 0) && (perA >= 0) && (perB >= 0)
            && (colA == rowB))
    {
        m1 = create_rared(rowA, colA, perA);
        m2 = create_rared(rowB, colB, perB);
    }
    else
    {
        QMessageBox::information(this, "Error", "некорректные размеры матриц", QMessageBox::Ok);
        return;
    }

    flag = 1;

    qDebug() << "\nm1";
    description_m(m1);
    print_rared(m1, p1, pic1, imgLbl1);
    qDebug() << "\nm2";
    description_m(m2);
    print_rared(m2, p2, pic2, imgLbl2);
    print_rared(m3, p3, pic3, imgLbl3);
}
