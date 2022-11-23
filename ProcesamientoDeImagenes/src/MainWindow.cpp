#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include <iostream>
#include <string>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString url = R"(..\BMP rw\prueba.bmp)";
    QPixmap img(url);
    ui->ImagenOriginal->setPixmap(img);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BotonAjusteBrillo_clicked()
{    
    std::string dato = "C:/Users/c04813/Downloads/TareaProgramada2-Ensambla-main/TareaProgramada2-Ensambla-main/BMP rw/Copia - prueba.bmp";
    //QString::fromStdString(dato);
    QString url(dato.c_str());
    QPixmap img(url);
    ui->imagenFiltro->setPixmap(img);
    std::cerr << "hola" <<std::endl;
}


void MainWindow::on_BotonSalir_clicked()
{
    ui->imagenFiltro->clear();
    ui->ImagenOriginal->clear();
    std::cerr << "hola" <<std::endl;
}


void MainWindow::on_buton_elegirImagen_clicked()
{
    QString nombreArchivo = QFileDialog::getOpenFileName(this, tr("Abrir imagen"), "C://", "Image File(*.bmp)");
    QString dato = nombreArchivo;
    QString url(dato);
    QPixmap img(url);
    ui->ImagenOriginal->setScaledContents(true);
    ui->ImagenOriginal->setPixmap(img);
    std::cerr << "hola" <<std::endl;
}

