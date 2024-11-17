#include "Pila.h"

int main() {
	Pila Historial_de_navegacion;
	int opc;

	string nueva_pagina;
	string pagina_anterior;
	string pagina_actual; //Esta se tiene que ir actualizando conforme el usuario se vaya moviendo entre páginas

	cout << "----------BIENVENIDO AL SISTEMA DE NAVEGACIÓN WEB, STELLA----------" << endl;
	do
	{
		cout << endl;
		cout << "¿Qué desea hacer?" << endl;
		cout << endl;
		cout << "1. Visitar nueva página\t\t2. Retroceder en el historial\t\t3. Ver historial de búsqueda completo\t\t 4. Ver pestaña actual\t\t 5. Abrir pestaña\t\t 6. Cerrar pestaña\t\t 7. Ver todas las pestañas abiertas\t\t 8. Agregar una decarga\t\t 9. Iniciar descarga\t\t 10. Salir " << endl;
		cin >> opc;
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
			if (pagina_anterior == "-" && pagina_actual =="-")
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
			break;
		case 9:
			break;
		case 10:
			cout << "----------SALIENDO DEL SISTEMA DE NAVEGACIÓN WEB, STELLA-----------" << endl;
			break;
		default:
			cout << "Parece que elegiste una opción que no es válida!!! POR FAVOR ELIGE UNA DE LAS OPCIONES MOSTRADAS!!!" << endl;
			cout << endl;
			break;
		}
	} while (opc != 10);


	return 0;
}