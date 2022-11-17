#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString url = R"(C:\Users\Invita2\Desktop\image2.bmp)";
    QPixmap img(url);
    ui->ImagenOriginal->setPixmap(img);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_BotonAjusteBrillo_clicked()
{
    QString url = R"(C:\Users\Invita2\Desktop\image2.bmp)";
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

