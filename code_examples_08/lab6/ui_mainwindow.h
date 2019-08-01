/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad;
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QPushButton *btnAdd;
    QPushButton *btnSort;
    QPushButton *btnRemove;
    QLineEdit *edtRemove;
    QPushButton *btnSearch;
    QPushButton *pushButton;
    QGraphicsView *graphicsView;
    QLineEdit *edtLetter;
    QLabel *label;
    QPushButton *btnFind;
    QTableWidget *tableWidget_2;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1141, 700);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 221, 361));
        btnAdd = new QPushButton(centralWidget);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));
        btnAdd->setGeometry(QRect(250, 50, 111, 31));
        btnSort = new QPushButton(centralWidget);
        btnSort->setObjectName(QStringLiteral("btnSort"));
        btnSort->setGeometry(QRect(250, 90, 111, 31));
        btnRemove = new QPushButton(centralWidget);
        btnRemove->setObjectName(QStringLiteral("btnRemove"));
        btnRemove->setGeometry(QRect(380, 50, 111, 31));
        edtRemove = new QLineEdit(centralWidget);
        edtRemove->setObjectName(QStringLiteral("edtRemove"));
        edtRemove->setGeometry(QRect(250, 20, 241, 20));
        btnSearch = new QPushButton(centralWidget);
        btnSearch->setObjectName(QStringLiteral("btnSearch"));
        btnSearch->setGeometry(QRect(380, 90, 111, 31));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(250, 130, 241, 41));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(1100, 0, 256, 192));
        edtLetter = new QLineEdit(centralWidget);
        edtLetter->setObjectName(QStringLiteral("edtLetter"));
        edtLetter->setGeometry(QRect(290, 180, 113, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 180, 46, 13));
        btnFind = new QPushButton(centralWidget);
        btnFind->setObjectName(QStringLiteral("btnFind"));
        btnFind->setGeometry(QRect(410, 180, 75, 23));
        tableWidget_2 = new QTableWidget(centralWidget);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(250, 250, 251, 191));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 220, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1141, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionLoad);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0));
        btnAdd->setText(QApplication::translate("MainWindow", "Add", 0));
        btnSort->setText(QApplication::translate("MainWindow", "Sort", 0));
        btnRemove->setText(QApplication::translate("MainWindow", "Remove", 0));
        btnSearch->setText(QApplication::translate("MainWindow", "Search", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Draw tree", 0));
        label->setText(QApplication::translate("MainWindow", "Letter:", 0));
        btnFind->setText(QApplication::translate("MainWindow", "Find", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
