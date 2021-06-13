#include "../include/Estadistica.h"

Estadistica::Estadistica(string nom, string des){
	Nombre = nom;
    Descripcion = des;
}

string Estadistica::getNombre(){
    return Nombre;
}
string Estadistica::getDescripcion(){
    return Descripcion;
}
    
Estadistica::~Estadistica(){}