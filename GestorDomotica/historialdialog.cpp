#include "historialdialog.h"
#include "ui_historialdialog.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>

HistorialDialog::HistorialDialog(DatabaseManager* db, QWidget *parent)
    : QDialog(parent), ui(new Ui::HistorialDialog) {
    ui->setupUi(this);
    setWindowTitle("Historial de Eventos");

    // Configurar tabla
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels({"Dispositivo", "Acción", "Fecha"});
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    // Cargar eventos
    QSqlQuery query(QSqlDatabase::database());
    query.exec("SELECT dispositivo, accion, fecha FROM eventos ORDER BY id DESC");
    int fila = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(fila);
        ui->tableWidget->setItem(fila, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(fila, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(fila, 2, new QTableWidgetItem(query.value(2).toString()));
        fila++;
    }
}

HistorialDialog::~HistorialDialog() {
    delete ui;
}

void HistorialDialog::on_pushButton_clicked() {
    close();
}
