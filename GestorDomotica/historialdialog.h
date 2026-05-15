#ifndef HISTORIALDIALOG_H
#define HISTORIALDIALOG_H

#include <QDialog>
#include "databasemanager.h"

namespace Ui { class HistorialDialog; }

class HistorialDialog : public QDialog {
    Q_OBJECT

public:
    HistorialDialog(DatabaseManager* db, QWidget *parent = nullptr);
    ~HistorialDialog();

private slots:
    void on_pushButton_clicked(); // Cerrar

private:
    Ui::HistorialDialog *ui;
};

#endif // HISTORIALDIALOG_H
