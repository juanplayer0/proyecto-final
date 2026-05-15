#ifndef HISTORIALDIALOG_H
#define HISTORIALDIALOG_H

#include <QDialog>
#include "databasemanager.h"

namespace Ui { class HistorialDialog; }

/**
 * @class HistorialDialog
 * @brief Ventana que muestra el historial de eventos registrados.
 *
 * Consulta la tabla de eventos en la base de datos y los
 * presenta en una tabla ordenados del más reciente al más antiguo.
 */
class HistorialDialog : public QDialog {
    Q_OBJECT

public:
    /**
     * @brief Constructor del diálogo de historial.
     * @param db Puntero al gestor de base de datos activo.
     * @param parent Widget padre, por defecto es nullptr.
     */
    HistorialDialog(DatabaseManager* db, QWidget *parent = nullptr);

    /** @brief Destructor. Libera la memoria de la interfaz. */
    ~HistorialDialog();

private slots:
    /** @brief Cierra el diálogo al presionar el botón Cerrar. */
    void on_pushButton_clicked();

private:
    Ui::HistorialDialog *ui; ///< Interfaz gráfica del diálogo
};

#endif // HISTORIALDIALOG_H
