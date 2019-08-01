#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QFileDialog>
#include <QPainter>
#include <cmath>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

typedef struct
{
    int type;
    int len;
} reb;

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    int read_file(FILE* fin);

    void print_graph();

    void ins_reb(int i, int j, int num, int type);

    int dijkstra(int a, int b);
    int dijkstra1(int a, int b);
    int dijkstra2(int a, int b);

    int myInfoMsg(QString s1, QString s2);

    void draw_headers();
    void init_coord();
    void draw_s();

private slots:
    void on_condBtn_clicked();

    void on_createBtn_clicked();

    void on_addBtn_clicked();

    void on_delBtn_clicked();

    void on_shortBtn_clicked();

private:
    Ui::Widget *ui;

    QPixmap *pic;
    QPainter *painter;


    int flag;
    QVector< QVector<reb> > g_sum;
    QVector< QVector<int> > g_auto;
    QVector< QVector<int> > g_train;
    QVector<int> s, s_tt;
    QVector< QPointF > coord;
};

#endif // WIDGET_H
