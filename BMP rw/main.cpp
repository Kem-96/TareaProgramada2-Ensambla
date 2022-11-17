#include "imagen.h"
#include <iostream>
#include <string>

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
}