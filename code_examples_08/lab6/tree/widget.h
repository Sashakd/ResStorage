#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMessageBox>
#include "ui_widget.h"

namespace Ui {
class Widget;
}

typedef struct Root
{
    struct Root *parent;
    struct Root *left;
    struct Root *right;
    QChar key;
    int num;
} Root;

class Widget : public QWidget, Ui::Widget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void WalkSetFalse(Root *BTree);
    Root* SearchByLetter(Root *BTree, QChar key);
    Root* Minimum(Root *BTree);
    Root* Remove(Root *BTree, Root *DelRoot);
    Root* Insert(Root* TreeTop, QChar key);
    void inorder(Root* bufTree);
    void preorder(Root* bufTree);
    void CreationBinaryTree(Root* &BTree);
    void draw_tree();
    void draw_branch(Root *bufRoot, int p, int x, int y, int k);
    void free_tree(Root *bufTree);
    Root* delRep(Root *BTree);
    void draw_info(int x, int y, QChar key, int num);
    void sort_i(QString &str, int cnt);

private slots:
    void on_buildBtn_clicked();

    void on_addBtn_clicked();

    void on_delBtn_clicked();

    void on_delRepBtn_clicked();

    void on_timeBtn_clicked();

private:
    Root *BTree;
    QPixmap *pic;
    QPainter *painter;
    QString order_str;
};

#endif // WIDGET_H
