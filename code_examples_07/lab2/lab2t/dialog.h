#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "ui_dialog.h"

class Dialog: public QDialog, public Ui::Dialog
{
public:
    Dialog(QDialog *parent = 0);
private slots:
    void on_prBtn_clicked();
};

#endif // DIALOG_H
