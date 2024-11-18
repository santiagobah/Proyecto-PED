#include "Pila.h"
#include"Cola.h"
#include "Lista.h"


int main() {
    // Apoyo de vectores para la interfaz gráfica
    vector<string> pestañas;
	Pila Historial_de_navegacion;
	Cola Descargas;
    Lista Pestañas_Abiertas;
    int opc, tamano, contador_pestañas = 0;
	string nombreArchivo, tipoArchivo, nueva_pagina, pagina_anterior, pagina_actual;
	//'pagina_actual' se tiene que ir actualizando conforme el usuario se vaya moviendo entre páginas
	Archivo Datos;

	cout << "----------BIENVENIDO AL SISTEMA DE NAVEGACIÓN WEB, STELLA----------" << endl;
	do
	{
        // INICIO CÓDIGO INTERFAZ GRÁFICA
        
        cout << endl;
        cout << "-- - -- - -- - -- - -- - -- - -- - -- - -- - -- - -- - -- - -- - -- - --"<<endl;
        for (int i = 0; i < contador_pestañas; i++) {
            if (pestañas[i] == pagina_actual) {
                cout << "^" <<pestañas[i] << "^" << "|";
            }
            else{
                cout << pestañas[i] << "|";
            }
            // Los "^^" al lado de cada URL indican que es la pestaña actual
        }
        cout << endl;
        cout << "-- - -- - -- - -- - -- - -- - -- - -- - -- - -- - -- - -- - -- - -- - --"<<endl;

        // FIN CÓDIGO INTERFAZ GRÁFICA
        
		cout << endl;
		cout << "¿Qué desea hacer?" << endl;
		cout << endl;
		cout << "1. Visitar nueva página \n2. Retroceder en el historial\n3. Ver historial de búsqueda completo\n4. Ver pestaña actual";
		cout << "\n5. Abrir pestaña\n6. Cerrar pestaña\n7. Ver todas las pestañas abiertas\n8. Agregar una decarga\n9. Iniciar descarga\n10. Mostrar Descargas pendientes\n11. Cambiar de pestaña\n12. Salir " << endl;
        cout << "\nOpción seleccionada: ";
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
            {
                cout << "BUSCAR (Nombre de la página que desea buscar): ";
                cin >> nueva_pagina;
                Historial_de_navegacion.insertar(nueva_pagina);
                pagina_actual = nueva_pagina;
                Pestañas_Abiertas.Insertar(nueva_pagina);
                contador_pestañas++;
                
                pestañas.push_back(nueva_pagina);
                
                break;
            }
		case 2:
            {
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
            }
		case 3:
            {
                Historial_de_navegacion.mostrar();
                break;
            }
		case 4:
            {
                cout << "Actualmente se encuentra en: " << pagina_actual;
                cout << endl;
                break;
            }
		case 5:
            {
                string url_agr;
                cout << "\nSe ha creado una nueva pestaña, escriba la URL que desea abrir en esta pestaña: ";
                cin >> url_agr;
                Pestañas_Abiertas.Insertar(url_agr);
                Historial_de_navegacion.insertar(url_agr); // la página que se acaba de abrir se agrega al historialn de navegación
                pagina_actual = url_agr;
                contador_pestañas++;
                
                pestañas.push_back(url_agr);
                
                break;
            }
		case 6:
            {
                string pestaña_cerrar;
                int respuesta_cierre;
                cout << "\nURL de la pestaña a cerrar: ";
                cin >> pestaña_cerrar;
                respuesta_cierre = Pestañas_Abiertas.Extraer(pestaña_cerrar);
                if (respuesta_cierre == -1) {
                    cout << "\nActualmente no hay pestañas abiertas" << endl;
                }
                else if(respuesta_cierre == -2){
                    cout << "\nLa pestaña con el URL '" << pestaña_cerrar << "' no está abierta en el momento, por tanto, no se puede cerrar" << endl;
                }
                else if (respuesta_cierre == 0){
                    cout << "\nLa pestaña con el URL '" << pestaña_cerrar <<"' ha sido cerrada exitosamente" << endl;
                    
                    for (int i = 0; i < contador_pestañas; i++) {
                        if (pestaña_cerrar == pestañas[i]) {
                            pestañas.erase(pestañas.begin()+i);
                            break;
                        }
                    }
                    
                    contador_pestañas--;
                }
                break;
            }
		case 7:
            {
                cout << "\nPestañas actuales:" << endl;
                Pestañas_Abiertas.Mostrar();
                break;
            }
		case 8:
            {
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
            }
		case 9:
            {
                Datos = Descargas.Extraer();
                if (Datos.nombre == "" || Datos.tipo == "")
                {
                    cout << "No hay archivos pendientes por terminar de descargarse\n";
                    break;
                }
                cout << "Se ha descargado exitosamente el archivo " << Datos.nombre << "." << Datos.tipo << "con un tamano de " << Datos.tamano << " Mbts" << endl;
                break;
            }
		case 10:
            {
                Descargas.Mostrar();
                break;
            }
        case 11:
            {
                string url_move;
                cout << "\nEscriba el URL de la página a la que desea moverse: ";
                cin >> url_move;
                for (int i = 0; i < contador_pestañas; i++) {
                    if(pestañas[i] == url_move){
                        pagina_actual = url_move;
                    }
                    else{
                        cout << "\nLa página '" << url_move << "' no está abierta en este momento" << endl;
                    }
                }
                break;
            }
		case 12:
            {
                cout << "----------SALIENDO DEL SISTEMA DE NAVEGACIÓN WEB, STELLA-----------" << endl;
                break;
            }
		default:
            {
                cout << "Parece que elegiste una opción que no es válida!!! POR FAVOR ELIGE UNA DE LAS OPCIONES MOSTRADAS!!!" << endl;
                cout << endl;
                break;
            }
		}
	} while (opc != 12);
	return 0;
}
