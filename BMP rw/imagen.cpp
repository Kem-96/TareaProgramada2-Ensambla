#include "imagen.h"

#include <iostream>
#include <fstream>
#include <vector>

Color::Color() : r(0), g(0), b(0) {}

Color::Color(unsigned char r, unsigned char g, unsigned char b): r(r), g(g), b(g) {}

void Color::colorcito(unsigned char rojo, unsigned char verde, unsigned char azul){
	r = rojo;
	g = verde;
	b = azul;
}

Color::~Color(){}

Imagen::Imagen(int w, int h): m_ancho(w), m_alto(h), m_colores(std::vector<Color>(w * h)) {}

Imagen::~Imagen(){}

Color Imagen::getColor(int x, int y){
	return m_colores[y * m_ancho + x];
}

void Imagen::setColor(Color& color, int x, int y){
	m_colores[y * m_ancho + x].r = color.r;
	m_colores[y * m_ancho + x].g = color.g;
	m_colores[y * m_ancho + x].b = color.b;
}

void Imagen::Lectura(std::string path){
	std::ifstream ori;
	ori.open(path, std::ios::in | std::ios::binary);

	if (!ori.is_open()) {
		std::cout << "Error abriendo el archivo...\n";
		return;
	}

	const int fHeaderSize = 14;
	const int iHeaderSize = 40;

	unsigned char fHeader[fHeaderSize];
	ori.read(reinterpret_cast<char*>(fHeader), fHeaderSize);

	if (fHeader[0] != 'B' || fHeader[1] != 'M') {
		std::cout << "El archivo no se puede leer...\n";
		ori.close();
		return;
	}

	unsigned char iHeader[iHeaderSize];
	ori.read(reinterpret_cast<char*>(iHeader), iHeaderSize);

	int fileSize = fHeader[2] + (fHeader[3] << 8) + (fHeader[4] << 16) + (fHeader[5] << 24);
	m_ancho = iHeader[4] + (iHeader[5] << 8) + (iHeader[6] << 16) + (iHeader[7] << 24);
	m_alto = iHeader[8] + (iHeader[9] << 8) + (iHeader[10] << 16) + (iHeader[11] << 24);

	m_colores.resize(m_ancho * m_alto);

	const int paddingAmmo = ((4 - (m_ancho * 3) % 4) % 4);

	for (int y = 0; y < m_alto; y++) {
		for (int x = 0; x < m_ancho; x++) {
			unsigned char color[3];
			ori.read(reinterpret_cast<char*>(color), 3);

			m_colores[y * m_ancho + x].r = static_cast<unsigned char>(color[2]);
			m_colores[y * m_ancho + x].g = static_cast<unsigned char>(color[1]);
			m_colores[y * m_ancho + x].b = static_cast<unsigned char>(color[0]);
		}
		ori.ignore(paddingAmmo);
	}
	ori.close();

	std::cout << "Archivo leido...\n";
}

void Imagen::Exportar(std::string path){
	std::ofstream arc;
	arc.open(path, std::ios::out | std::ios::binary);
	
	if (!arc.is_open()){
		std::cout << "El archivo no se ha abierto\n";
		return;
	}
	
	unsigned char bmpPad[3] = {0,0,0};
	const int paddingAmmo = ((4 - (m_ancho * 3) % 4) % 4);
	
	const int fHeaderSize = 14;
	const int iHeaderSize = 40;
	int fileSize = fHeaderSize + iHeaderSize + m_ancho * m_alto * 3 + paddingAmmo * m_alto;	

	unsigned char fHeader[fHeaderSize];

	//Tipo de archivo.
	fHeader[0] = 'B';
	fHeader[1] = 'M';

	//Tamaño del archivo.
	fHeader[2] = fileSize;
	fHeader[3] = fileSize >> 8;
	fHeader[4] = fileSize >> 16;
	fHeader[5] = fileSize >> 24;

	//Reservados.
	fHeader[6] = 0;
	fHeader[7] = 0;

	fHeader[8] = 0;
	fHeader[9] = 0;

	//Offset de los pixeles.
	fHeader[10] = fHeaderSize + iHeaderSize;
	fHeader[11] = 0;
	fHeader[12] = 0;
	fHeader[13] = 0;

	unsigned char iHeader[iHeaderSize];
	
	//Tamaño del header.
	iHeader[0] = iHeaderSize;
	iHeader[1] = 0;
	iHeader[2] = 0;
	iHeader[3] = 0;

	//Ancho Imagen.
	iHeader[4] = m_ancho;
	iHeader[5] = m_ancho >> 8;
	iHeader[6] = m_ancho >> 16;
	iHeader[7] = m_ancho >> 24;

	//Alto Imagen.
	iHeader[8] = m_alto;
	iHeader[9] = m_alto >> 8;
	iHeader[10] = m_alto >> 16;
	iHeader[11] = m_alto >> 24;

	//Planes.
	iHeader[12] = 1;
	iHeader[13] = 0;

	//Bits porpixel (RGB).
	iHeader[14] = 24;
	iHeader[15] = 0;

	//Compresion.
	iHeader[16] = 0;
	iHeader[17] = 0;
	iHeader[18] = 0;
	iHeader[19] = 0;

	//Tamaño de la imagen.
	iHeader[20] = 0;
	iHeader[21] = 0;
	iHeader[22] = 0;
	iHeader[23] = 0;

	//Pixeles en x por metro.
	iHeader[24] = 0;
	iHeader[25] = 0;
	iHeader[26] = 0;
	iHeader[27] = 0;
	//Pixeles en y por metro.
	iHeader[28] = 0;
	iHeader[29] = 0;
	iHeader[30] = 0;
	iHeader[31] = 0;

	//Paleta de colores.
	iHeader[32] = 0;
	iHeader[33] = 0;
	iHeader[34] = 0;
	iHeader[35] = 0;

	//Colores importantes, si es 0, importan todos...
	iHeader[36] = 0;
	iHeader[37] = 0;
	iHeader[38] = 0;
	iHeader[39] = 0;

	arc.write(reinterpret_cast<char*>(fHeader), fHeaderSize);
	arc.write(reinterpret_cast<char*>(iHeader), iHeaderSize);

	for (int y = 0; y < m_alto; y++) {
		for (int x = 0; x < m_ancho; x++) {
			unsigned char r = getColor(x, y).r;
			unsigned char g = getColor(x, y).g;
			unsigned char b = getColor(x, y).b;

			unsigned char color[] = { b, g, r };

			arc.write(reinterpret_cast<char*>(color), 3);
		}

		arc.write(reinterpret_cast<char*>(bmpPad), paddingAmmo);

	}

	arc.close();

	std::cout << "Archivo creado\n";
}

std::vector<Color>& Imagen::getPixeles(){
	return this->m_colores;
}

void Imagen::setMatrix(std::vector<Color> matriz){
	this->m_colores = matriz;
}

int Imagen::getAncho(){
	return this->m_ancho;
}

int Imagen::getAlto(){
	return this->m_alto;
}