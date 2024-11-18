#include "Pila.h"
#include"Cola.h"

int main() {
	Pila Historial_de_navegacion;
	Cola Descargas;
	int opc, tamano;
	string nombreArchivo, tipoArchivo, nueva_pagina, pagina_anterior, pagina_actual;
	//'pagina_actual' se tiene que ir actualizando conforme el usuario se vaya moviendo entre páginas
	Archivo Datos;

	cout << "----------BIENVENIDO AL SISTEMA DE NAVEGACIÓN WEB, STELLA----------" << endl;
	do
	{
		cout << endl;
		cout << "¿Qué desea hacer?" << endl;
		cout << endl;
		cout << "1. Visitar nueva página\t\t2. Retroceder en el historial\t\t3. Ver historial de búsqueda completo\t\t 4. Ver pestaña actual\t\t";
		cout << "5. Abrir pestaña\t\t 6. Cerrar pestaña\t\t 7. Ver todas las pestañas abiertas\t\t 8. Agregar una decarga\t\t 9. Iniciar descarga\t\t 10. Mostrar Descargas pendientes\t\t 11. Salir " << endl;
		cin >> opc;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			opc = -1;
		}
		cout << endl;
		switch (opc)
		{
		case 1:
			cout << "BUSCAR (Nombre de la página que desea buscar): " << endl;
			cin >> nueva_pagina;
			Historial_de_navegacion.insertar(nueva_pagina);
			pagina_actual = nueva_pagina;
			break;
		case 2:
			pagina_anterior = Historial_de_navegacion.extraer();
			pagina_actual = Historial_de_navegacion.consultar();
			if (pagina_actual == "-" && pagina_anterior != "-")
			{
				cout << "Te encontrabas en " << pagina_anterior << ", ahora retrocediste al buscador nuevamente. (Ya no hay más páginas para retroceder) " << endl;
				break;
			}
			if (pagina_anterior == "-" && pagina_actual == "-")
			{
				cout << "Te encuentras en el buscador, ya no puedes retroceder" << endl;
				break;
			}
			cout << "Te encontrabas en " << pagina_anterior << ", ahora retrocediste a " << pagina_actual;
			break;
		case 3:
			Historial_de_navegacion.mostrar();
			break;
		case 4:
			cout << "Actualmente se encuentra en: " << pagina_actual;
			cout << endl;
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			cout << "Cual es el nombre con el que quieres descargar el archivo?: ";
			cin >> nombreArchivo;
			do
			{
				cout << "En que formato lo quieres descargar?: ";
				cin >> tipoArchivo;
				if (tipoArchivo == "pdf" || tipoArchivo == "txt" || tipoArchivo == "docx")
				{
					tamano = rand() % 1000 + 1;
					Descargas.Insertar(nombreArchivo, tipoArchivo, tamano);
					cout << "\n";
					break;
				}
				cout << "\n";
				cout << "Ese tipo de archivo descargable no existe. Porfavor escoja uno de estos:\n";
				cout << "\t\t\tpdf, txt y docx\n\n";
			} while (true);
			cout << "Se ha almacenado exitosamente en la cola de 'Descargas'\n";
			break;
		case 9:
			Datos = Descargas.Extraer();
			if (Datos.nombre == "" || Datos.tipo == "")
			{
				cout << "No hay archivos pendientes por terminar de descargarse\n";
				break;
			}
			cout << "Se ha descargado exitosamente el archivo " << Datos.nombre << "." << Datos.tipo << "con un tamano de " << Datos.tamano << " Mbts" << endl;
			break;
		case 10:
			Descargas.Mostrar();
			break;
		case 11:
			cout << "----------SALIENDO DEL SISTEMA DE NAVEGACIÓN WEB, STELLA-----------" << endl;
			break;
		default:
			cout << "Parece que elegiste una opción que no es válida!!! POR FAVOR ELIGE UNA DE LAS OPCIONES MOSTRADAS!!!" << endl;
			cout << endl;
			break;
		}
	} while (opc != 11);


	return 0;
}