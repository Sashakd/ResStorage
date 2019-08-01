#include "widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    BTree = NULL;
    balance_tree = NULL;

    pic1 = new QPixmap(QSize(btreeLbl->width(), btreeLbl->height()));
    p1 = new QPainter(pic1);
    p1->setBrush(QBrush(Qt::white));
    pic2 = new QPixmap(QSize(avlLbl->width(), avlLbl->height()));
    p2 = new QPainter(pic2);
    p2->setBrush(QBrush(Qt::white));
}

void Widget::on_buildBtn_clicked()
{
    btree_part();
    avltree_part();
    openhash_part();
    closehash_part();
}

unsigned long long tick(void)
{
    unsigned long long d;

    __asm__ __volatile__ ("rdtsc" : "=A" (d) );

    return d;
}

void Widget::on_testBtn_clicked()
{
    if (!BTree)
    {
        QMessageBox::information(0, "info", "нечего тестировать");
        return;
    }
    double t1, t2, t3, t4;
    double k1, k2, k3, k4;
    unsigned long long t_buf;

    kol_avl = 0;
    t1 = 0;
    for (int i=0; i<order_str.size(); i++)
    {
        t_buf = tick();
        SearchByLetter(BTree, order_str.data()[i]);
        t_buf = tick() - t_buf;
        t1 += t_buf;
    }
    t1 /= order_str.size();
    k1 = kol_avl/order_str.size();

    kol_avl = 0;
    t2 = 0;
    for (int i=0; i<order_str.size(); i++)
    {
        t_buf = tick();
        SearchByLetter(balance_tree, order_str.data()[i]);
        t_buf = tick() - t_buf;
        t2 += t_buf;
    }
    t2 /= order_str.size();
    k2 = kol_avl/order_str.size();

    k3 = compare_open(t3);
    k4 = compare_closed(t4);
    QMessageBox::information(this, "tests (время в тактах)",
                             "среднее\nкол-во сравнений в дереве двоичного поиска = " +
                             QString::number(k1) +
                             "\nкол-во сравнений в авл-дереве = " +
                             QString::number(k2) +
                             "\nкол-во сравнений в открытой хеш-таблице = " +
                             QString::number(k3) +
                             "\nкол-во сравнений в закрытой хеш-таблице = " +
                             QString::number(k4) +
                             "\n\nвремя сравнений в дереве двоичного поиска = " +
                             QString::number(t1) +
                             "\nвремя сравнений в авл-дереве = " +
                             QString::number(t2) +
                             "\nвремя сравнений в открытой хеш-таблице = " +
                             QString::number(t3) +
                             "\nвремя сравнений в закрытой хеш-таблице = " +
                             QString::number(t4));
}

void Widget::on_findBtn_clicked()
{
    if ((!BTree) || (chEdt->text().size()==0))
        return;
    int flag2 = 0;

    kol_avl = 0;
    if (SearchByLetter(BTree, chEdt->text().data()[0]))
        flag2 = 1;

    kol_btree = kol_avl;
    kol_avl = 0;
    SearchByLetter(balance_tree, chEdt->text().data()[0]);

    double kol_open = open_search(chEdt->text().toStdString().data()[0]);
    double kol_close = closed_search(chEdt->text().toStdString().data()[0]);

    if (flag2==1)
        QMessageBox::information(this, "символ найден",
                                 "среднее\nкол-во сравнений в дереве двоичного поиска = " +
                                 QString::number(kol_btree) +
                                 "\nкол-во сравнений в авл-дереве = " +
                                 QString::number(kol_avl) +
                                 "\nкол-во сравнений в открытой хеш-таблице = " +
                                 QString::number(kol_open) +
                                 "\nкол-во сравнений в закрытой хеш-таблице = " +
                                 QString::number(kol_close));
    else
        QMessageBox::information(this, "символ не найден",
                                 "\nкол-во сравнений в дереве двоичного поиска = " +
                                 QString::number(kol_btree) +
                                 "\nкол-во сравнений в авл-дереве = " +
                                 QString::number(kol_avl) +
                                 "\nкол-во сравнений в открытой хеш-таблице = " +
                                 QString::number(kol_open) +
                                 "\nкол-во сравнений в закрытой хеш-таблице = " +
                                 QString::number(kol_close));
}
