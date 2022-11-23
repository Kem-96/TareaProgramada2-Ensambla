#include "imagen.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<Color> colores;
int brillosito = 255;
int iteraciones = 0;
int opt = 0;

extern "C" char inicio();
extern "C" char masBrillo();
extern "C" char menosBrillo();
extern "C" char negativo();
extern "C" void brilloAux();
extern "C" void contraste();

int main() {
	/*Dimensiones de la imagen.
	int ancho = 271;
	int alto = 271;

	//Se crea la imagen y se llenan los colores.
	Imagen img(ancho, alto);
	Color rgb = Color();
	for (int y = 0; y < alto; y++) {
		for (int x = 0; x < ancho; x++) {
			rgb.colorcito(x+5, x+10, x+15);
			img.setColor(rgb, x, y);
		}
	}
	rgb.~Color();
	*/
	//Se le indica el nombre de la imagen por abrir.
	std::string pat = "prueba.bmp";
	//img.Exportar(pat);

	Imagen abrido(0, 0);

	abrido.Lectura(pat);
	
	int ancho = abrido.getAncho();
	int alto = abrido.getAlto();
	
	colores.resize(ancho*alto);
	iteraciones = ((colores.size()*3)/32)+1;
	cout << iteraciones << endl;
	
	colores = abrido.getPixeles();
	/*
	cout << "Lo que sigue es el vector dela imagen: \n";
	for(int i = 0; i < abrido.getPixeles().size(); i++){
		printf("%hhu %hhu %hhu\n", abrido.getPixeles()[i].r, abrido.getPixeles()[i].g,abrido.getPixeles()[i].b);
	}*/
	
	inicio();
	brilloAux();
	abrido.getPixeles() = colores;
	//abrido.setMatrix(colores);
	abrido.Exportar("Copia - "+pat);
	
	//colores = abrido.getPixeles();
	
	/*
	cout << "Lo que sigue es el vector dela imagen editada: \n";
	for(int i = 0; i < abrido.getPixeles().size(); i++){
		printf("%hhu %hhu %hhu\n", abrido.getPixeles()[i].r, abrido.getPixeles()[i].g,abrido.getPixeles()[i].b);
	}*/
	int factor = 259*(255+50)/255*(259-50);
	cout << factor << endl;
	return 0;
}