#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "ui_dialog.h"
#include <QDate>
#include <QDebug>

#define N 200

int MainWindow::birthday(int i)
{
    QString str = QString::fromStdString("личный\n").toUtf8();
    if (QString::compare(data[keys[i].pos].status, str))
        return 0;
    int d = data[keys[i].pos].v.value<Ui::privacy>().dd;
    int m = data[keys[i].pos].v.value<Ui::privacy>().mm;

    QDate d1 = QDate::currentDate();
    QDate d2(d1.year(), m, d);
    if ((d1.daysTo(d2)<8) && (d1.daysTo(d2)>=0))
        return 1;
    qDebug() << "запись" << i << "не подходит";
    return 0;
}

// сортировка таблицы
void MainWindow::on_sortBtn_clicked()
{
    table_sort_s();
    fill_table();
}

void MainWindow::on_keyBtn_clicked()
{
    keys_sort_s();
    fill_table();
}

void MainWindow::on_bdCbx_clicked()
{
    fill_table();
}

void MainWindow::keys_sort_i()
{
    int i, j;
    for(i = 1; i < keys.size(); i++)
        for(j = i; j > 0 && keys[j - 1].surname > keys[j].surname; j--)
            swap(keys[j - 1], keys[j]);
}

void MainWindow::table_sort_i()
{
    int i, j;
    for (i = 1; i < data.size(); i++)
        for (j = i; j > 0 && data[j - 1].surname > data[j].surname; j--)
            swap(data[j - 1], data[j]);
}

void MainWindow::keys_sort_s()
{
    int i, j, k;
    for(i = 0; i < keys.size(); i++)
    {
        k = i;
        for(j = i + 1; j < keys.size(); j++)
            if (keys[j].surname < keys[k].surname)
                k = j;
        swap(keys[i], keys[k]);
    }
}

void MainWindow::table_sort_s()
{
    int i, j, k;
    for(i = 0; i < data.size(); i++)
    {
        k = i;
        for(j = i + 1; j < data.size(); j++)
            if (data[j].surname < data[k].surname)
                k = j;
        swap(data[i], data[k]);
    }
}

template<class T>
void MainWindow::swap(T &a, T &b)
{
  T c;
  c = a;
  a = b;
  b = c;
}

unsigned long long tick(void)
{
    unsigned long long d;

    __asm__ __volatile__ ("rdtsc" : "=A" (d) );

    return d;
}

void MainWindow::on_timeBtn_clicked()
{
    unsigned long long tb, te;
    double res_k1=0, res_t1=0, res_t2=0, res_k2=0;

    if (fname.isEmpty())
        return;
    for (int i=0; i<N; i++)
    {
        fill_keys();
        tb = tick();
        keys_sort_i();
        te = tick();
        res_k2 += te - tb;
    }
    res_k2 /= N;

    for (int i=0; i<N; i++)
    {
        fill_keys();
        tb = tick();
        keys_sort_s();
        te = tick();
        res_k1 += te - tb;
    }
    res_k1 /= N;

    for (int i=0; i<N; i++)
    {
        if (data.size()!=0)
            data.remove(0, data.size());
        fin = fopen(fname.toStdString().data(), "r");
        read_file(fin);
        tb = tick();
        table_sort_i();
        te = tick();
        res_t2 += te - tb;
        fclose(fin);
    }
    res_t2 /= N;

    for (int i=0; i<N; i++)
    {
        if (data.size()!=0)
            data.remove(0, data.size());
        fin = fopen(fname.toStdString().data(), "r");
        read_file(fin);
        tb = tick();
        table_sort_s();
        te = tick();
        res_t1 += te - tb;
        fclose(fin);
    }
    res_t1 /= N;

    QString results;
    results.append("Время сортировки: ");
    results.append("\n");
    results.append("    Выбором:\n\t time(keys)/time(table) = ");
    results.append(QString::number(res_k1/res_t1));
    results.append("\n\tКлючи: ");
    results.append(QString::number(res_k1));
    results.append("\n\tТаблица: ");
    results.append(QString::number(res_t1));
    results.append("\n");
    results.append("    Вставками:\n\t time(keys)/time(table) = ");
    results.append(QString::number(res_k2/res_t2));
    results.append("\n\tКлючи: ");
    results.append(QString::number(res_k2));
    results.append("\n\tТаблица: ");
    results.append(QString::number(res_t2));
    results.append("\n");

    results.append("Память:");
    results.append("\n");
    results.append("    Таблица: ");
    results.append(QString::number(data.size()*sizeof(data[0])));
    results.append("\n");
    results.append("    Ключи: ");
    results.append(QString::number(keys.size()*sizeof(keys[0])));
    results.append("\n");
    results.append("    Отношение: c ключами/без ключей = ");
    results.append(
      QString::number((double)(keys.size()*sizeof(keys[0]) + data.size()*sizeof(data[0]))/\
                (data.size()*sizeof(data[0]))));
    results.append("\n");
    QMessageBox::information(this, "результаты", results, QMessageBox::Ok);
}
