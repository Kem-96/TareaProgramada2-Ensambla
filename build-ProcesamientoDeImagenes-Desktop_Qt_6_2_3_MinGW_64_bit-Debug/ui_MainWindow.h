/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *BotonAjusteBrillo;
    QPushButton *BotonContraste;
    QPushButton *BotonNegativo;
    QPushButton *BotonEscalado;
    QPushButton *BotonEspejado;
    QLabel *label_imagenOriginal;
    QLabel *label_ImagenFiltro;
    QPushButton *BotonSalir;
    QLabel *label_Titulo;
    QLabel *ImagenOriginal;
    QLabel *label_tiposFiltros;
    QLabel *imagenFiltro;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(773, 507);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        BotonAjusteBrillo = new QPushButton(centralwidget);
        BotonAjusteBrillo->setObjectName(QString::fromUtf8("BotonAjusteBrillo"));
        BotonAjusteBrillo->setGeometry(QRect(620, 170, 91, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sitka")});
        font.setPointSize(10);
        font.setBold(false);
        font.setUnderline(false);
        BotonAjusteBrillo->setFont(font);
        BotonContraste = new QPushButton(centralwidget);
        BotonContraste->setObjectName(QString::fromUtf8("BotonContraste"));
        BotonContraste->setGeometry(QRect(620, 210, 91, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sitka")});
        font1.setPointSize(10);
        BotonContraste->setFont(font1);
        BotonContraste->setMouseTracking(true);
        BotonNegativo = new QPushButton(centralwidget);
        BotonNegativo->setObjectName(QString::fromUtf8("BotonNegativo"));
        BotonNegativo->setGeometry(QRect(620, 250, 91, 31));
        BotonNegativo->setFont(font1);
        BotonEscalado = new QPushButton(centralwidget);
        BotonEscalado->setObjectName(QString::fromUtf8("BotonEscalado"));
        BotonEscalado->setGeometry(QRect(620, 290, 93, 29));
        BotonEscalado->setFont(font1);
        BotonEspejado = new QPushButton(centralwidget);
        BotonEspejado->setObjectName(QString::fromUtf8("BotonEspejado"));
        BotonEspejado->setGeometry(QRect(620, 330, 93, 29));
        BotonEspejado->setFont(font1);
        label_imagenOriginal = new QLabel(centralwidget);
        label_imagenOriginal->setObjectName(QString::fromUtf8("label_imagenOriginal"));
        label_imagenOriginal->setGeometry(QRect(60, 110, 131, 21));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Sitka")});
        font2.setPointSize(12);
        label_imagenOriginal->setFont(font2);
        label_ImagenFiltro = new QLabel(centralwidget);
        label_ImagenFiltro->setObjectName(QString::fromUtf8("label_ImagenFiltro"));
        label_ImagenFiltro->setGeometry(QRect(350, 110, 151, 21));
        label_ImagenFiltro->setFont(font2);
        BotonSalir = new QPushButton(centralwidget);
        BotonSalir->setObjectName(QString::fromUtf8("BotonSalir"));
        BotonSalir->setGeometry(QRect(620, 370, 93, 29));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Sitka")});
        font3.setPointSize(10);
        font3.setBold(true);
        BotonSalir->setFont(font3);
        label_Titulo = new QLabel(centralwidget);
        label_Titulo->setObjectName(QString::fromUtf8("label_Titulo"));
        label_Titulo->setGeometry(QRect(180, 30, 361, 41));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Sitka Banner")});
        font4.setPointSize(16);
        font4.setBold(true);
        font4.setItalic(true);
        label_Titulo->setFont(font4);
        ImagenOriginal = new QLabel(centralwidget);
        ImagenOriginal->setObjectName(QString::fromUtf8("ImagenOriginal"));
        ImagenOriginal->setGeometry(QRect(30, 160, 271, 271));
        ImagenOriginal->setFrameShape(QFrame::Box);
        label_tiposFiltros = new QLabel(centralwidget);
        label_tiposFiltros->setObjectName(QString::fromUtf8("label_tiposFiltros"));
        label_tiposFiltros->setGeometry(QRect(590, 110, 141, 21));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Sitka Display")});
        font5.setPointSize(12);
        font5.setBold(true);
        label_tiposFiltros->setFont(font5);
        imagenFiltro = new QLabel(centralwidget);
        imagenFiltro->setObjectName(QString::fromUtf8("imagenFiltro"));
        imagenFiltro->setGeometry(QRect(330, 160, 271, 271));
        imagenFiltro->setFrameShape(QFrame::Box);
        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 773, 26));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        BotonAjusteBrillo->setText(QCoreApplication::translate("MainWindow", "Ajuste Brillo", nullptr));
        BotonContraste->setText(QCoreApplication::translate("MainWindow", "Contraste", nullptr));
        BotonNegativo->setText(QCoreApplication::translate("MainWindow", "Negativo", nullptr));
        BotonEscalado->setText(QCoreApplication::translate("MainWindow", "Escalado x2", nullptr));
        BotonEspejado->setText(QCoreApplication::translate("MainWindow", "Espejado", nullptr));
        label_imagenOriginal->setText(QCoreApplication::translate("MainWindow", "Imagen Original", nullptr));
        label_ImagenFiltro->setText(QCoreApplication::translate("MainWindow", "Imagen con Filtro", nullptr));
        BotonSalir->setText(QCoreApplication::translate("MainWindow", "Salir", nullptr));
        label_Titulo->setText(QCoreApplication::translate("MainWindow", "Procesador de imagenes", nullptr));
        ImagenOriginal->setText(QString());
        label_tiposFiltros->setText(QCoreApplication::translate("MainWindow", "Tipos de Filtros", nullptr));
        imagenFiltro->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
