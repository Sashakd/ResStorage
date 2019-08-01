/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *condBtn;
    QPushButton *testBtn;
    QLabel *imgLbl1;
    QLabel *imgLbl2;
    QLabel *imgLbl3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *createBtn;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *CBEdt;
    QLineEdit *PAEdt;
    QLineEdit *CAEdt;
    QLabel *label_9;
    QLineEdit *PBEdt;
    QLineEdit *RBEdt;
    QLineEdit *RAEdt;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_11;
    QWidget *tab_2;
    QPushButton *insBtn;
    QPushButton *delBtn;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *colEdt;
    QLabel *label_14;
    QLineEdit *valEdt;
    QLineEdit *rowEdt;
    QLabel *label_15;
    QComboBox *cmb;
    QPushButton *mulBtn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(376, 359);
        condBtn = new QPushButton(Widget);
        condBtn->setObjectName(QStringLiteral("condBtn"));
        condBtn->setGeometry(QRect(270, 150, 93, 28));
        testBtn = new QPushButton(Widget);
        testBtn->setObjectName(QStringLiteral("testBtn"));
        testBtn->setGeometry(QRect(270, 180, 93, 28));
        imgLbl1 = new QLabel(Widget);
        imgLbl1->setObjectName(QStringLiteral("imgLbl1"));
        imgLbl1->setGeometry(QRect(20, 250, 100, 100));
        imgLbl2 = new QLabel(Widget);
        imgLbl2->setObjectName(QStringLiteral("imgLbl2"));
        imgLbl2->setGeometry(QRect(140, 250, 100, 100));
        imgLbl3 = new QLabel(Widget);
        imgLbl3->setObjectName(QStringLiteral("imgLbl3"));
        imgLbl3->setGeometry(QRect(260, 250, 100, 100));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 220, 61, 20));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(150, 220, 61, 20));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(260, 220, 101, 20));
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 361, 131));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        createBtn = new QPushButton(tab);
        createBtn->setObjectName(QStringLiteral("createBtn"));
        createBtn->setGeometry(QRect(10, 70, 331, 28));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 10, 71, 16));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 40, 71, 16));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(170, 10, 16, 16));
        CBEdt = new QLineEdit(tab);
        CBEdt->setObjectName(QStringLiteral("CBEdt"));
        CBEdt->setGeometry(QRect(182, 40, 31, 22));
        PAEdt = new QLineEdit(tab);
        PAEdt->setObjectName(QStringLiteral("PAEdt"));
        PAEdt->setGeometry(QRect(320, 10, 31, 22));
        CAEdt = new QLineEdit(tab);
        CAEdt->setObjectName(QStringLiteral("CAEdt"));
        CAEdt->setGeometry(QRect(182, 10, 31, 22));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(230, 40, 91, 16));
        PBEdt = new QLineEdit(tab);
        PBEdt->setObjectName(QStringLiteral("PBEdt"));
        PBEdt->setGeometry(QRect(320, 40, 31, 20));
        RBEdt = new QLineEdit(tab);
        RBEdt->setObjectName(QStringLiteral("RBEdt"));
        RBEdt->setGeometry(QRect(134, 40, 31, 22));
        RAEdt = new QLineEdit(tab);
        RAEdt->setObjectName(QStringLiteral("RAEdt"));
        RAEdt->setGeometry(QRect(135, 10, 31, 22));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(170, 40, 16, 16));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(230, 10, 91, 16));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(80, 10, 51, 16));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(80, 40, 51, 16));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        insBtn = new QPushButton(tab_2);
        insBtn->setObjectName(QStringLiteral("insBtn"));
        insBtn->setGeometry(QRect(190, 70, 161, 28));
        insBtn->setAutoDefault(true);
        delBtn = new QPushButton(tab_2);
        delBtn->setObjectName(QStringLiteral("delBtn"));
        delBtn->setGeometry(QRect(10, 70, 171, 28));
        delBtn->setAutoDefault(true);
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(140, 13, 41, 16));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 10, 51, 16));
        colEdt = new QLineEdit(tab_2);
        colEdt->setObjectName(QStringLiteral("colEdt"));
        colEdt->setGeometry(QRect(310, 10, 41, 22));
        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(244, 12, 51, 16));
        valEdt = new QLineEdit(tab_2);
        valEdt->setObjectName(QStringLiteral("valEdt"));
        valEdt->setGeometry(QRect(230, 40, 121, 22));
        rowEdt = new QLineEdit(tab_2);
        rowEdt->setObjectName(QStringLiteral("rowEdt"));
        rowEdt->setGeometry(QRect(190, 10, 41, 22));
        label_15 = new QLabel(tab_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 40, 211, 16));
        cmb = new QComboBox(tab_2);
        cmb->setObjectName(QStringLiteral("cmb"));
        cmb->setGeometry(QRect(70, 10, 51, 22));
        tabWidget->addTab(tab_2, QString());
        mulBtn = new QPushButton(Widget);
        mulBtn->setObjectName(QStringLiteral("mulBtn"));
        mulBtn->setGeometry(QRect(10, 150, 201, 41));
        QWidget::setTabOrder(CBEdt, insBtn);
        QWidget::setTabOrder(insBtn, CAEdt);
        QWidget::setTabOrder(CAEdt, PAEdt);
        QWidget::setTabOrder(PAEdt, RBEdt);
        QWidget::setTabOrder(RBEdt, RAEdt);
        QWidget::setTabOrder(RAEdt, testBtn);
        QWidget::setTabOrder(testBtn, delBtn);
        QWidget::setTabOrder(delBtn, colEdt);
        QWidget::setTabOrder(colEdt, valEdt);
        QWidget::setTabOrder(valEdt, rowEdt);
        QWidget::setTabOrder(rowEdt, cmb);
        QWidget::setTabOrder(cmb, condBtn);
        QWidget::setTabOrder(condBtn, PBEdt);
        QWidget::setTabOrder(PBEdt, tabWidget);
        QWidget::setTabOrder(tabWidget, mulBtn);
        QWidget::setTabOrder(mulBtn, createBtn);

        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Sparse Matrixes", 0));
        condBtn->setText(QApplication::translate("Widget", "\321\203\321\201\320\273\320\276\320\262\320\270\320\265", 0));
        testBtn->setText(QApplication::translate("Widget", "\321\202\320\265\321\201\321\202\321\213", 0));
        imgLbl1->setText(QApplication::translate("Widget", "TextLabel", 0));
        imgLbl2->setText(QApplication::translate("Widget", "TextLabel", 0));
        imgLbl3->setText(QApplication::translate("Widget", "TextLabel", 0));
        label->setText(QApplication::translate("Widget", "\320\274\320\260\321\202\321\200\320\270\321\206\320\260 A", 0));
        label_2->setText(QApplication::translate("Widget", "\320\274\320\260\321\202\321\200\320\270\321\206\320\260 B", 0));
        label_3->setText(QApplication::translate("Widget", "\320\274\320\260\321\202\321\200\320\270\321\206\320\260 C = AxB", 0));
        createBtn->setText(QApplication::translate("Widget", "\321\201\320\276\320\267\320\264\320\260\321\202\321\214 \320\274\320\260\321\202\321\200\320\270\321\206\321\213", 0));
        label_4->setText(QApplication::translate("Widget", "\320\274\320\260\321\202\321\200\320\270\321\206\320\260 \320\220", 0));
        label_5->setText(QApplication::translate("Widget", "\320\274\320\260\321\202\321\200\320\270\321\206\320\260 \320\222", 0));
        label_6->setText(QApplication::translate("Widget", "\321\205", 0));
        CBEdt->setText(QApplication::translate("Widget", "10", 0));
        PAEdt->setText(QApplication::translate("Widget", "50", 0));
        CAEdt->setText(QApplication::translate("Widget", "10", 0));
        label_9->setText(QApplication::translate("Widget", "% \320\267\320\260\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217", 0));
        PBEdt->setText(QApplication::translate("Widget", "50", 0));
        RBEdt->setText(QApplication::translate("Widget", "10", 0));
        RAEdt->setText(QApplication::translate("Widget", "10", 0));
        label_7->setText(QApplication::translate("Widget", "\321\205", 0));
        label_8->setText(QApplication::translate("Widget", "% \320\267\320\260\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217", 0));
        label_10->setText(QApplication::translate("Widget", "\321\200\320\260\320\267\320\274\320\265\321\200\321\213", 0));
        label_11->setText(QApplication::translate("Widget", "\321\200\320\260\320\267\320\274\320\265\321\200\321\213", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "\321\201\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\274\320\260\321\202\321\200\320\270\321\206", 0));
        insBtn->setText(QApplication::translate("Widget", "\320\262\321\201\321\202\320\260\320\262\320\270\321\202\321\214 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", 0));
        delBtn->setText(QApplication::translate("Widget", "\321\203\320\264\320\260\320\273\320\270\321\202\321\214 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", 0));
        label_12->setText(QApplication::translate("Widget", "\321\201\321\202\321\200\320\276\320\272\320\260", 0));
        label_13->setText(QApplication::translate("Widget", "\320\274\320\260\321\202\321\200\320\270\321\206\320\260", 0));
        label_14->setText(QApplication::translate("Widget", "\321\201\321\202\320\276\320\273\320\261\320\265\321\206", 0));
        label_15->setText(QApplication::translate("Widget", "\320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260 (\320\277\321\200\320\270 \320\262\321\201\321\202\320\260\320\262\320\272\320\265)", 0));
        cmb->clear();
        cmb->insertItems(0, QStringList()
         << QApplication::translate("Widget", "A", 0)
         << QApplication::translate("Widget", "B", 0)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "\321\200\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", 0));
        mulBtn->setText(QApplication::translate("Widget", "\321\203\320\274\320\275\320\276\320\266\320\270\321\202\321\214 \321\201\320\276\320\267\320\264\320\260\320\275\320\275\321\213\320\265 \320\274\320\260\321\202\321\200\320\270\321\206\321\213", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
