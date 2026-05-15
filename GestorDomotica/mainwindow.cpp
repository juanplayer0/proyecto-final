#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowTitle("Gestor de Domótica");

    // Conectar base de datos y cargar dispositivos
    db.conectar();
    dispositivos = db.cargarDispositivos();
    actualizarLista();
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

void MainWindow::on_pushButton_4_clicked() {  // Agregar
    QString nombre = QInputDialog::getText(this, "Nuevo Dispositivo", "Nombre:");
    QString tipo   = QInputDialog::getText(this, "Nuevo Dispositivo", "Tipo (Luz/Persiana/Sensor):");
    if (!nombre.isEmpty() && !tipo.isEmpty()) {
        Dispositivo* d = new Dispositivo(nombre, tipo);
        dispositivos.append(d);
        db.guardarDispositivo(d);
        actualizarLista();
    }
}

void MainWindow::on_pushButton_clicked() {  // Encender
    int i = ui->listWidget->currentRow();
    if (i >= 0) {
        dispositivos[i]->encender();
        db.actualizarEstado(dispositivos[i]);
        actualizarLista();
    }
}

void MainWindow::on_pushButton_2_clicked() {  // Apagar
    int i = ui->listWidget->currentRow();
    if (i >= 0) {
        dispositivos[i]->apagar();
        db.actualizarEstado(dispositivos[i]);
        actualizarLista();
    }
}

void MainWindow::on_pushButton_3_clicked() {  // Fallo
    int i = ui->listWidget->currentRow();
    if (i >= 0) {
        dispositivos[i]->setFallo();
        db.actualizarEstado(dispositivos[i]);
        actualizarLista();
    }
}
