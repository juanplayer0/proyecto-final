#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H

#include <QString>

class Dispositivo {
public:
    // Constructor
    Dispositivo(QString nombre, QString tipo);

    // Métodos
    void encender();
    void apagar();
    void setFallo();

    // Getters
    QString getNombre();
    QString getTipo();
    QString getEstado();
    void registrarEvento(QString dispositivo, QString accion);

private:
    QString nombre;
    QString tipo;
    QString estado; // "Encendido", "Apagado", "Fallo"
};

#endif // DISPOSITIVO_H
