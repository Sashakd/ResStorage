/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QGroupBox *groupBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *wrBtn;
    QRadioButton *prBtn;
    QGroupBox *bdGb;
    QLineEdit *edtDD;
    QLineEdit *edtMM;
    QLineEdit *edtYYYY;
    QGroupBox *wGb;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *edtPos;
    QLineEdit *edtOrg;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout;
    QLineEdit *edtName;
    QLineEdit *edtSurname;
    QLineEdit *edtTel;
    QLineEdit *edtAddr;

    void setupUi(QWidget *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(428, 208);
        btnOk = new QPushButton(Dialog);
        btnOk->setObjectName(QStringLiteral("btnOk"));
        btnOk->setGeometry(QRect(140, 140, 201, 61));
        btnCancel = new QPushButton(Dialog);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(350, 140, 71, 61));
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 130, 120, 80));
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 20, 97, 49));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        wrBtn = new QRadioButton(widget);
        wrBtn->setObjectName(QStringLiteral("wrBtn"));
        wrBtn->setChecked(true);

        verticalLayout_2->addWidget(wrBtn);

        prBtn = new QRadioButton(widget);
        prBtn->setObjectName(QStringLiteral("prBtn"));

        verticalLayout_2->addWidget(prBtn);

        bdGb = new QGroupBox(Dialog);
        bdGb->setObjectName(QStringLiteral("bdGb"));
        bdGb->setGeometry(QRect(220, 10, 161, 51));
        edtDD = new QLineEdit(bdGb);
        edtDD->setObjectName(QStringLiteral("edtDD"));
        edtDD->setGeometry(QRect(10, 20, 31, 22));
        edtMM = new QLineEdit(bdGb);
        edtMM->setObjectName(QStringLiteral("edtMM"));
        edtMM->setGeometry(QRect(50, 20, 31, 22));
        edtYYYY = new QLineEdit(bdGb);
        edtYYYY->setObjectName(QStringLiteral("edtYYYY"));
        edtYYYY->setGeometry(QRect(90, 20, 51, 22));
        wGb = new QGroupBox(Dialog);
        wGb->setObjectName(QStringLiteral("wGb"));
        wGb->setGeometry(QRect(210, 60, 211, 80));
        widget1 = new QWidget(wGb);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 20, 211, 55));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_5 = new QLabel(widget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_4->addWidget(label_5);

        label_6 = new QLabel(widget1);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_4->addWidget(label_6);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        edtPos = new QLineEdit(widget1);
        edtPos->setObjectName(QStringLiteral("edtPos"));

        verticalLayout_5->addWidget(edtPos);

        edtOrg = new QLineEdit(widget1);
        edtOrg->setObjectName(QStringLiteral("edtOrg"));

        verticalLayout_5->addWidget(edtOrg);


        horizontalLayout_2->addLayout(verticalLayout_5);

        widget2 = new QWidget(Dialog);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(10, 10, 203, 113));
        horizontalLayout = new QHBoxLayout(widget2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(widget2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);

        label_2 = new QLabel(widget2);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_3 = new QLabel(widget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        label_4 = new QLabel(widget2);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_3->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        edtName = new QLineEdit(widget2);
        edtName->setObjectName(QStringLiteral("edtName"));

        verticalLayout->addWidget(edtName);

        edtSurname = new QLineEdit(widget2);
        edtSurname->setObjectName(QStringLiteral("edtSurname"));

        verticalLayout->addWidget(edtSurname);

        edtTel = new QLineEdit(widget2);
        edtTel->setObjectName(QStringLiteral("edtTel"));

        verticalLayout->addWidget(edtTel);

        edtAddr = new QLineEdit(widget2);
        edtAddr->setObjectName(QStringLiteral("edtAddr"));

        verticalLayout->addWidget(edtAddr);


        horizontalLayout->addLayout(verticalLayout);

        btnOk->raise();
        edtName->raise();
        edtSurname->raise();
        label->raise();
        label_2->raise();
        btnCancel->raise();
        edtTel->raise();
        edtAddr->raise();
        label_3->raise();
        label_4->raise();
        groupBox->raise();
        bdGb->raise();
        wGb->raise();

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QWidget *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\320\240\320\265\320\264\320\260\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", 0));
        btnOk->setText(QApplication::translate("Dialog", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", 0));
        btnCancel->setText(QApplication::translate("Dialog", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
        groupBox->setTitle(QApplication::translate("Dialog", "\321\201\321\202\320\260\321\202\321\203\321\201", 0));
        wrBtn->setText(QApplication::translate("Dialog", "\321\200\320\260\320\261\320\276\321\207\320\270\320\271", 0));
        prBtn->setText(QApplication::translate("Dialog", "\320\273\320\270\321\207\320\275\321\213\320\271", 0));
        bdGb->setTitle(QApplication::translate("Dialog", "\320\264\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217", 0));
        wGb->setTitle(QApplication::translate("Dialog", "\321\200\320\260\320\261\320\276\321\202\320\260", 0));
        label_5->setText(QApplication::translate("Dialog", "\320\264\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", 0));
        label_6->setText(QApplication::translate("Dialog", "\320\276\321\200\320\263\320\260\320\275\320\270\320\267\320\260\321\206\320\270\321\217", 0));
        label->setText(QApplication::translate("Dialog", "\320\270\320\274\321\217", 0));
        label_2->setText(QApplication::translate("Dialog", "\321\204\320\260\320\274\320\270\320\273\320\270\321\217", 0));
        label_3->setText(QApplication::translate("Dialog", "\321\202\320\265\320\273\320\265\321\204\320\276\320\275", 0));
        label_4->setText(QApplication::translate("Dialog", "\320\260\320\264\321\200\320\265\321\201", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
