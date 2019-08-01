/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *condBtn;
    QPushButton *buildBtn;
    QLineEdit *strEdt;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *avlLbl;
    QLabel *btreeLbl;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *tab_2;
    QTableWidget *openTbl;
    QTableWidget *closeTbl;
    QPushButton *testBtn;
    QLabel *label_4;
    QLineEdit *chEdt;
    QPushButton *findBtn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(723, 494);
        condBtn = new QPushButton(Widget);
        condBtn->setObjectName(QStringLiteral("condBtn"));
        condBtn->setGeometry(QRect(582, 20, 131, 28));
        buildBtn = new QPushButton(Widget);
        buildBtn->setObjectName(QStringLiteral("buildBtn"));
        buildBtn->setGeometry(QRect(370, 20, 201, 28));
        strEdt = new QLineEdit(Widget);
        strEdt->setObjectName(QStringLiteral("strEdt"));
        strEdt->setGeometry(QRect(70, 20, 291, 22));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 51, 20));
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 69, 711, 401));
        tabWidget->setStyleSheet(QStringLiteral("background-color: rgb(220, 220, 220);"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        avlLbl = new QLabel(tab);
        avlLbl->setObjectName(QStringLiteral("avlLbl"));
        avlLbl->setGeometry(QRect(360, 40, 321, 321));
        avlLbl->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        btreeLbl = new QLabel(tab);
        btreeLbl->setObjectName(QStringLiteral("btreeLbl"));
        btreeLbl->setGeometry(QRect(10, 40, 321, 321));
        btreeLbl->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 10, 121, 16));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(370, 10, 91, 16));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        openTbl = new QTableWidget(tab_2);
        if (openTbl->columnCount() < 3)
            openTbl->setColumnCount(3);
        if (openTbl->rowCount() < 41)
            openTbl->setRowCount(41);
        openTbl->setObjectName(QStringLiteral("openTbl"));
        openTbl->setGeometry(QRect(10, 30, 361, 331));
        openTbl->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        openTbl->setRowCount(41);
        openTbl->setColumnCount(3);
        closeTbl = new QTableWidget(tab_2);
        if (closeTbl->columnCount() < 1)
            closeTbl->setColumnCount(1);
        if (closeTbl->rowCount() < 41)
            closeTbl->setRowCount(41);
        closeTbl->setObjectName(QStringLiteral("closeTbl"));
        closeTbl->setGeometry(QRect(450, 30, 131, 331));
        closeTbl->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        closeTbl->setRowCount(41);
        closeTbl->setColumnCount(1);
        tabWidget->addTab(tab_2, QString());
        testBtn = new QPushButton(Widget);
        testBtn->setObjectName(QStringLiteral("testBtn"));
        testBtn->setGeometry(QRect(490, 50, 221, 28));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(180, 60, 53, 16));
        chEdt = new QLineEdit(Widget);
        chEdt->setObjectName(QStringLiteral("chEdt"));
        chEdt->setGeometry(QRect(220, 58, 41, 22));
        findBtn = new QPushButton(Widget);
        findBtn->setObjectName(QStringLiteral("findBtn"));
        findBtn->setGeometry(QRect(270, 56, 93, 28));

        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        condBtn->setText(QApplication::translate("Widget", "\321\203\321\201\320\273\320\276\320\262\320\270\320\265 \320\267\320\260\320\264\320\260\321\207\320\270", 0));
        buildBtn->setText(QApplication::translate("Widget", "\320\277\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\264\320\265\321\200\320\265\320\262\321\214\321\217 \320\270 \321\202\320\260\320\261\320\273\320\270\321\206\321\213", 0));
        label->setText(QApplication::translate("Widget", "\321\201\321\202\321\200\320\276\320\272\320\260", 0));
        avlLbl->setText(QApplication::translate("Widget", "avlTree", 0));
        btreeLbl->setText(QApplication::translate("Widget", "btree", 0));
        label_2->setText(QApplication::translate("Widget", "\320\261\320\270\320\275\320\260\321\200\320\275\320\276\320\265 \320\264\320\265\321\200\320\265\320\262\320\276", 0));
        label_3->setText(QApplication::translate("Widget", "\320\260\320\262\320\273-\320\264\320\265\321\200\320\265\320\262\320\276", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "\320\264\320\265\321\200\320\265\320\262\321\214\321\217", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "\321\202\320\260\320\261\320\273\320\270\321\206\321\213", 0));
        testBtn->setText(QApplication::translate("Widget", "\321\202\320\265\321\201\321\202\321\213 \321\202\320\265\320\272\321\203\321\211\320\265\320\263\320\276 \321\201\320\276\321\201\321\202\320\276\321\217\320\275\320\270\321\217 \321\201\321\202\321\200\321\203\320\272\321\202\321\203\321\200", 0));
        label_4->setText(QApplication::translate("Widget", "\320\261\321\203\320\272\320\262\320\260", 0));
        findBtn->setText(QApplication::translate("Widget", "\320\275\320\260\320\271\321\202\320\270", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
