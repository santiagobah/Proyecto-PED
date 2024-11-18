#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Archivo
{
	string nombre;
	string tipo;
	int tamano;
};

struct Archivos 
{
	Archivo datos;
	Archivos* siguiente;
};

class Cola
{
public:
	Cola();
	Archivo Extraer();
	void Insertar(string, string, int);
	void Mostrar();
private:
	Archivos* principio, * final, * nodo;
	int contador;
};

