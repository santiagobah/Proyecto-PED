#include "Pila.h"

Pila::Pila()
{
	tope = NULL;
}

string Pila::consultar()
{
	string url;
	if (tope == NULL) {
		return "-";
	}
	url = tope->dato;
	return url;
}

void Pila::mostrar()
{
	nodo = tope;
	if (nodo == NULL)
	{
		cout << "No hay nada en el historial para mostrar (pila vacía)" << endl;
		return;
	}
	while (nodo != NULL)
	{
		cout << "\t\t" << nodo->dato;
		if (nodo == tope)
		{
			cout << "\t--->Tope";
		}
		cout << endl;
		nodo = nodo->anterior;
	}
}

void Pila::insertar(string nuevo_URL)
{
	nodo = new URL;
	nodo->dato = nuevo_URL;
	nodo->anterior = tope;
	tope = nodo;
}

string Pila::extraer()
{
	if (tope == NULL) {
		return "-";
	}
	URL* extraido;
	string url_extraido;
	extraido = tope;
	tope = tope->anterior;
	url_extraido = extraido->dato;
	delete extraido;
	return url_extraido;
}