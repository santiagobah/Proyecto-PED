#pragma once
#include <iostream>
#include <string>


using namespace std;

struct URL {

	string dato;
	URL* anterior;

};

class Pila
{
public:
    
	Pila();
	string consultar();
	void mostrar();
	void insertar(string);
	string extraer();

private:

	URL* nodo, * tope;

};
