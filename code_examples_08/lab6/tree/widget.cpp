#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    BTree = NULL;

    pic = new QPixmap(QSize(imgLbl->width(), imgLbl->height()));
    painter = new QPainter(pic);
    painter->setPen(QPen(Qt::white, 4));
    painter->setBrush(QBrush(Qt::white));
    painter->drawRect(-1, -1, imgLbl->width(), imgLbl->height());
    imgLbl->setPixmap(*pic);
}

Widget::~Widget() {}

Root* Widget::SearchByLetter(Root *BTree, QChar key)
{
    Root *bufRoot = BTree;
    Root *bufRoot2;
    if (bufRoot)
    {
        if ((bufRoot2 = SearchByLetter(bufRoot->left, key)) != NULL)
            return bufRoot2;
        if ((bufRoot2 = SearchByLetter(bufRoot->right, key)) != NULL)
            return bufRoot2;
        if (bufRoot->key == key)
            return bufRoot;
    }
    return NULL;
}

Root* Widget::Minimum(Root *BTree)
{
    Root *bufRoot = BTree;
    while (bufRoot->left)
        bufRoot = bufRoot->left;
    return bufRoot;
}

Root* Widget::Remove(Root *BTree, Root *DelRoot) // ok
{
    Root *bufRoot = DelRoot;

    if (!DelRoot->left && !DelRoot->right)
    {
        if (!DelRoot->parent)
        {
            free(DelRoot);
            return NULL;
        }
        if ((DelRoot->parent->left)==DelRoot)
            DelRoot->parent->left = NULL;
        else
            DelRoot->parent->right = NULL;
        free(DelRoot);
    }
    else if ((!DelRoot->left && DelRoot->right) || (DelRoot->left && !DelRoot->right))
    {
        bufRoot = DelRoot->right ? DelRoot->right : DelRoot->left;
        if (!DelRoot->parent)
        {
            bufRoot->parent = NULL;
            free(DelRoot);
            return bufRoot;
        }
        bufRoot->parent = DelRoot->parent;
        if (DelRoot->parent->left==DelRoot)
            bufRoot->parent->left = bufRoot;
        else
            bufRoot->parent->right = bufRoot;
        free(DelRoot);
    }
    else
    {
        bufRoot = Minimum(DelRoot->right);
        DelRoot->key = bufRoot->key;
        DelRoot->num = bufRoot->num;
        BTree = Remove(BTree, bufRoot);
    }
    return BTree;
}

Root* Widget::Insert(Root* TreeTop, QChar key) // ok
{
    Root *newRoot = (Root*)malloc(sizeof(Root));
    Root *bufRoot = TreeTop;
    newRoot->key = key;
    newRoot->num = 0;
    if (TreeTop)
    {
        while (bufRoot->left || bufRoot->right)
        {
            if (key == bufRoot->key)
                bufRoot->num = newRoot->num = 1;
            if (bufRoot->left && (key < bufRoot->key))
                bufRoot = bufRoot->left;
            else if (bufRoot->right && (key >= bufRoot->key))
                bufRoot = bufRoot->right;
            else
                break;
        }
        if (key == bufRoot->key)
            bufRoot->num = newRoot->num = 1;
    }
    else
        TreeTop = newRoot;
    newRoot->left = newRoot->right = NULL;
    newRoot->parent = bufRoot;
    if (bufRoot)
    {
        if (key < bufRoot->key)
            bufRoot->left = newRoot;
        else
            bufRoot->right = newRoot;
    }
    return TreeTop;
}

void Widget::CreationBinaryTree(Root* &BTree)
{
    int cnt = strEdt->text().length();
    BTree = NULL;
    for (int i=0; i<cnt; i++)
        BTree = Insert(BTree, strEdt->text().data()[i]);
}

void Widget::draw_tree()
{
    int k = 80;
    painter->setPen(QPen(Qt::white, 4));
    painter->drawRect(-1, -1, imgLbl->width(), imgLbl->height());
    if (BTree)
    {
        int x = imgLbl->width()/2, y = 18;
        draw_branch(BTree->left, 0, x-k, y+40, k);
        draw_branch(BTree->right, 1, x+k, y+40, k);
        draw_info(x, y, BTree->key, BTree->num);
    }
    imgLbl->setPixmap(*pic);
}

void Widget::draw_branch(Root *bufRoot, int p, int x, int y, int k)
{
    double sokr = 1.4;
    if (bufRoot)
    {
        painter->setPen(QPen(Qt::gray, 3));
        if (p)
            painter->drawLine(x, y, x-k, y-40);
        else
            painter->drawLine(x, y, x+k, y-40);
        draw_branch(bufRoot->left, 0, x-k/sokr, y+40, k/sokr);
        draw_branch(bufRoot->right, 1, x+k/sokr, y+40, k/sokr);
        draw_info(x, y, bufRoot->key, bufRoot->num);
    }
}

void Widget::draw_info(int x, int y, QChar key, int num)
{
    painter->setPen(QPen(Qt::blue, 3));
    painter->drawText(x-5, y-7, QString(key));
    if (num)
        painter->setPen(QPen(Qt::red, 6));
    else
        painter->setPen(QPen(Qt::green, 6));
    painter->drawPoint(x, y);
}

void Widget::free_tree(Root *bufTree)
{
    if (bufTree)
    {
        free_tree(bufTree->left);
        free_tree(bufTree->right);
        free(bufTree);
        bufTree = NULL;
    }
}

void Widget::on_buildBtn_clicked()
{
    free_tree(BTree);
    CreationBinaryTree(BTree);
    draw_tree();
}

void Widget::on_addBtn_clicked()
{
    if (!letEdt->text().isEmpty())
        BTree = Insert(BTree, letEdt->text().data()[0]);
    draw_tree();
}

void Widget::on_delBtn_clicked()
{
    Root *bufRoot;
    if (!letEdt->text().isEmpty())
        while ((bufRoot = SearchByLetter(BTree, letEdt->text().data()[0])) != NULL)
            BTree = Remove(BTree, bufRoot);
    draw_tree();
}

Root* Widget::delRep(Root *BTree)
{
    Root *bufRoot = BTree;
    Root *bufRoot2;
    if (bufRoot)
    {
        if ((bufRoot2 = delRep(bufRoot->left)) != NULL)
            return bufRoot2;
        if ((bufRoot2 = delRep(bufRoot->right)) != NULL)
            return bufRoot2;
        if (bufRoot->num)
            return bufRoot;
    }
    return NULL;
}

void Widget::on_delRepBtn_clicked()
{
    Root *bufRoot;
    while ((bufRoot = delRep(BTree)) != NULL)
        BTree = Remove(BTree, bufRoot);
    draw_tree();
}

void Widget::inorder(Root* bufTree) // сортировка
{
    if (!bufTree)
        return;
    inorder(bufTree->left);
    order_str.append(bufTree->key);
    inorder(bufTree->right);
}

void Widget::preorder(Root* bufTree)
{
    if (!bufTree)
        return;
    order_str.append(bufTree->key);
    preorder(bufTree->left);
    preorder(bufTree->right);
}

unsigned long long tick(void)
{
    unsigned long long d;

    __asm__ __volatile__ ("rdtsc" : "=A" (d) );

    return d;
}

void Widget::sort_i(QString &str, int cnt)
{
    int i, j;
    for (i = 1; i < cnt; i++)
        for (j = i; j > 0 && str[j - 1] > str[j]; j--)
        {
            QChar ch = str[j-1];
            str[j-1] = str[j];
            str[j] = ch;
        }
}

void delrepstr(QString &str, int cnt)
{
    int i, j;
    int flag;
    for (i=0; i < cnt; i++)
    {
        flag = 0;
        for (j=i+1; j<cnt; j++)
            if (str[i] == str[j])
            {
                str.remove(j, 1);
                flag = 1;
            }
        if (flag)
            str.remove(i, 1);
    }
}

void Widget::on_timeBtn_clicked()
{
    unsigned long long tb;
    double t1, t2, t3, t4;
    emit on_buildBtn_clicked();
    order_str.clear();
    tb = tick();
    inorder(BTree);
    t1 = tick() - tb;
    outLbl->setText(order_str);
    QString str;
    str.append(strEdt->text());
    int cnt = str.length();
    tb = tick();
    sort_i(str, cnt);
    t2 = tick() - tb;

    emit on_buildBtn_clicked();
    Root *bufRoot;
    tb = tick();
    while ((bufRoot = delRep(BTree)) != NULL)
        BTree = Remove(BTree, bufRoot);
    t3 = tick() - tb;

    str.clear();
    str.append(strEdt->text());
    cnt = str.length();
    tb = tick();
    delrepstr(str, cnt);
    t4 = tick() - tb;

    draw_tree();
    QMessageBox::information(this, "замеры времени сортировки", "Время дерева на сортировку: " +
                     QString::number(t1) + " тактов.\n Время строки на сортировку: " +
                     QString::number(t2)+" тактов.\n\t Разница: "+QString::number((t2-t1)/t1*100) +
                     " %.\n Время дерева на удаление повторяющихся элементов: " +
                     QString::number(t3) + " тактов.\n Время строки на удаление: " +
                     QString::number(t4) + " тактов.\n\t Разница: " +
                     QString::number((t4-t3)/t3*100) + " % ", QMessageBox::Ok);
}

