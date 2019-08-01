#ifndef WIDGET_H
#define WIDGET_H


#define TBL_SIZE (41)

#include "ui_widget.h"

#include <QDebug>
#include <QPainter>
#include <QMessageBox>

typedef struct Root
{
    struct Root *parent;
    struct Root *left;
    struct Root *right;
    QChar key;
    int num;
    int bal;
} Root;

unsigned long long tick(void);

class Widget : public QWidget, private Ui::Widget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);

    // btree
    void free_tree(Root *bufTree);
    void CreationBinaryTree(Root* &BTree);

    void draw_info(int x, int y, QChar key, int num, QPainter *painter);
    void draw_branch(Root *bufRoot, int p, int x, int y, int k, QPainter *painter);
    void draw_tree(Root *BTree, QLabel *imgLbl, QPainter *painter, QPixmap *pic);

    Root* Insert(Root* TreeTop, QChar key);
    Root* Remove(Root *BTree, Root *DelRoot);

    Root* delRep(Root *BTree);
    Root* Minimum(Root *BTree);
    Root* SearchByLetter(Root *BTree, QChar key);

    void inorder(Root* bufTree);
    void preorder(Root* bufTree);

    void btree_part();

    // avltree
    Root* add_tree(Root* node, QChar key);
    void avltree_part();

    // hash
    void fill_table(QVector< QList<char> > hesh, QTableWidget *tbl);
    void add_close(char ch);
    void add_open(char ch);
    void create_h(QVector< QList<char> > &tbl);
    int index(char ch);
    int closed_search(char ch);
    int open_search(char ch);

    double compare_open(double &time);
    double compare_closed(double &time);

    void openhash_part();
    void closehash_part();

private slots:
    void on_condBtn_clicked();

    void on_buildBtn_clicked();

    void on_testBtn_clicked();

    void on_findBtn_clicked();

private:
    QPainter *p1, *p2;
    QPixmap *pic1, *pic2;
    Root *BTree;
    QString order_str;

    Root* balance_tree;
    bool flag, flag1;
    double kol_btree, kol_avl;

    QVector< QList<char> > open_h;
    QVector< QList<char> > close_h;

};

#endif // WIDGET_H
