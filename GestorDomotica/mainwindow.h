#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "dispositivo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();    // Agregar dispositivo
    void on_pushButton_2_clicked();  // Encender
    void on_pushButton_3_clicked();  // Apagar
    void on_pushButton_4_clicked();  // Fallo

private:
    Ui::MainWindow *ui;
    QList<Dispositivo*> dispositivos;
    void actualizarLista();
};

#endif // MAINWINDOW_H
