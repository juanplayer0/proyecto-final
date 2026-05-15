#include "dispositivo.h"

Dispositivo::Dispositivo(QString nombre, QString tipo) {
    this->nombre = nombre;
    this->tipo = tipo;
    this->estado = "Apagado"; // Estado inicial
}

void Dispositivo::encender() {
    estado = "Encendido";
}

void Dispositivo::apagar() {
    estado = "Apagado";
}

void Dispositivo::setFallo() {
    estado = "Fallo";
}

QString Dispositivo::getNombre() { return nombre; }
QString Dispositivo::getTipo()   { return tipo;   }
QString Dispositivo::getEstado() { return estado; }
