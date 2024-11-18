#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Pagina {
    string url;
    Pagina* sig;
};
class Lista {
public:
    Lista();
    void Insertar(string url_ins);
    int Extraer(string url_ext);
    void Mostrar();
private:
    Pagina* cabecera;
    Pagina* fin;
    Pagina* actual;
};

