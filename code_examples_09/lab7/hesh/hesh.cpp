#include "widget.h"


void Widget::openhash_part()
{
    for (int i=0; i<open_h.size(); i++)
        open_h[i].clear();
    create_h(open_h);
    for (int i=0; i<order_str.size(); i++)
       add_open(order_str.toStdString().data()[i]);
    fill_table(open_h, openTbl);
}

void Widget::closehash_part()
{
    for (int i=0; i<close_h.size(); i++)
        close_h[i].clear();
    create_h(close_h);

    for (int i=0; i<order_str.size(); i++)
       add_close(order_str.toStdString().data()[i]);
    fill_table(close_h, closeTbl);
}

void Widget::create_h(QVector< QList<char> > &tbl)
{
    tbl.resize(TBL_SIZE);
}

void Widget::add_open(char ch)
{
    open_h[index(ch)].append(ch);
}

void Widget::add_close(char ch)
{
    int cur = index(ch);
    while ((close_h[cur].size()!=0) && (cur<close_h.size()))
        cur++;
    close_h[cur].append(ch);
}

void Widget::fill_table(QVector< QList<char> > hesh, QTableWidget *tbl)
{
    tbl->clear();
    for (int i=0; i<hesh.size(); i++)
        for (int j=0; j<hesh[i].size(); j++)
        {
            QTableWidgetItem* it = new QTableWidgetItem;
            it->setText(QChar::fromLatin1(hesh[i][j]));
            tbl->setItem(i,j,it);
        }
}

int Widget::index(char ch)
{
    return ch%TBL_SIZE;
}


int Widget::open_search(char ch)
{
    int kol = 0;
    int ind = index(ch);
    for (int i = 0; i < open_h[ind].size(); i++)
    {
            kol++;
            if (open_h[ind][i]==ch)
            {
                flag1 = true;
                return kol;
            }
    }
    flag1 = false;
    return kol;
}

double Widget::compare_open(double &time)
{
    int kol = 0;

    double t_time = 0.0;
    unsigned long long t;
    for (int i=0; i<order_str.size(); i++)
    {
        char ch = order_str.toStdString().data()[i];
        t = tick();
        kol += open_search(ch);
        t = tick() - t;
        t_time += t;
    }
    time = (double) t_time/(5*order_str.size());
    return (double)kol/order_str.size();
}

double Widget::compare_closed(double &time)
{
    int kol = 0;
    double t_time = 0.0;
    unsigned long long t;
    for (int i=0; i<order_str.size(); i++)
    {
        char ch = order_str.toStdString().data()[i];
        t = tick();
        kol += closed_search(ch);
        t = tick() - t;
        t_time += t;
    }
    time = (double) t_time/(5*order_str.size());
    return (double)kol/order_str.size();
}

int Widget::closed_search(char ch)
{
        int kol = 0;
        for (int i = index(ch); i < close_h.size() && close_h[i].size()>0; i++)
        {
                kol++;
                if (close_h[i][0]==ch)
                {
                    flag1 = true;
                    return kol;
                }
        }
        flag1 = false;
        return kol;
}

