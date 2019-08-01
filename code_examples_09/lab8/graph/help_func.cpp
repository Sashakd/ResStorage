#include "widget.h"
#include "ui_widget.h"
#include <cstdlib>

void Widget::on_condBtn_clicked() // условие задачи
{
    QMessageBox::information(this, "условие",
        "Есть множество городов, соединенных двусторонними .\n"\
        "железными и автомобильными дорогами.\n"\
        "Найти минимальный по длине путь из города А в Б,\n"\
        "и места пересадок с одного вида транспорта на другой.\n");
}

void Widget::print_graph()
{
    init_coord();
    painter->setPen(QPen(Qt::white, 1));
    painter->setBrush(QBrush(Qt::white));
    painter->drawRect(-1, -1, ui->imgLbl->width(), ui->imgLbl->height());

    for (int i=0; i<g_auto.size(); i++)
        for (int j=i+1; j<g_auto.size(); j++)
        {
            if (g_auto[i][j] != 0)
            {
                painter->setPen(QPen(Qt::blue, 1));
                painter->drawLine(coord[i], coord[j]);
                painter->drawText((coord[i].x()+coord[j].x())/2-11,
                             (coord[i].y()+coord[j].y())/2, QString::number(g_auto[i][j]));
            }
            if (g_train[i][j] != 0)
            {
                painter->setPen(QPen(Qt::black, 1));
                painter->drawLine(coord[i], coord[j]);
                painter->drawText((coord[i].x()+coord[j].x())/2+11,
                              (coord[i].y()+coord[j].y())/2, QString::number(g_train[i][j]));
            }
        }

    draw_headers();

    ui->imgLbl->setPixmap(*pic);
}

void Widget::init_coord()
{
    double xc = ui->imgLbl->width()/2, yc = ui->imgLbl->height()/2;
    double R = xc < yc ? xc - 20 : yc - 20;
    double delta = 2*3.1415926/g_auto.size();
    double angle = 0;
    QPointF crd;
    coord.clear();
    for (int i=0; i<g_auto.size(); i++)
    {
        crd.setX(xc + R*cos(angle));
        crd.setY(yc + R*sin(angle));
        angle += delta;
        coord.push_back(crd);
    }
}

void Widget::draw_headers()
{
    painter->setPen(QPen(Qt::darkGreen, 6));
    for (int i=0; i<coord.size(); i++)
    {
        painter->drawPoint(coord[i]);
        painter->drawText(coord[i].x()-6, coord[i].y()-6, QString::number(i));
    }
}

void Widget::draw_s()
{
    for (int i=0; i<s.size()-1; i++)
    {
        if (s_tt[i]!=0)
            painter->setPen(QPen(Qt::blue, 3));
        else
            painter->setPen(QPen(Qt::black, 3));
        painter->drawLine(coord[s[i]].x(), coord[s[i]].y(),
                coord[s[i+1]].x(), coord[s[i+1]].y());
    }
    ui->imgLbl->setPixmap(*pic);
}

int Widget::dijkstra(int a, int b)
{
    int count, u, V = g_auto.size();
    QVector<int> distance(V, INT_MAX);
    QVector<bool> visited(V, false);
    QVector<int> s_in(V, -1);

    distance[a]=0;
    for (count=0; count < V-1; count++)
    {
        int min = INT_MAX;
        for (int i=0; i<V; i++)
            if (!visited[i] && distance[i] <= min)
            {
                min = distance[i];
                u = i;
            }
        visited[u] = true;
        for (int i=0; i<V; i++)
            if (!visited[i] && g_sum[u][i].len && distance[u]!=INT_MAX &&
                    distance[u]+g_sum[u][i].len<distance[i])
            {
                distance[i] = g_sum[u][i].len+distance[u];
                s_in[i] = u;
            }
    }

    s.clear();
    s_tt.clear();
    s.push_back(b);
    u = b;
    if (distance[b] == INT_MAX)
        ui->infoLbl->setText("Маршрут недоступен");
    else
    {
        ui->infoLbl->setText("длина пути "+QString::number(distance[b]));
        while (u != a)
        {
            s_tt.push_back(g_sum[u][s_in[u]].type);
            u = s_in[u];
            s.push_back(u);
        }
    }
    return distance[b];
}

int Widget::dijkstra1(int a, int b)
{
    int count, u, V = g_auto.size();
    QVector<int> distance(V, INT_MAX);
    QVector<bool> visited(V, false);
    QVector<int> s_in(V, -1);

    distance[a]=0;
    for (count=0; count < V-1; count++)
    {
        int min = INT_MAX;
        for (int i=0; i<V; i++)
            if (!visited[i] && distance[i] <= min)
            {
                min = distance[i];
                u = i;
            }
        visited[u] = true;
        for (int i=0; i<V; i++)
            if (!visited[i] && g_auto[u][i] && distance[u]!=INT_MAX &&
                    distance[u]+g_auto[u][i]<distance[i])
            {
                distance[i] = g_auto[u][i]+distance[u];
                s_in[i] = u;
            }
    }

    s.clear();
    s_tt.clear();
    s.push_back(b);
    u = b;
    if (distance[b] == INT_MAX)
        ui->infoLbl->setText("Маршрут недоступен");
    else
    {
        ui->infoLbl->setText("длина пути "+QString::number(distance[b]));
        while (u != a)
        {
            s_tt.push_back(1);
            u = s_in[u];
            s.push_back(u);
        }
    }
    return distance[b];
}

int Widget::dijkstra2(int a, int b)
{
    int count, u, V = g_auto.size();
    QVector<int> distance(V, INT_MAX);
    QVector<bool> visited(V, false);
    QVector<int> s_in(V, -1);

    distance[a]=0;
    for (count=0; count < V-1; count++)
    {
        int min = INT_MAX;
        for (int i=0; i<V; i++)
            if (!visited[i] && distance[i] <= min)
            {
                min = distance[i];
                u = i;
            }
        visited[u] = true;
        for (int i=0; i<V; i++)
            if (!visited[i] && g_train[u][i] && distance[u]!=INT_MAX &&
                    distance[u]+g_train[u][i]<distance[i])
            {
                distance[i] = g_train[u][i]+distance[u];
                s_in[i] = u;
            }
    }

    s.clear();
    s_tt.clear();
    s.push_back(b);
    u = b;
    if (distance[b] == INT_MAX)
        ui->infoLbl->setText("Маршрут недоступен");
    else
    {
        ui->infoLbl->setText("длина пути "+QString::number(distance[b]));
        while (u != a)
        {
            s_tt.push_back(0);
            u = s_in[u];
            s.push_back(u);
        }
    }
    return distance[b];
}
