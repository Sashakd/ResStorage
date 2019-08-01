#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

void MainWindow::on_delBtn_clicked()
{
    if (data.size()!=0)
        data.remove(0, data.size());
    fill_table();
}

void MainWindow::cancel_but()
{
    dialog->hide();
}

void MainWindow::on_condBtn_clicked() // условие задачи
{
    myInfoMsg("условие", "Ввести список абонентов, содержащий фамилию, имя, телефон, "\
        "адрес, статус (личный - дата рождения: день, месяц, год; служебный - должность,"\
        " организация). Найти всех друзей, которых необходимо поздравить с днем "\
        "рождения в ближайшую неделю.");
}

QString MainWindow::getQS(FILE *fin)
{
    char s[80];
    fgets(s,80,fin);
    return QString::fromStdString(s).toUtf8();
}

int MainWindow::getInt(FILE *fin)
{
    char s[80];
    fgets(s,80,fin);
    return QString::fromStdString(s).toInt();
}

int MainWindow::raisedialog()
{
    QMessageBox::information(this,"Ошибка","Есть незаполненные поля!",QMessageBox::Ok);
    dialog->raise();
    return -1;
}

int MainWindow::myInfoMsg(QString s1, QString s2)
{
    QMessageBox::information(this, s1, s2, QMessageBox::Ok);
    return -1;
}

void MainWindow::setStr(QString s1,QString s2,QString s3,QString s4,QString s5)
{
    dialog->btnOk->setText(s1);
    dialog->edtName->setText(s2);
    dialog->edtSurname->setText(s3);
    dialog->edtTel->setText(s4);
    dialog->edtAddr->setText(s5);
}

void MainWindow::setVar(QString s1,QString s2,QString s3,QString s4,QString s5)
{
    dialog->edtPos->setText(s1);
    dialog->edtOrg->setText(s2);
    dialog->edtDD->setText(s3);
    dialog->edtMM->setText(s4);
    dialog->edtYYYY->setText(s5);
}

void MainWindow::wr_chb() // переключение статуса
{
    dialog->wrBtn->setChecked(true);
    dialog->bdGb->hide();
    dialog->wGb->show();
}

void MainWindow::pr_chb() // переключение статуса
{
    dialog->prBtn->setChecked(true);
    dialog->wGb->hide();
    dialog->bdGb->show();
}

void MainWindow::create_table() // задание заголовков
{
    QString headers[] = {"Имя", "Фамилия", "Телефон", "Адрес", "Статус",
                        "День", "Месяц", "Год", "Должность", "Организация"};
    int whead[] = {90, 100, 80, 110, 80, 50, 60, 40, 120, 120};
    for (int i=0; i<10; i++)
    {
        QTableWidgetItem *ti = new QTableWidgetItem;
        ti->setText(headers[i]);
        tableWidget->setHorizontalHeaderItem(i,ti);
        tableWidget->setColumnWidth(i, whead[i]);
    }
    tableWidget->horizontalHeaderItem(5)->setToolTip("День рождения");
    tableWidget->horizontalHeaderItem(6)->setToolTip("Месяц рождения");
    tableWidget->horizontalHeaderItem(7)->setToolTip("Год рождения");
}

int MainWindow::find_pos(int pos)
{
    int i=-1, k=-1;
    if (!bdCbx->isChecked())
        return pos;

    while (k<pos)
    {
        i++;
        if (birthday(i))
            k++;
    }

    return i;
}

void MainWindow::findBd(QVector<int> &bd)
{
    bd.clear();
    for (int i = 0; i < keys.size(); i++)
        if (birthday(i))
            bd.push_back(i);
}
