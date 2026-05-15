/********************************************************************************
** Form generated from reading UI file 'historialdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORIALDIALOG_H
#define UI_HISTORIALDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_HistorialDialog
{
public:
    QTableWidget *tableWidget;
    QPushButton *pushButton;

    void setupUi(QDialog *HistorialDialog)
    {
        if (HistorialDialog->objectName().isEmpty())
            HistorialDialog->setObjectName(QString::fromUtf8("HistorialDialog"));
        HistorialDialog->resize(759, 307);
        tableWidget = new QTableWidget(HistorialDialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(5, 0, 751, 192));
        pushButton = new QPushButton(HistorialDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(340, 230, 80, 23));

        retranslateUi(HistorialDialog);

        QMetaObject::connectSlotsByName(HistorialDialog);
    } // setupUi

    void retranslateUi(QDialog *HistorialDialog)
    {
        HistorialDialog->setWindowTitle(QCoreApplication::translate("HistorialDialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("HistorialDialog", "cerrar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HistorialDialog: public Ui_HistorialDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORIALDIALOG_H
