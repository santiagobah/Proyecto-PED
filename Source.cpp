#include "Pila.h"
#include"Cola.h"
#include "Lista.h"
#include <vector>


int main() {
    // Apoyo de vectores para la interfaz gráfica
    vector <string> pestañas;
    vector <string> descargas;
    vector <string> historial;
    
    Pila Historial_de_navegacion;
    Cola Descargas;
    Lista Pestañas_Abiertas;
    
    string name_tab;
    
    Pestana* Pestana_seleccionada;
    
    int opc, tamano, contador_pestañas = 0, contador_descargas = 0;
    int cant_tabs = 0;
    string nombreArchivo, tipoArchivo, nueva_pagina, pagina_anterior, pagina_actual;
    //'pagina_actual' se tiene que ir actualizando conforme el usuario se vaya moviendo entre páginas
    Archivo Datos;

    cout << "----------BIENVENIDO AL SISTEMA DE NAVEGACIÓN WEB, STELLA----------" << endl;
    do
    {
//        // INICIO CÓDIGO INTERFAZ GRÁFICA

        cout << endl;
        cout << "-- - -- - -- - -- - -- - -- - -- - -- - -- - -- - -- - -- - -- - -- - --" << endl;
        for (int i = 0; i < contador_pestañas; i++) {
            if (pestañas[i] == pagina_actual) {
                cout << "^" << pestañas[i] << "^" << "|";
            }
            else {
                cout << pestañas[i] << "|";
            }
            // Los "^^" al lado de cada URL indican que es la pestaña actual
        }
        for (int i = 0; i < contador_descargas; i++) {
            cout << "\t" << "|| ↓  " << "(" << contador_descargas << ")";
        }
        cout << endl;
        cout << "-- - -- - -- - -- - -- - -- - -- - -- - -- - -- - -- - -- - -- - -- - --" << endl;

//        // FIN CÓDIGO INTERFAZ GRÁFICA

        cout << endl;
        cout << "¿Qué desea hacer?" << endl;
        cout << endl;
        cout << "1. Abrir nueva página en pestaña actual \n2. Retroceder a página anterior\n3. Ver páginas anteriores de pestaña actual\n4. Ver pestaña actual";
        cout << "\n5. Abrir pestaña\n6. Cerrar pestaña\n7. Ver todas las pestañas abiertas\n8. Cambiar pestaña\n9. Mostrar historial completo\n10. Mostrar todas las descargas\n11. Iniciar descarga\n12. Mostrar Descargas pendientes\n13. Salir " << endl;
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
            if (contador_pestañas < 1) {
                cout << "\nAún no hay ninguna pestaña abierta" << endl;
            }
            else{
                string new_pagina;
                cout << "Página a buscar en pestaña actual " << ": ";
                cin >> new_pagina;
                
                Pestana_seleccionada = Pestañas_Abiertas.Buscar(name_tab);
                
                Pestana_seleccionada->historial_pestana.insertar(new_pagina);
                
                pagina_actual = new_pagina;
//                cout << "\npr:" << endl;
//                Pestana_seleccionada->historial_pestana.mostrar();
//                cout << "pr:" << endl;
                
                Historial_de_navegacion.insertar(new_pagina);
                
                
    //            cout << "BUSCAR (Nombre de la página que desea buscar): ";
    //            cin >> nueva_pagina;
    //            Historial_de_navegacion.insertar(nueva_pagina);
    //            pagina_actual = nueva_pagina;
    //            Pestañas_Abiertas.Insertar(nueva_pagina);
                //contador_pestañas++;
                historial.push_back(new_pagina); //se van agregando todas las páginas que se vayan visitanto
                char num_tab;
                for (int i = 0; i < name_tab.length(); i++) {
                    num_tab = name_tab[i];
                }
                string str_conv(1, num_tab);
                int pos = stoi(str_conv);
                pestañas[pos-1] = Pestana_seleccionada->historial_pestana.consultar();
            }

            break;
        }
        case 2:
        {
            Pestana_seleccionada = Pestañas_Abiertas.Buscar(pagina_actual);
            
            pagina_anterior = Pestana_seleccionada->historial_pestana.extraer();
            
            pagina_actual = Pestana_seleccionada->historial_pestana.consultar();
            
            //pagina_anterior = Historial_de_navegacion.extraer();
            //pagina_actual = Historial_de_navegacion.consultar();
            
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
            Pestana_seleccionada = Pestañas_Abiertas.Buscar(name_tab);
            Pestana_seleccionada->historial_pestana.mostrar();
            break;
        }
        case 4:
        {
            Pestana_seleccionada = Pestañas_Abiertas.Buscar(name_tab);
            cout << "Actualmente se encuentra en: " << Pestana_seleccionada->url;
            cout << endl;
            break;
        }
        case 5:
        {
            
            
            
            string url_agr;

            cout << "\nSe ha creado una nueva pestaña, escriba la URL que desea abrir en esta pestaña: ";
            cin >> url_agr;
            
            // Generador nombres de cada pestaña:
            name_tab = "Tab" + to_string(cant_tabs+1);
            //
            
            Pestañas_Abiertas.Insertar(name_tab, url_agr);
            //Historial_de_navegacion.insertar(url_agr); // la página que se acaba de abrir se agrega al historialn de navegación
            Historial_de_navegacion.insertar(url_agr);
            
            
            pagina_actual = url_agr;
            
            contador_pestañas++;
            
            cant_tabs++;
            
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
            else if (respuesta_cierre == -2) {
                cout << "\nLa pestaña con el URL '" << pestaña_cerrar << "' no está abierta en el momento, por tanto, no se puede cerrar" << endl;
            }
            else if (respuesta_cierre == 0) {
                cout << "\nLa pestaña con el URL '" << pestaña_cerrar << "' ha sido cerrada exitosamente" << endl;

                for (int i = 0; i < contador_pestañas; i++) {
                    if (pestaña_cerrar == pestañas[i]) {
                        pestañas.erase(pestañas.begin() + i);
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
            cout << "\nEscriba el número de tab al que se desea mover: ";
            string num_tab; cin >> num_tab;
            string name_bus_tab = "Tab" + num_tab;
            Pestana_seleccionada = Pestañas_Abiertas.Buscar(name_bus_tab);
            name_tab = name_bus_tab;
            pagina_actual = Pestana_seleccionada->historial_pestana.consultar();
            break;
        }
        case 9:
        {
            // No es el case correcto, pero voy poniendo el código para mostrar el historial completo del programa
            cout << endl;
            cout << "----------HISTORIAL----------" << endl;
            cout << endl;
            Historial_de_navegacion.mostrar();
//            if (historial.size() == 0)
//            {
//                cout << "El historial está vacio" << endl;
//                break;
//            }
//            for (int i = 0; i < historial.size(); i++)
//            {
//                cout << historial[i] << endl;
//            }
            cout << "--------------------------------------------------" << endl;
            break;
        }
        case 10:
        {
            Descargas.Mostrar();
            break;
        }
        case 11:
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
            contador_descargas++;
            break;
        }
        case 12:
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
        case 13:
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
    } while (opc != 13);
    return 0;
}
