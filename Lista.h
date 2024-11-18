//
//  Lista.hpp
//  Sistema de Gestión de Navegación Web
//
//  Created by Santiago Bañuelos on 18/11/24.
//

#pragma once

struct Pagina{
    string url;
    Pagina* sig;
};

class Lista{
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
