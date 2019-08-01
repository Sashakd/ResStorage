#include "widget.h"

#define K_VAL (40)
#define Y_VAL (40)

//_________________поиск в двоичном дереве_________________//
Root* Widget::SearchByLetter(Root *BTree, QChar key)
{
    Root *bufRoot = BTree;

    if (bufRoot)
    {
        kol_avl++;
        if (bufRoot->key == key)
            return bufRoot;
        if (bufRoot->key > key)
            return SearchByLetter(bufRoot->left, key);
        if (bufRoot->key < key)
            return SearchByLetter(bufRoot->right, key);
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
//_________________поиск в двоичном дереве____________________//

//_______________редактирование двоичного дерева______________//
Root* Widget::Remove(Root *BTree, Root *DelRoot)
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

Root* Widget::Insert(Root* TreeTop, QChar key)
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
//_______________редактирование двоичного дерева______________//

//_________________отрисовка двоичного дерева_________________//
void Widget::draw_tree(Root *BTree, QLabel *imgLbl, QPainter *painter, QPixmap *pic) // дерево и лейбл
{
    int k = K_VAL;
    painter->setPen(QPen(Qt::white, 4));
    painter->drawRect(-1, -1, imgLbl->width(), imgLbl->height());
    if (BTree)
    {
        int x = imgLbl->width()/2, y = 18;
        draw_branch(BTree->left, 0, x-k, y+Y_VAL, k, painter);
        draw_branch(BTree->right, 1, x+k, y+Y_VAL, k, painter);
        draw_info(x, y, BTree->key, BTree->num, painter);
    }
    imgLbl->setPixmap(*pic);
}

void Widget::draw_branch(Root *bufRoot, int p, int x, int y, int k, QPainter *painter)
{
    double sokr = 1.4;
    if (bufRoot)
    {
        painter->setPen(QPen(Qt::gray, 3));
        if (p)
            painter->drawLine(x, y, x-k, y-Y_VAL);
        else
            painter->drawLine(x, y, x+k, y-Y_VAL);
        draw_branch(bufRoot->left, 0, x-k/sokr, y+Y_VAL, k/sokr, painter);
        draw_branch(bufRoot->right, 1, x+k/sokr, y+Y_VAL, k/sokr, painter);
        draw_info(x, y, bufRoot->key, bufRoot->num, painter);
    }
}

void Widget::draw_info(int x, int y, QChar key, int num, QPainter *painter)
{
    painter->setPen(QPen(Qt::blue, 3));
    painter->drawText(x-5, y-7, QString(key));
    if (num)
        painter->setPen(QPen(Qt::red, 6));
    else
        painter->setPen(QPen(Qt::green, 6));
    painter->drawPoint(x, y);
}
//_________________отрисовка двоичного дерева_________________//

//______________создание/очистка двоичного дерева_____________//
void Widget::CreationBinaryTree(Root* &BTree)
{
    int cnt = strEdt->text().length();
    BTree = NULL;
    for (int i=0; i<cnt; i++)
        BTree = Insert(BTree, strEdt->text().data()[i]);
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
//______________создание/очистка двоичного дерева_____________//
void Widget::btree_part()
{
    free_tree(BTree);
    CreationBinaryTree(BTree);
    Root *bufRoot;
    while ((bufRoot = delRep(BTree)) != NULL)
        BTree = Remove(BTree, bufRoot);
    draw_tree(BTree, btreeLbl, p1, pic1);
    order_str.clear();
    preorder(BTree);
}

void Widget::avltree_part()
{
    free_tree(balance_tree);
    balance_tree = NULL;
    flag = false;
    for (int i=0; i<order_str.size(); i++)
       balance_tree = add_tree(balance_tree,order_str.data()[i]);
    draw_tree(balance_tree, avlLbl, p2, pic2);
}

void Widget::preorder(Root* bufTree)
{
    if (!bufTree)
        return;
    order_str.append(bufTree->key);
    preorder(bufTree->left);
    preorder(bufTree->right);
}


//_______________________________avl_______________________________//
Root* Widget::add_tree(Root* node, QChar key)
{
    Root* Q1 = NULL;
    Root* Q2 = NULL;
    if (!node)
    {
        node = (Root*)malloc(sizeof(Root));;
        flag = true;
        node->key = key;
        node->left = node->right = NULL;
        node->bal = 0;
        node->num = 0;
    }
    else
    {
        node->num = 0;
        if (key <= node->key)
        {
            node->left = add_tree(node->left, key);
            if (flag)
            {
                if (node->bal == 1)
                {
                    node->bal = 0;
                    flag = false;
                }
                else
                    if (node->bal == 0)
                        node->bal = -1;
                else
                        if (node->bal == -1)
                        {
                            Q1 = node->left;
                            if (Q1->bal == -1)
                            {
                                node->left = Q1->right;
                                Q1->right = node;
                                node->bal = 0;
                                node = Q1;
                            }
                            else
                            {
                                Q2 = Q1->right;
                                Q1->right = Q2->left;
                                Q2->left = Q1;
                                node->left = Q2->right;
                                Q2->right = node;
                                if (Q2->bal == -1)
                                    node->bal = 1;
                                else
                                    node->bal = 0;
                                if (Q2->bal == 1)
                                    Q1->bal = -1;
                                else
                                    Q1->bal = 0;
                                node = Q2;
                            }
                            node->bal = 0;
                            flag = false;
                        }
            }
        }
        else
            if (key > node->key)
            {
                node->right = add_tree(node->right,key);
                if (flag)
                {
                    if (node->bal == -1)
                    {
                        node->bal = 0;
                        flag = false;
                    }
                    else
                        if (node->bal == 0)
                            node->bal = 1;
                    else
                            if (node->bal == 1)
                            {
                                Q1 = node->right;
                                if (Q1->bal == 1)
                                {
                                    node->right = Q1->left;
                                    Q1->left = node;
                                    node->bal = 0;
                                    node = Q1;
                                }
                                else
                                {
                                    Q2 = Q1->left;
                                    Q1->left = Q2->right;
                                    Q2->right = Q1;
                                    node->right = Q2->left;
                                    Q2->left = node;
                                    if (Q2->bal == 1)
                                        node->bal = -1;
                                    else
                                        node->bal = 0;
                                    if (Q2->bal == -1)
                                        Q1->bal = 1;
                                    else
                                        Q1->bal = 0;
                                    node = Q2;
                                }
                                node->bal = 0;
                                flag = false;
                            }
                }
            }
    }
    return node;
}
