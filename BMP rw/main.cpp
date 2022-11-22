#include "imagen.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Color colores;
vector<Color> colores;
int brillosito = 0;

extern "C" char inicio();

int main() {
	int ancho = 271;
	int alto = 271;

	Imagen img(ancho, alto);
	Color rgb = Color();
	for (int y = 0; y < alto; y++) {
		for (int x = 0; x < ancho; x++) {
			rgb.colorcito(x, x+1, x+2);
			img.setColor(rgb, x, y);
		}
	}
	rgb.~Color();
	std::string pat = "prueba.bmp";
	img.Exportar(pat);

	Imagen abrido(0, 0);

	abrido.Lectura(pat);

	char dato[3];
	dato[0] = (abrido.getColor(0, 0)).r;
	dato[1] = (abrido.getColor(0, 0)).g;
	dato[2] = (abrido.getColor(0, 0)).b;
	
	printf("%hhu %hhu %hhu\n", dato[0], dato[1], dato[2]);

	abrido.Exportar("Copia - "+pat);
	
	colores.resize(11);
	
	colores[0] = abrido.getColor(0,0);
	printf("%hhu %hhu %hhu\n", colores[0].r, colores[0].g,colores[0].b);
	colores[1] = abrido.getColor(3,3);
	printf("%hhu %hhu %hhu\n", colores[1].r, colores[1].g,colores[1].b);
	colores[2] = abrido.getColor(0,0);
	colores[3] = abrido.getColor(0,0);
	colores[4] = abrido.getColor(0,0);
	colores[5] = abrido.getColor(0,0);
	colores[6] = abrido.getColor(0,0);
	colores[7] = abrido.getColor(0,0);
	colores[8] = abrido.getColor(0,0);
	colores[9] = abrido.getColor(0,0);
	colores[10] = abrido.getColor(3,3);
	
	inicio();
	
	//cout << "El resultado: \n";
	
	printf("%hhu %hhu %hhu\n", colores[10].r, colores[10].g,colores[10].b);
	
	return 0;
}