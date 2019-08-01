#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QPainter>
#include "ui_widget.h"
#include <QDebug>
#include <cmath>

namespace Ui {
class Widget;
}

typedef struct
{
    int a, b;
    QVector<double> A;
    QVector<int> JA;
    QList<int> IA;
} t_m_rare;

class Widget : public QWidget, public Ui::Widget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    t_m_rare create_rared(int a, int b, double part);
    void transp_rared(t_m_rare m1, t_m_rare &mt);
    void mul_rared(t_m_rare m1, t_m_rare m2, t_m_rare &m3);

    void norm_matrix_to_rared(double **pb, int a, int b, t_m_rare &m);
    void insert_rared(double num, int row, int col, t_m_rare &m);
    void remove_rared(int row, int col, t_m_rare &m);
    void free_matrix_rared(t_m_rare &m);

    void print_rared(t_m_rare m, QPainter *p, QPixmap *pm, QLabel *lbl);
    void description_m(t_m_rare m);

    double** allocate_matrix_solid(int n, int m);
    void init_norm_matrix(double **pb, int a, int b, double part);
    int mul_matr(double **pb1, int a1, int b1, double **pb2, int a2, int b2,
              double **pb_buf);
    double spec_sum(double **pb1, double **pb2, int ni, int nj, int b);

    void print_test_results(double t1_100, double t2_100, double t1_10, double t2_10,
                            double t1_05, double t2_05, double t1_5, double t2_5,
                            double m1_100, double m2_100, double m2_10, double m2_05, double m2_5);
    void test_mul_matrix();
    double random(double from, double to);

private slots:
    void on_condBtn_clicked();

    void on_testBtn_clicked();

    void on_mulBtn_clicked();

    void on_insBtn_clicked();

    void on_delBtn_clicked();

    void on_createBtn_clicked();

private:
    QPixmap *pic1, *pic2, *pic3;
    QPainter *p1, *p2, *p3;
    t_m_rare m1, m2, m3;
    int flag;
};

#endif // WIDGET_H
