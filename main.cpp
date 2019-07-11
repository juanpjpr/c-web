#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

class Plantilla {
private:
	char* dir;

public:
	Plantilla(string d) {
		dir = new char[d.size() + 1];
		strcpy(dir, d.c_str());
	}

	void setDir(string d) {
		dir = new char[d.size() + 1];
		strcpy(dir, d.c_str());
	}

	char* getDir() {
		return dir;
	}

	char* getContenido(string d) {
		char* path = dir;
		string Dir = path;
		Dir.append(d);
		path = new char[Dir.size() + 1];
		strcpy(path, Dir.c_str());

		char* contenido;

		//abrir archivo
		FILE* f = fopen(path, "rb");

		//posiciono al final
		fseek (f, 0, SEEK_END);

		//creo array con el tamaño del contenido
		int len = ftell(f);

		contenido = new char[ftell(f) + 1];

		//posiciono comienzo
		fseek (f, 0, SEEK_SET);

		//leo
		fread(contenido, sizeof(char), len, f);

		//cierro
		fclose(f);

		return contenido;
	}

	int getTamContenido(string d) {
		char* path = dir;
		string Dir = path;
		Dir.append(d);
		path = new char[Dir.size() + 1];
		strcpy(path, Dir.c_str());

		char* contenido;

		//abrir archivo
		FILE* f = fopen(path, "rb");

		//posiciono al final
		fseek (f, 0, SEEK_END);

		//creo array con el tamaño del contenido
		int len = ftell(f);

		//cierro
		fclose(f);

		return len;
	}


};

int main() {

	Plantilla plantilla("C:/Users/Juan/Desktop/Cweb/Plantillas/");


	FILE* f = fopen("index.html", "w+b");

	fwrite(plantilla.getContenido("header.html"), sizeof(char), plantilla.getTamContenido("header.html"), f);

	fwrite(plantilla.getContenido("navbar.html"), sizeof(char), plantilla.getTamContenido("navbar.html"), f);

	fwrite(plantilla.getContenido("form.html"), sizeof(char), plantilla.getTamContenido("form.html"), f);

	fwrite(plantilla.getContenido("booter.html"), sizeof(char), plantilla.getTamContenido("booter.html"), f);

	fclose(f);

}