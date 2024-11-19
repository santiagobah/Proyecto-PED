#pragma once
#include <string>
#include <iostream>
#include "Pila.h"

using namespace std;

struct Pestana {
    string url;
    Pestana* sig;
    Pila historial_pestana;
};

class Lista {
public:
    Lista();
    void Insertar(string &url_ins, string &pag_visita);
    int Extraer(string url_ext);
    void Mostrar();
    Pestana* Buscar(string url_bus);
private:
    Pestana* cabecera;
    Pestana* fin;
    Pestana* actual;
    Pestana editable;
};

