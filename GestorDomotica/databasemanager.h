#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QList>
#include "dispositivo.h"

class DatabaseManager {
public:
    DatabaseManager();
    bool conectar();
    void guardarDispositivo(Dispositivo* d);
    QList<Dispositivo*> cargarDispositivos();
    void actualizarEstado(Dispositivo* d);
    void registrarEvento(QString dispositivo, QString accion);

private:
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
