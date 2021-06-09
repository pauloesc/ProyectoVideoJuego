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

string Categoria::getTipo(){
    return Tipo;
}

DtCategoria* Categoria::ObtenerDataCategoria(){
    DtCategoria* Datos= new Datos(this->Nombre, this->Descripcion, this->Tipo);
    return Datos;
}

void Categoria::adicionarVideojuego(Videojuego* vid){
    VectorDePunterosVideojuegos.push_back(vid);
}

void Categoria::desvincularVideoJuego(VideoJuego* vj){

    int i=0;
    bool NoEncontrado = 1;

    while( (i< VectorDePunterosVideojuegos.size()) && NoEncontrado){

        if ( (*VectorDePunterosVideojuegos[i]).getNombre() == (*vj).getNombre() ){
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

bool Categoria::esCategoriaDelVideojuego(Videojuego* v){

    bool res=0;
    for(int i= 0; i< VectorDePunterosVideojuegos.size(); i++){
        res = res || ( VectorDePunterosVideojuegos[i] == v )
    }

}


Categoria::~Categoria(){
    VectorDePunterosVideojuegos.clear();
}
