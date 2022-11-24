/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbrir_imagen;
    QAction *actionSalir;
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
    QPushButton *buton_elegirImagen;
    QSlider *horizontalSlider;
    QMenuBar *menuBar;
    QMenu *menuArchivo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(909, 512);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(240, 240, 240, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        MainWindow->setPalette(palette);
        actionAbrir_imagen = new QAction(MainWindow);
        actionAbrir_imagen->setObjectName("actionAbrir_imagen");
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName("actionSalir");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        BotonAjusteBrillo = new QPushButton(centralwidget);
        BotonAjusteBrillo->setObjectName("BotonAjusteBrillo");
        BotonAjusteBrillo->setGeometry(QRect(640, 180, 91, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sitka")});
        font.setPointSize(10);
        font.setBold(false);
        font.setUnderline(false);
        BotonAjusteBrillo->setFont(font);
        BotonContraste = new QPushButton(centralwidget);
        BotonContraste->setObjectName("BotonContraste");
        BotonContraste->setGeometry(QRect(640, 220, 91, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sitka")});
        font1.setPointSize(10);
        BotonContraste->setFont(font1);
        BotonContraste->setMouseTracking(true);
        BotonNegativo = new QPushButton(centralwidget);
        BotonNegativo->setObjectName("BotonNegativo");
        BotonNegativo->setGeometry(QRect(640, 260, 91, 31));
        BotonNegativo->setFont(font1);
        BotonEscalado = new QPushButton(centralwidget);
        BotonEscalado->setObjectName("BotonEscalado");
        BotonEscalado->setGeometry(QRect(640, 300, 93, 29));
        BotonEscalado->setFont(font1);
        BotonEspejado = new QPushButton(centralwidget);
        BotonEspejado->setObjectName("BotonEspejado");
        BotonEspejado->setGeometry(QRect(640, 340, 93, 29));
        BotonEspejado->setFont(font1);
        label_imagenOriginal = new QLabel(centralwidget);
        label_imagenOriginal->setObjectName("label_imagenOriginal");
        label_imagenOriginal->setGeometry(QRect(90, 90, 131, 21));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Sitka")});
        font2.setPointSize(12);
        label_imagenOriginal->setFont(font2);
        label_ImagenFiltro = new QLabel(centralwidget);
        label_ImagenFiltro->setObjectName("label_ImagenFiltro");
        label_ImagenFiltro->setGeometry(QRect(380, 90, 151, 21));
        label_ImagenFiltro->setFont(font2);
        BotonSalir = new QPushButton(centralwidget);
        BotonSalir->setObjectName("BotonSalir");
        BotonSalir->setGeometry(QRect(640, 380, 93, 29));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Sitka")});
        font3.setPointSize(10);
        font3.setBold(true);
        BotonSalir->setFont(font3);
        label_Titulo = new QLabel(centralwidget);
        label_Titulo->setObjectName("label_Titulo");
        label_Titulo->setGeometry(QRect(200, 30, 261, 41));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Sitka Banner")});
        font4.setPointSize(16);
        font4.setBold(true);
        font4.setItalic(true);
        label_Titulo->setFont(font4);
        ImagenOriginal = new QLabel(centralwidget);
        ImagenOriginal->setObjectName("ImagenOriginal");
        ImagenOriginal->setGeometry(QRect(30, 140, 271, 271));
        ImagenOriginal->setFrameShape(QFrame::StyledPanel);
        label_tiposFiltros = new QLabel(centralwidget);
        label_tiposFiltros->setObjectName("label_tiposFiltros");
        label_tiposFiltros->setGeometry(QRect(620, 90, 141, 21));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Sitka Display")});
        font5.setPointSize(12);
        font5.setBold(true);
        label_tiposFiltros->setFont(font5);
        imagenFiltro = new QLabel(centralwidget);
        imagenFiltro->setObjectName("imagenFiltro");
        imagenFiltro->setGeometry(QRect(320, 140, 271, 271));
        imagenFiltro->setFrameShape(QFrame::StyledPanel);
        buton_elegirImagen = new QPushButton(centralwidget);
        buton_elegirImagen->setObjectName("buton_elegirImagen");
        buton_elegirImagen->setGeometry(QRect(630, 140, 111, 31));
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(750, 190, 91, 20));
        horizontalSlider->setOrientation(Qt::Horizontal);
        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 909, 26));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName("menuArchivo");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuArchivo->addAction(actionAbrir_imagen);
        menuArchivo->addAction(actionSalir);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Procesador de imagenes", nullptr));
        actionAbrir_imagen->setText(QCoreApplication::translate("MainWindow", "Abrir imagen...", nullptr));
        actionSalir->setText(QCoreApplication::translate("MainWindow", "Salir", nullptr));
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
        buton_elegirImagen->setText(QCoreApplication::translate("MainWindow", "Elegir Imagen", nullptr));
        menuArchivo->setTitle(QCoreApplication::translate("MainWindow", "Archivo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
