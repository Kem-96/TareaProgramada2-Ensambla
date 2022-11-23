#pragma once
#include <vector>
#include <string>

struct Color {
	unsigned char r,g,b;
public:
	Color();
	Color(unsigned char r, unsigned char g, unsigned char b);
	void colorcito(unsigned char r, unsigned char g, unsigned char b);
	~Color();
};

class Imagen{
public:
	Imagen(int ancho, int alto);
	~Imagen();
	
	Color getColor(int x, int y);//Toma el color de un pixel.
	void setColor(Color& color, int x, int y);//Pone el color en un pixel.
	
	void Lectura(std::string path);
	void Exportar(std::string path);//Exporta la imagen basicamente.
	std::vector<Color>& getPixeles();
	void setMatrix(std::vector<Color> matriz);
	int getAncho();
	int getAlto();
	
	
private:
	int m_ancho;
	int m_alto;
	std::vector<Color> m_colores;//Basicamente guarda cada pixel en un struct de Color y cada pixel o color lo guarda en un vector, deberia ver como usar todo en un arreglo de char en el que se ingrese a traves de indice*3 y tal...
	
};

/*
https://www.youtube.com/watch?v=vqT5j38bWGg
referencia: https://poesiabinaria.net/2011/06/leyendo-archivos-de-imagen-en-formato-bmp-en-c/
https://solarianprogrammer.com/2018/11/19/cpp-reading-writing-bmp-images/
*/
