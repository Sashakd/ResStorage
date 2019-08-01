/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *buildBtn;
    QPushButton *addBtn;
    QPushButton *delRepBtn;
    QPushButton *timeBtn;
    QLabel *imgLbl;
    QLineEdit *strEdt;
    QPushButton *delBtn;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *letEdt;
    QLabel *outLbl;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(661, 530);
        buildBtn = new QPushButton(Widget);
        buildBtn->setObjectName(QStringLiteral("buildBtn"));
        buildBtn->setGeometry(QRect(361, 7, 120, 30));
        addBtn = new QPushButton(Widget);
        addBtn->setObjectName(QStringLiteral("addBtn"));
        addBtn->setGeometry(QRect(100, 40, 93, 28));
        delRepBtn = new QPushButton(Widget);
        delRepBtn->setObjectName(QStringLiteral("delRepBtn"));
        delRepBtn->setGeometry(QRect(490, 7, 161, 30));
        timeBtn = new QPushButton(Widget);
        timeBtn->setObjectName(QStringLiteral("timeBtn"));
        timeBtn->setGeometry(QRect(530, 40, 121, 28));
        imgLbl = new QLabel(Widget);
        imgLbl->setObjectName(QStringLiteral("imgLbl"));
        imgLbl->setGeometry(QRect(10, 80, 641, 431));
        strEdt = new QLineEdit(Widget);
        strEdt->setObjectName(QStringLiteral("strEdt"));
        strEdt->setGeometry(QRect(60, 10, 291, 22));
        delBtn = new QPushButton(Widget);
        delBtn->setObjectName(QStringLiteral("delBtn"));
        delBtn->setGeometry(QRect(200, 40, 93, 28));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 41, 16));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 40, 53, 16));
        letEdt = new QLineEdit(Widget);
        letEdt->setObjectName(QStringLiteral("letEdt"));
        letEdt->setGeometry(QRect(60, 40, 31, 22));
        outLbl = new QLabel(Widget);
        outLbl->setObjectName(QStringLiteral("outLbl"));
        outLbl->setGeometry(QRect(337, 45, 181, 20));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        buildBtn->setText(QApplication::translate("Widget", "\320\277\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\264\320\265\321\200\320\265\320\262\320\276", 0));
        addBtn->setText(QApplication::translate("Widget", "\320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
        delRepBtn->setText(QApplication::translate("Widget", "\321\203\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\320\276\320\262\321\202\320\276\321\200\321\217\321\216\321\211\320\270\320\265\321\201\321\217", 0));
        timeBtn->setText(QApplication::translate("Widget", "\320\267\320\260\320\274\320\265\321\200\321\213 \320\262\321\200\320\265\320\274\320\265\320\275\320\270", 0));
        imgLbl->setText(QApplication::translate("Widget", "                                                                         TextLabel", 0));
        strEdt->setText(QString());
        delBtn->setText(QApplication::translate("Widget", "\321\203\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        label_2->setText(QApplication::translate("Widget", "\321\201\321\202\321\200\320\276\320\272\320\260", 0));
        label_3->setText(QApplication::translate("Widget", "\320\261\321\203\320\272\320\262\320\260", 0));
        outLbl->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
