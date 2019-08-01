#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include "ui_mainwindow.h"
#include "dialog.h"

namespace Ui {
class MainWidget;

struct privacy {
    int dd;
    int mm;
    int yyyy;
};

struct work {
    QString position;
    QString org;
};

}

Q_DECLARE_METATYPE(Ui::privacy)
Q_DECLARE_METATYPE(Ui::work)

class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    int on_fileBtn_clicked();

    void on_sortBtn_clicked();

    void on_condBtn_clicked();

    void on_delCurBtn_clicked();

    void on_delBtn_clicked();

    int ok_but();
    void cancel_but();
    void wr_chb();
    void pr_chb();

    int on_editCurBtn_clicked();

    int on_addBtn_clicked();

    void on_bdCbx_clicked();

    void on_keyBtn_clicked();

    void on_timeBtn_clicked();

private:
    FILE* fin;
    QString fname;
    struct group {
        QString name;
        QString surname;
        QString tel;
        QString address;
        QString status;
        QVariant v;
    };

    struct key
    {
      int pos;
      QString surname;
    };

    QVector<group> data;
    QVector<key> keys;

    Dialog *dialog;

    int read_file(FILE *fin);
    QString getQS(FILE *fin);
    int getInt(FILE *fin);
    void create_table();
    int fill_table();
    void fill_keys();
    int myInfoMsg(QString s1, QString s2);
    void setVar(QString s1,QString s2,QString s3,QString s4,QString s5);
    void setStr(QString s1,QString s2,QString s3,QString s4,QString s5);
    int birthday(int i);
    int raisedialog();
    int find_pos(int pos);
    void findBd(QVector<int> &bd);
    template<class T> void swap(T &a, T &b);
    void table_sort_s();
    void keys_sort_s();
    void table_sort_i();
    void keys_sort_i();


};

#endif // MAINWINDOW_H
