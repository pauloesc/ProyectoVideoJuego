#include "../include/Categoria.h"

Categoria::Categoria( string vNombre, string vDescripcion, string vTipo) {
	this->Nombre = vNombre;
    this->Descripcion = vDescripcion;
    this->Tipo = vTipo;
}


string Categoria::getNombre(){
    return Nombre;
}

string Categoria::getDescripcion(){
    return Descripcion;
}

string Categoria::getTpo(){
    return Tipo;
}

DtCategoria Categoria::ObtenerDataCategoria(){
    DtCategoria Datos(this->Nombre, this->Descripcion, this->Tipo);
    return Datos;
}

Categoria::adicionarVideojuego(Videojuego* vid){
    VectorDePunterosVideojuegos.push_back(vid);
}

Categoria::desvincularVideoJuego(vj:VideoJuego){

    int i=0;
    bool NoEncontrado = 1;

    while( (i< VectorDePunterosVideojuegos.size()) && NoEncontrado){

        if ( (*VectorDePunterosVideojuegos[i]).getNombre() == vj.getNombre() ){
            NoEncontrado = 0;
        }
        else{
            i=i+1;
        }
    }
    //elimino la posicion donde esta ese puntero;
    iterator= VectorDePunterosVideojuegos.begin() + i;
    VectorDePunterosVideojuegos.erase(iterator);
}

Categoria::~Categoria(){
    VectorDePunterosVideojuegos.clear();
}
