//
//  Pag_Web.hpp
//  Sistema de Gestión de Navegación Web
//
//  Created by Santiago Bañuelos on 18/11/24.
//

#pragma once
#include <iostream>
using namespace std;

class Contenido{
public:
    Contenido();
    void Insertar_Titulo();
    void Insertar_Contenido();
    void Cargar_Paginas();
private:
    string title, content;
};
