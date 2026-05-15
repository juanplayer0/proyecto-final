#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "dispositivo.h"
#include "databasemanager.h"
#include "historialdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @class MainWindow
 * @brief Ventana principal de la aplicación.
 *
 * Muestra la lista de dispositivos y permite agregar
 * nuevos, cambiar su estado y ver el historial de eventos.
 */
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    /**
     * @brief Constructor de la ventana principal.
     * @param parent Widget padre, por defecto es nullptr.
     */
    MainWindow(QWidget *parent = nullptr);

    /** @brief Destructor. Libera la memoria de la interfaz. */
    ~MainWindow();

private slots:
    /** @brief Enciende el dispositivo seleccionado en la lista. */
    void on_pushButton_clicked();

    /** @brief Apaga el dispositivo seleccionado en la lista. */
    void on_pushButton_2_clicked();

    /** @brief Marca como fallo el dispositivo seleccionado. */
    void on_pushButton_3_clicked();

    /** @brief Abre el diálogo para agregar un nuevo dispositivo. */
    void on_pushButton_4_clicked();

    /** @brief Abre el diálogo con el historial de eventos. */
    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;                  ///< Interfaz gráfica generada por Qt Designer
    QList<Dispositivo*> dispositivos;    ///< Lista de dispositivos cargados
    DatabaseManager db;                  ///< Gestor de base de datos

    /** @brief Refresca la lista visual con el estado actual de los dispositivos. */
    void actualizarLista();
};

#endif // MAINWINDOW_H
