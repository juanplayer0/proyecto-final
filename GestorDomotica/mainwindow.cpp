#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowTitle("Gestor de Domótica");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::actualizarLista() {
    ui->listWidget->clear();
    for (Dispositivo* d : dispositivos) {
        QString item = d->getNombre() + " [" + d->getTipo() + "] - " + d->getEstado();
        ui->listWidget->addItem(item);
    }
}

void MainWindow::on_pushButton_clicked() {  // Encender
    int i = ui->listWidget->currentRow();
    if (i >= 0) { dispositivos[i]->encender(); actualizarLista(); }
}

void MainWindow::on_pushButton_2_clicked() {  // Apagar
    int i = ui->listWidget->currentRow();
    if (i >= 0) { dispositivos[i]->apagar(); actualizarLista(); }
}

void MainWindow::on_pushButton_3_clicked() {  // Fallo
    int i = ui->listWidget->currentRow();
    if (i >= 0) { dispositivos[i]->setFallo(); actualizarLista(); }
}

void MainWindow::on_pushButton_4_clicked() {  // Agregar
    QString nombre = QInputDialog::getText(this, "Nuevo Dispositivo", "Nombre:");
    QString tipo   = QInputDialog::getText(this, "Nuevo Dispositivo", "Tipo (Luz/Persiana/Sensor):");
    if (!nombre.isEmpty() && !tipo.isEmpty()) {
        dispositivos.append(new Dispositivo(nombre, tipo));
        actualizarLista();
    }
}
