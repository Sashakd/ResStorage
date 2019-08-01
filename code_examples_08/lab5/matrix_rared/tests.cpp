#include "widget.h"
#include <cstdlib>

double Widget::random(double from, double to)
{
    return from+((double)rand()/(double)RAND_MAX)*(to-from);
}

unsigned long long tick(void)
{
    unsigned long long d;

    __asm__ __volatile__ ("rdtsc" : "=A" (d) );

    return d;
}

void Widget::on_condBtn_clicked() // условие задачи
{
    QMessageBox::information(this, "условие",
        "Разреженная матрица хранится в форме трех объектов.\n"\
        " - Вектор A содержит значения ненулевых элементов.\n"\
        " - Вектор JA содержит номера столбцов для элементов вектора A\n"\
        " - Связный список IA, в элементе Nk которого которого\n"\
        "\tнаходится номер компонент в A и JA, с которых\n"\
        "\tначинается описание строки Nk матрицы A.\n"\
        "Провести умножение матриц в форме разреженных матриц, "\
        "сравнить производительность.", QMessageBox::Ok);
}

void Widget::test_mul_matrix()
{
    int a1=1000, b1=100, a2=100, b2=1;
    double **pb1 = allocate_matrix_solid(a1, b1);
    double **pb2 = allocate_matrix_solid(a2, b2);

    unsigned long long btick = tick();
    double **pb_buf = allocate_matrix_solid(a1, b2);
    btick = tick() - btick;

    t_m_rare m1, m2, m_buf;

    unsigned long long tb;
    double t1_100, t2_100, t1_10, t2_10, t1_05, t2_05, t1_5, t2_5;
    double m1_100, m2_100, m2_10, m2_05, m2_5;

    // test 100%
    init_norm_matrix(pb1, a1, b1, a1*b2);
    init_norm_matrix(pb2, a2, b2, a1*b2);

    tb = tick();
    mul_matr(pb1, a1, b1, pb2, a2, b2, pb_buf);
    t1_100 = tick() - tb + btick;

    norm_matrix_to_rared(pb1, a1, b1, m1);
    norm_matrix_to_rared(pb2, a2, b2, m2);

    qDebug() << "\n-----------------------------------\nm1";
    description_m(m1);
    qDebug() << "\nm2";
    description_m(m2);

    tb = tick();
    mul_rared(m1, m2, m_buf);
    t2_100 = tick() - tb;

    qDebug() << "\nm_buf";
    description_m(m_buf);

    m2_100 =
        (m1.A.size() + m2.A.size() + m_buf.A.size()) * sizeof(double) +
        ((m1.JA.size() + m1.IA.size()) + (m2.JA.size() + m2.IA.size()) +
         (m1.JA.size() + m1.IA.size())) * sizeof(int);

    free_matrix_rared(m1);
    free_matrix_rared(m2);
    free_matrix_rared(m_buf);

    // test 10%
    init_norm_matrix(pb1, a1, b1, 10);
    init_norm_matrix(pb2, a2, b2, 10);

    tb = tick();
    mul_matr(pb1, a1, b1, pb2, a2, b2, pb_buf);
    t1_10 = tick() - tb + btick;

    norm_matrix_to_rared(pb1, a1, b1, m1);
    norm_matrix_to_rared(pb2, a2, b2, m2);

    qDebug() << "\n-----------------------------------\nm1";
    description_m(m1);
    qDebug() << "\nm2";
    description_m(m2);

    tb = tick();
    mul_rared(m1, m2, m_buf);
    t2_10 = tick() - tb;

    qDebug() << "\nm_buf";
    description_m(m_buf);

    m2_10 =
        (m1.A.size() + m2.A.size() + m_buf.A.size()) * sizeof(double) +
        ((m1.JA.size() + m1.IA.size()) + (m2.JA.size() + m2.IA.size()) +
         (m1.JA.size() + m1.IA.size())) * sizeof(int);

    free_matrix_rared(m1);
    free_matrix_rared(m2);
    free_matrix_rared(m_buf);

    // test 5%
    init_norm_matrix(pb1, a1, b1, 1.3);
    init_norm_matrix(pb2, a2, b2, 1.3);

    tb = tick();
    mul_matr(pb1, a1, b1, pb2, a2, b2, pb_buf);
    t1_5 = tick() - tb + btick;

    norm_matrix_to_rared(pb1, a1, b1, m1);
    norm_matrix_to_rared(pb2, a2, b2, m2);

    qDebug() << "\n-----------------------------------\nm1";
    description_m(m1);
    qDebug() << "\nm2";
    description_m(m2);

    tb = tick();
    mul_rared(m1, m2, m_buf);
    t2_5 = tick() - tb;

    qDebug() << "\nm_buf";
    description_m(m_buf);

    m2_5 =
        (m1.A.size() + m2.A.size() + m_buf.A.size()) * sizeof(double) +
        ((m1.JA.size() + m1.IA.size()) + (m2.JA.size() + m2.IA.size()) +
         (m1.JA.size() + m1.IA.size())) * sizeof(int);

    free_matrix_rared(m1);
    free_matrix_rared(m2);
    free_matrix_rared(m_buf);

    // test 0.5%
    init_norm_matrix(pb1, a1, b1, 0.5);
    init_norm_matrix(pb2, a2, b2, 0.5);

    tb = tick();
    mul_matr(pb1, a1, b1, pb2, a2, b2, pb_buf);
    t1_05 = tick() - tb + btick;

    norm_matrix_to_rared(pb1, a1, b1, m1);
    norm_matrix_to_rared(pb2, a2, b2, m2);

    qDebug() << "\n-----------------------------------\nm1";
    description_m(m1);
    qDebug() << "\nm2";
    description_m(m2);

    tb = tick();
    mul_rared(m1, m2, m_buf);
    t2_05 = tick() - tb;

    qDebug() << "\nm_buf";
    description_m(m_buf);

    m2_05 =
        (m1.A.size() + m2.A.size() + m_buf.A.size()) * sizeof(double) +
        ((m1.JA.size() + m1.IA.size()) + (m2.JA.size() + m2.IA.size()) +
         (m1.JA.size() + m1.IA.size())) * sizeof(int);

    free_matrix_rared(m1);
    free_matrix_rared(m2);
    free_matrix_rared(m_buf);

    free(pb1);
    free(pb2);
    free(pb_buf);

    m1_100 = (a1*b1 + a2*b2 + a1*b2) * sizeof(int);

    print_test_results(t1_100, t2_100, t1_10, t2_10, t1_05, t2_05, t1_5, t2_5,
                       m1_100, m2_100, m2_10, m2_05, m2_5);

    flag = 0;
}

void Widget::print_test_results(double t1_100, double t2_100, double t1_10, double t2_10,
                        double t1_05, double t2_05, double t1_5, double t2_5,
                                double m1_100, double m2_100, double m2_10, double m2_05,
                                double m2_5)
{
    QMessageBox::information(this, "Результаты тестов: время",
        "Время матриц на умножение с разным процентом ненулевых элементов:\n "\
        "Обычной,       100%\t" + QString::number(t1_100) + " тактов.\n"\
        "Разреженной, 100%\t" + QString::number(t2_100) + " тактов.\n"\
        "Разница:\t\t"+QString::number((t1_100-t2_100)/t2_100*100) + " %.\n\n"\
        "Обычной,        10%\t" + QString::number(t1_10) + " тактов.\n"\
        "Разреженной, 10%\t" + QString::number(t2_10) + " тактов.\n"\
        "Разница:\t\t"+QString::number((t1_10-t2_10)/t2_10*100) + " %.\n\n"\
         "Обычной,        1.3%\t" + QString::number(t1_5) + " тактов.\n"\
         "Разреженной, 1.3%\t" + QString::number(t2_5) + " тактов.\n"\
         "Разница:\t\t"+QString::number((t1_5-t2_5)/t2_5*100) + " %.\n\n"\
        "Обычной,        0.5%\t" + QString::number(t1_05) + " тактов.\n"\
        "Разреженной, 0.5%\t" + QString::number(t2_05) + " тактов.\n"\
        "Разница:\t\t"+QString::number((t1_05-t2_05)/t2_05*100) + " %.\n\n",
                             QMessageBox::Ok);

    QMessageBox::information(this, "Результаты тестов: память",
        "Память на хранение матриц с разным процентом ненулевых элементов:\n "\
        "Обычной,       100%\t" + QString::number(m1_100) + " байт.\n"\
        "Разреженной, 100%\t" + QString::number(m2_100) + " байт.\n"\
        "Разница:\t\t"+QString::number((m1_100-m2_100)/m2_100*100) + " %.\n\n"\
        "Обычной,        10%\t" + QString::number(m1_100) + " байт.\n"\
        "Разреженной, 10%\t" + QString::number(m2_10) + " байт.\n"\
        "Разница:\t\t"+QString::number((m1_100-m2_10)/m2_10*100) + " %.\n\n"\
         "Обычной,        1.3%\t" + QString::number(m1_100) + " байт.\n"\
         "Разреженной, 1.3%\t" + QString::number(m2_5) + " байт.\n"\
         "Разница:\t\t"+QString::number((m1_100-m2_5)/m2_5*100) + " %.\n\n"\
        "Обычной,        0.5%\t" + QString::number(m1_100) + " байт.\n"\
        "Разреженной, 0.5%\t" + QString::number(m2_05) + " байт.\n"\
        "Разница:\t\t"+QString::number((m1_100-m2_05)/m2_05*100) + " %.\n\n",
                             QMessageBox::Ok);
}
