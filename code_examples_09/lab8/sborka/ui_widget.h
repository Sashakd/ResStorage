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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *condBtn;
    QLabel *imgLbl;
    QPushButton *createBtn;
    QGroupBox *groupBox;
    QLineEdit *num_fromEdt;
    QPushButton *delBtn;
    QLineEdit *num_toEdt;
    QLineEdit *val_edtEdt;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *addBtn;
    QLabel *label_4;
    QLabel *label_7;
    QComboBox *cmb;
    QLabel *infoLbl;
    QLabel *label;
    QPushButton *shortBtn;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *otEdt;
    QLineEdit *doEdt;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(629, 434);
        condBtn = new QPushButton(Widget);
        condBtn->setObjectName(QStringLiteral("condBtn"));
        condBtn->setGeometry(QRect(10, 220, 191, 28));
        imgLbl = new QLabel(Widget);
        imgLbl->setObjectName(QStringLiteral("imgLbl"));
        imgLbl->setGeometry(QRect(230, 20, 381, 381));
        createBtn = new QPushButton(Widget);
        createBtn->setObjectName(QStringLiteral("createBtn"));
        createBtn->setGeometry(QRect(10, 10, 191, 41));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 50, 191, 171));
        num_fromEdt = new QLineEdit(groupBox);
        num_fromEdt->setObjectName(QStringLiteral("num_fromEdt"));
        num_fromEdt->setGeometry(QRect(130, 17, 41, 22));
        delBtn = new QPushButton(groupBox);
        delBtn->setObjectName(QStringLiteral("delBtn"));
        delBtn->setGeometry(QRect(10, 130, 71, 28));
        num_toEdt = new QLineEdit(groupBox);
        num_toEdt->setObjectName(QStringLiteral("num_toEdt"));
        num_toEdt->setGeometry(QRect(130, 44, 41, 22));
        val_edtEdt = new QLineEdit(groupBox);
        val_edtEdt->setObjectName(QStringLiteral("val_edtEdt"));
        val_edtEdt->setGeometry(QRect(130, 70, 41, 22));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 47, 111, 16));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 74, 121, 16));
        addBtn = new QPushButton(groupBox);
        addBtn->setObjectName(QStringLiteral("addBtn"));
        addBtn->setGeometry(QRect(100, 130, 71, 28));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 20, 111, 16));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 100, 121, 16));
        cmb = new QComboBox(groupBox);
        cmb->setObjectName(QStringLiteral("cmb"));
        cmb->setGeometry(QRect(90, 100, 81, 22));
        infoLbl = new QLabel(Widget);
        infoLbl->setObjectName(QStringLiteral("infoLbl"));
        infoLbl->setGeometry(QRect(20, 340, 171, 81));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(230, 410, 391, 16));
        shortBtn = new QPushButton(Widget);
        shortBtn->setObjectName(QStringLiteral("shortBtn"));
        shortBtn->setGeometry(QRect(10, 290, 191, 28));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 260, 21, 16));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 260, 21, 16));
        otEdt = new QLineEdit(Widget);
        otEdt->setObjectName(QStringLiteral("otEdt"));
        otEdt->setGeometry(QRect(50, 260, 41, 22));
        doEdt = new QLineEdit(Widget);
        doEdt->setObjectName(QStringLiteral("doEdt"));
        doEdt->setGeometry(QRect(150, 260, 41, 22));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\320\223\321\200\320\260\321\204\321\213", 0));
        condBtn->setText(QApplication::translate("Widget", "\321\203\321\201\320\273\320\276\320\262\320\270\320\265", 0));
        imgLbl->setText(QApplication::translate("Widget", "TextLabel", 0));
        createBtn->setText(QApplication::translate("Widget", "\320\267\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\201\320\270\321\201\321\202\320\265\320\274\321\203 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", 0));
        groupBox->setTitle(QApplication::translate("Widget", "\321\200\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \321\200\320\265\320\261\320\265\321\200 \320\263\321\200\320\260\321\204\320\260", 0));
        delBtn->setText(QApplication::translate("Widget", "\321\203\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        label_5->setText(QApplication::translate("Widget", "\320\264\320\276 \320\272\320\260\320\272\320\276\320\271 \320\262\320\265\321\200\321\210\320\270\320\275\321\213", 0));
        label_6->setText(QApplication::translate("Widget", "\320\267\320\260\320\264\320\260\321\202\321\214 \321\200\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\320\265", 0));
        addBtn->setText(QApplication::translate("Widget", "\320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
        label_4->setText(QApplication::translate("Widget", "\320\276\321\202 \320\272\320\260\320\272\320\276\320\271 \320\262\320\265\321\200\321\210\320\270\320\275\321\213", 0));
        label_7->setText(QApplication::translate("Widget", "\320\267\320\260\320\264\320\260\321\202\321\214 \321\202\320\270\320\277", 0));
        cmb->clear();
        cmb->insertItems(0, QStringList()
         << QApplication::translate("Widget", "\320\266/\320\264", 0)
         << QApplication::translate("Widget", "\320\260\320\262\321\202\320\276", 0)
        );
        infoLbl->setText(QString());
        label->setText(QApplication::translate("Widget", "\321\207\320\265\321\200\320\275\321\213\320\265 - \320\266/\320\264, \321\201\320\270\320\275\320\270\320\265 - \320\260\320\262\321\202\320\276\320\274\320\276\320\261\320\270\320\273\321\214\320\275\321\213\320\265", 0));
        shortBtn->setText(QApplication::translate("Widget", "\320\275\320\260\320\271\321\202\320\270 \320\272\321\200\320\260\321\202\321\207\320\260\320\271\321\210\320\270\320\271 \320\277\321\203\321\202\321\214", 0));
        label_2->setText(QApplication::translate("Widget", "\320\276\321\202", 0));
        label_3->setText(QApplication::translate("Widget", "\320\264\320\276", 0));
        otEdt->setText(QString());
        doEdt->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
