#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include <string>
#include <QFileDialog>
#include <QMessageBox>
#include "imagen.h"
#include <iostream>
#include <string>
#include <vector>


std::vector<Color> colores;
int brillosito = 255;
int iteraciones = 0;
int opt = 0;
std::string path = "";

extern "C" char inicio();
extern "C" char masBrillo();
extern "C" char menosBrillo();
extern "C" char negativo();
extern "C" void brilloAux();
extern "C" void contraste();

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
    Imagen abrido(0, 0);

    abrido.Lectura(path);

    int ancho = abrido.getAncho();
    int alto = abrido.getAlto();

    colores.resize(ancho*alto);
    iteraciones = ((colores.size()*3)/32)+1;
    std::cout << iteraciones << std::endl;

    colores = abrido.getPixeles();

    inicio();

    brilloAux();
    abrido.getPixeles() = colores;
    //abrido.setMatrix(colores);
    abrido.Exportar(path+"-copia.bmp");

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

/*void MainWindow::inicializacion()
{

    abrido.Lectura(path);

    int ancho = abrido.getAncho();
    int alto = abrido.getAlto();

    colores.resize(ancho*alto);
    iteraciones = ((colores.size()*3)/32)+1;
    std::cout << iteraciones << std::endl;

    colores = abrido.getPixeles();
    inicio();
}*/


