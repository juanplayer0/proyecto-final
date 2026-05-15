#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H

#include <QString>

/**
 * @class Dispositivo
 * @brief Clase para manejar un dispositivo domótico.
 *
 * Guarda la información básica de cada dispositivo:
 * cómo se llama, qué tipo es y en qué estado está.
 */
class Dispositivo {
public:
    /**
     * @brief Crea un dispositivo con nombre y tipo definidos.
     * @param nombre Nombre que identifica al dispositivo.
     * @param tipo Tipo de dispositivo, por ejemplo Luz, Persiana o Sensor.
     */
    Dispositivo(QString nombre, QString tipo);

    /** @brief Pone el dispositivo en estado Encendido. */
    void encender();

    /** @brief Pone el dispositivo en estado Apagado. */
    void apagar();

    /** @brief Marca el dispositivo como en Fallo. */
    void setFallo();

    /** @brief Devuelve el nombre del dispositivo. */
    QString getNombre();

    /** @brief Devuelve el tipo del dispositivo. */
    QString getTipo();

    /** @brief Devuelve el estado actual del dispositivo. */
    QString getEstado();

private:
    QString nombre; ///< Nombre del dispositivo
    QString tipo;   ///< Tipo: Luz, Persiana o Sensor
    QString estado; ///< Estado actual del dispositivo
};

#endif // DISPOSITIVO_H
