#include "Lista.h"
Lista::Lista() {
    cabecera = fin = nullptr;
}
void Lista::Insertar(string url_ins) {

    Pagina* nuevo = new Pagina;
    nuevo->url = url_ins;
    nuevo->sig = nullptr;
    if (cabecera == nullptr) {
        cabecera = fin = nuevo;
    }
    else if (url_ins < cabecera->url) {
        nuevo->sig = cabecera;
        cabecera = nuevo;
    }
    else {
        Pagina* actual = cabecera;
        Pagina* anterior = nullptr;
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
    Pagina* actual = cabecera;
    Pagina* anterior = nullptr;
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
        cout << "\nNo hay pestañas abiertas en el momento" << endl;
        return;
    }
    actual = cabecera;
    while (actual != nullptr) {
        cout << actual->url;
        if (actual == cabecera) {
            cout << " <-- Cabecera";
        }
        cout << endl;
        actual = actual->sig;
    }
}