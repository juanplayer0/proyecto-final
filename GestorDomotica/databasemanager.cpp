#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDateTime>

void DatabaseManager::registrarEvento(QString dispositivo, QString accion) {
    QSqlQuery query;
    query.prepare("INSERT INTO eventos (dispositivo, accion, fecha) VALUES (:d, :a, :f)");
    query.bindValue(":d", dispositivo);
    query.bindValue(":a", accion);
    query.bindValue(":f", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    query.exec();
}

DatabaseManager::DatabaseManager() {}

bool DatabaseManager::conectar() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("domotica.db");

    if (!db.open()) return false;

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS dispositivos ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "nombre TEXT,"
               "tipo TEXT,"
               "estado TEXT)");
    return true;
    query.exec("CREATE TABLE IF NOT EXISTS eventos ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "dispositivo TEXT,"
               "accion TEXT,"
               "fecha TEXT)");
}

void DatabaseManager::guardarDispositivo(Dispositivo* d) {
    QSqlQuery query;
    query.prepare("INSERT INTO dispositivos (nombre, tipo, estado) VALUES (:n, :t, :e)");
    query.bindValue(":n", d->getNombre());
    query.bindValue(":t", d->getTipo());
    query.bindValue(":e", d->getEstado());
    query.exec();
}

QList<Dispositivo*> DatabaseManager::cargarDispositivos() {
    QList<Dispositivo*> lista;
    QSqlQuery query("SELECT nombre, tipo, estado FROM dispositivos");
    while (query.next()) {
        Dispositivo* d = new Dispositivo(query.value(0).toString(), query.value(1).toString());
        QString estado = query.value(2).toString();
        if (estado == "Encendido") d->encender();
        else if (estado == "Fallo") d->setFallo();
        lista.append(d);
    }
    return lista;
}

void DatabaseManager::actualizarEstado(Dispositivo* d) {
    QSqlQuery query;
    query.prepare("UPDATE dispositivos SET estado=:e WHERE nombre=:n");
    query.bindValue(":e", d->getEstado());
    query.bindValue(":n", d->getNombre());
    query.exec();
}
