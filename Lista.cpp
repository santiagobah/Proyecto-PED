#include "Lista.h"
Lista::Lista() {
    cabecera = fin = nullptr;
}
void Lista::Insertar(string &url_ins, string &pag_visita) {

    Pestana* nuevo = new Pestana;
    nuevo->url = url_ins;
    nuevo->historial_pestana.insertar(pag_visita);
    nuevo->sig = nullptr;
    if (cabecera == nullptr) {
        cabecera = fin = nuevo;
    }
    else if (url_ins < cabecera->url) {
        nuevo->sig = cabecera;
        cabecera = nuevo;
    }
    else {
        Pestana* actual = cabecera;
        Pestana* anterior = nullptr;
        //Recorrer la lsita:
        while (actual != nullptr && actual->url < url_ins) {
            anterior = actual;
            actual = actual->sig;
        }
        nuevo->sig = actual;
        anterior->sig = nuevo;
        if (nuevo->sig == nullptr) {
            fin = nuevo;
        }
    }
}
int Lista::Extraer(string url_ext) {
    if (cabecera == nullptr) {
        return -1;
    }
    Pestana* actual = cabecera;
    Pestana* anterior = nullptr;
    bool encontrado = false;
    while (actual != nullptr) {
        if (actual->url == url_ext) {
            encontrado = true;
            break;
        }
        anterior = actual;
        actual = actual->sig;
    }
    if (!encontrado) {
        return -2;
    }
    if (actual == cabecera) {
        cabecera = actual->sig;
        if (cabecera == nullptr) {
            fin = nullptr;
        }
    }
    else {
        anterior->sig = actual->sig;
        if (actual == fin) {
            fin = anterior;
        }
    }
    delete actual;
    return 0;
}
void Lista::Mostrar() {
    cout << "\nLista actual: \n";
    if (cabecera == nullptr)
    {
        cout << "\nNo hay pestaÒas abiertas en el momento" << endl;
        return;
    }
    actual = cabecera;
    while (actual != nullptr) {
        cout << actual->url;
        cout << " (" << actual->historial_pestana.consultar() << ")";
        if (actual == cabecera) {
            cout << " <-- Cabecera";
        }
        cout << endl;
        actual = actual->sig;
    }
}

Pestana* Lista::Buscar(string url_bus){
    actual = cabecera;
    int pos = 0;
    while (actual != nullptr) {
        if (actual->url == url_bus) {
            return actual;
        }
        actual =  actual->sig;
        pos++;
    }
    return nullptr;
    //no habrá manejo de errores del método pues siempre se buscará la URL actual y siempre estará disponible
}
