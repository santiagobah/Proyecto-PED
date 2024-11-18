#include "Cola.h"
Cola::Cola()
{
	principio = final = NULL;
	contador = 1;
}
Archivo Cola::Extraer()
{
	Archivo extraido;
	if (principio == NULL)
	{
		return extraido;
	}
	nodo = principio;
	extraido.nombre = nodo->datos.nombre;
	extraido.tipo = nodo->datos.tipo;
	extraido.tamano = nodo->datos.tamano;
	principio = nodo->siguiente;
	if (principio == NULL)
	{
		final = NULL;
	}
	delete nodo;
	return extraido;
}
void Cola::Insertar(string Nombre, string tipo, int tamano)
{
	nodo = new Archivos;
	nodo->datos.nombre = Nombre;
	nodo->datos.tipo = tipo;
	nodo->datos.tamano = tamano;
	nodo->siguiente = NULL;
	if (principio == NULL)
	{
		principio = nodo;
	}
	if (final != NULL)
	{
		final->siguiente = nodo;
	}
	final = nodo;
}
void Cola::Mostrar()
{
	cout << "Descagas Pendientes" << endl;
	if (principio == NULL) {
		cout << "\t\nNo hay ninguna descarga pendiente actualmente" << endl;
		return;
	}
	nodo = principio;
	contador = 1;
	while (nodo != NULL)
	{
		cout << "\t" << contador << ". " << nodo->datos.nombre << "." << nodo->datos.tipo << "\t" << nodo->datos.tamano << " Mbts";
		cout << endl << endl;
		contador++;
		nodo = nodo->siguiente;
	}
}