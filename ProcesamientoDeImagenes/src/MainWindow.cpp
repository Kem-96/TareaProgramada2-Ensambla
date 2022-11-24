#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include <string>
#include <QFileDialog>
#include <QMessageBox>
#include "imagen.hpp"
#include <iostream>
#include <string>
#include <vector>

std::vector<Color> colores;
std::vector<Color> escalado;
int brillosito = 90;
int iteraciones = 0;
Imagen abrido(0, 0);

extern "C" char inicio();
extern "C" char masBrilloAux();
extern "C" char menosBrilloAux();
extern "C" char negativo();
extern "C" char negativoAux();
extern "C" void brilloAux();
extern "C" void contraste();
extern "C" void escaladoAux();

std::string path = "";
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
    //Imagen abrido(0, 0);
    inicializacion();


    masBrilloAux();


    abrido.getPixeles() = colores;

    abrido.Exportar(path + "-copia.bmp");

    QPixmap img(QString::fromStdString(path+"-copia.bmp"));
    ui->imagenFiltro->setScaledContents(true);
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
    path = nombreArchivo.toStdString();
    QString dato = nombreArchivo;
    QString url(dato);
    QPixmap img(url);
    ui->ImagenOriginal->setScaledContents(true);
    ui->ImagenOriginal->setPixmap(img);

    std::cerr << "hola" <<std::endl;
}

void MainWindow::inicializacion()
{

    abrido.Lectura(path);

    int ancho = abrido.getAncho();
    int alto = abrido.getAlto();

    colores.resize(ancho*alto);
    iteraciones = ((colores.size()*3)/32);
    std::cout << iteraciones << std::endl;

    colores = abrido.getPixeles();
    inicio();
}



void MainWindow::on_BotonNegativo_clicked()
{
    inicializacion();

    negativoAux();

    abrido.getPixeles() = colores;

    abrido.Exportar(path + "-copia.bmp");

    QPixmap img(QString::fromStdString(path+"-copia.bmp"));
    ui->imagenFiltro->setScaledContents(true);
    ui->imagenFiltro->setPixmap(img);

    std::cerr << "hola" <<std::endl;
}


void MainWindow::on_BotonEscalado_clicked()
{
    inicializacion();

    escalado.resize(abrido.getAncho()* abrido.getAlto()*4);

    //escaladoAux();

    abrido.getPixeles() = colores;

    abrido.Exportar(path + "-copia.bmp");

}


void MainWindow::on_Button_Disminucionbrillo_clicked()
{
    inicializacion();

    menosBrilloAux();


    abrido.getPixeles() = colores;

    abrido.Exportar(path + "-copia.bmp");

    QPixmap img(QString::fromStdString(path+"-copia.bmp"));
    ui->imagenFiltro->setScaledContents(true);
    ui->imagenFiltro->setPixmap(img);

    std::cerr << "hola" <<std::endl;

}

