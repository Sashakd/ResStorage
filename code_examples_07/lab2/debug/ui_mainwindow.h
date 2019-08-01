/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QPushButton *condBtn;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *sortBtn;
    QPushButton *keyBtn;
    QCheckBox *bdCbx;
    QPushButton *timeBtn;
    QWidget *tab;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *fileBtn;
    QPushButton *delCurBtn;
    QPushButton *delBtn;
    QPushButton *editCurBtn;
    QPushButton *addBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1159, 428);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 10)
            tableWidget->setColumnCount(10);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setGeometry(QRect(250, 0, 901, 381));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setColumnCount(10);
        condBtn = new QPushButton(centralWidget);
        condBtn->setObjectName(QStringLiteral("condBtn"));
        condBtn->setGeometry(QRect(30, 10, 181, 28));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 50, 231, 311));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        layoutWidget = new QWidget(tab_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 176, 92));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        sortBtn = new QPushButton(layoutWidget);
        sortBtn->setObjectName(QStringLiteral("sortBtn"));
        sortBtn->setEnabled(true);

        verticalLayout->addWidget(sortBtn);

        keyBtn = new QPushButton(layoutWidget);
        keyBtn->setObjectName(QStringLiteral("keyBtn"));

        verticalLayout->addWidget(keyBtn);

        bdCbx = new QCheckBox(layoutWidget);
        bdCbx->setObjectName(QStringLiteral("bdCbx"));

        verticalLayout->addWidget(bdCbx);

        timeBtn = new QPushButton(tab_2);
        timeBtn->setObjectName(QStringLiteral("timeBtn"));
        timeBtn->setGeometry(QRect(20, 120, 131, 28));
        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 211, 170));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        fileBtn = new QPushButton(layoutWidget1);
        fileBtn->setObjectName(QStringLiteral("fileBtn"));

        verticalLayout_2->addWidget(fileBtn);

        delCurBtn = new QPushButton(layoutWidget1);
        delCurBtn->setObjectName(QStringLiteral("delCurBtn"));

        verticalLayout_2->addWidget(delCurBtn);

        delBtn = new QPushButton(layoutWidget1);
        delBtn->setObjectName(QStringLiteral("delBtn"));

        verticalLayout_2->addWidget(delBtn);

        editCurBtn = new QPushButton(layoutWidget1);
        editCurBtn->setObjectName(QStringLiteral("editCurBtn"));

        verticalLayout_2->addWidget(editCurBtn);

        addBtn = new QPushButton(layoutWidget1);
        addBtn->setObjectName(QStringLiteral("addBtn"));

        verticalLayout_2->addWidget(addBtn);

        tabWidget->addTab(tab, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1159, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Variable table", 0));
        condBtn->setText(QApplication::translate("MainWindow", "\321\203\321\201\320\273\320\276\320\262\320\270\320\265 \320\267\320\260\320\264\320\260\321\207\320\270", 0));
        sortBtn->setText(QApplication::translate("MainWindow", "\320\276\321\202\321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\262\321\201\321\216 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", 0));
        keyBtn->setText(QApplication::translate("MainWindow", "\320\276\321\202\321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\277\320\276 \320\272\320\273\321\216\321\207\321\203", 0));
        bdCbx->setText(QApplication::translate("MainWindow", "\320\262\321\213\320\262\320\276\320\264\320\270\321\202\321\214 \321\202\320\276\320\273\321\214\320\272\320\276 \320\224\320\240", 0));
        timeBtn->setText(QApplication::translate("MainWindow", "\320\267\320\260\320\274\320\265\321\200\321\213 \320\262\321\200\320\265\320\274\320\265\320\275\320\270", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\260", 0));
        fileBtn->setText(QApplication::translate("MainWindow", "\320\267\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", 0));
        delCurBtn->setText(QApplication::translate("MainWindow", "\321\203\320\264\320\260\320\273\320\270\321\202\321\214 \321\202\320\265\320\272\321\203\321\211\321\203\321\216 \320\267\320\260\320\277\320\270\321\201\321\214", 0));
        delBtn->setText(QApplication::translate("MainWindow", "\321\203\320\264\320\260\320\273\320\270\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", 0));
        editCurBtn->setText(QApplication::translate("MainWindow", "\321\200\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\202\320\265\320\272\321\203\321\211\321\203\321\216 \320\267\320\260\320\277\320\270\321\201\321\214", 0));
        addBtn->setText(QApplication::translate("MainWindow", "\320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
