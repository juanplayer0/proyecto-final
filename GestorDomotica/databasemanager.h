#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QList>
#include "dispositivo.h"

/**
 * @class DatabaseManager
 * @brief Se encarga de todo lo relacionado con la base de datos.
 *
 * Crea las tablas si no existen, guarda dispositivos,
 * los carga al iniciar y registra cada cambio de estado.
 */
class DatabaseManager {
public:
    /** @brief Constructor por defecto. */
    DatabaseManager();

    /**
     * @brief Abre la base de datos y crea las tablas si es necesario.
     * @return true si la conexión fue exitosa, false si falló.
     */
    bool conectar();

    /**
     * @brief Guarda un dispositivo nuevo en la base de datos.
     * @param d Puntero al dispositivo que se va a guardar.
     */
    void guardarDispositivo(Dispositivo* d);

    /**
     * @brief Carga todos los dispositivos guardados.
     * @return Lista con todos los dispositivos almacenados.
     */
    QList<Dispositivo*> cargarDispositivos();

    /**
     * @brief Actualiza el estado de un dispositivo en la base de datos.
     * @param d Puntero al dispositivo con el estado actualizado.
     */
    void actualizarEstado(Dispositivo* d);

    /**
     * @brief Guarda un evento en la tabla de historial.
     * @param dispositivo Nombre del dispositivo que generó el evento.
     * @param accion Acción realizada: Encendido, Apagado o Fallo.
     */
    void registrarEvento(QString dispositivo, QString accion);

private:
    QSqlDatabase db; ///< Conexión a la base de datos SQLite3
};

#endif // DATABASEMANAGER_H
