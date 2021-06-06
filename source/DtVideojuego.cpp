#include <string>
#include "../include/DtVideojuego.h"
#include <iostream>
#include "map"
using namespace std;

// este data type es un poco diferente se los diagramas, tiene los nombres de las categorias

DtVideojuego::DtVideojuego (string Snombre, string Sdescripcion, float ScostoMensual, float ScostoTrimestral, float ScostoAnual, float ScostoVitalicio, map<string, DtCategoria> Scategorias) {
	nombre = Snombre;
	descripcion = Sdescripcion;
	costoMensual = ScostoMensual;
	costoTrimestral = ScostoTrimestral;
	costoAnual = ScostoAnual;
	costoVitalicio = ScostoVitalicio;
	map<string, DtCategoria> :: iterator it;
	for(it = Scategorias.begin(); it != Scategorias.end(); ++it){
        categorias.insert(pair<string, DtCategoria>(it->first,it->second));
	}
}

DtVideojuego::~DtVideojuego () {
	map<string, DtCategoria> :: iterator it;
    for(it = categorias.begin(); it != categorias.end(); ++it)
    {
        DtCategoria cat = it->second;
        cat.~DtCategoria();
    }
    categorias.clear();
}

string DtVideojuego::getNombre() {
	return nombre;
}

string DtVideojuego::getDescripcion() {
	return descripcion;
}


float DtVideojuego::getCostoMensual() {
	return costoMensual;
}

float DtVideojuego::getCostoTrimestral() {
	return costoTrimestral;
}

float DtVideojuego::getCostoAnual() {
	return costoAnual;
}

float DtVideojuego::getCostoVitalicio() {
	return costoVitalicio;
}

map<string, DtCategoria> DtVideojuego::getCategorias() {
	return categorias;
}

void DtVideojuego::setNombre(string nombre) {
	this->nombre = nombre;
}

void DtVideojuego::setDescripcion(string descripcion) {
	this->descripcion = descripcion;
}

void DtVideojuego::setCostoMensual(float costoMensual) {
	this->costoMensual = costoMensual;
}

void DtVideojuego::setCostoTrimestral(float costoTrimestral) {
	this->costoTrimestral = costoTrimestral;
}

void DtVideojuego::setCostoAnual(float costoAnual) {
	this->costoAnual = costoAnual;
}

void DtVideojuego::setCostoVitalicio(float costoVitalicio) {
	this->costoVitalicio = costoVitalicio;
}

void DtVideojuego::setCategorias(map<string, DtCategoria> scategorias) {
	map<string, DtCategoria> :: iterator it;
    for(it = categorias.begin(); it != categorias.end(); ++it)
    {
        categorias.erase(it);
    }
    categorias.clear();
    map<string, DtCategoria> :: iterator it1;
	for(it1 = scategorias.begin(); it1 != scategorias.end(); ++it1){
        categorias.insert(pair<string, DtCategoria>(it1->first,it1->second));
	}
}

ostream& operator<<(ostream &o, DtVideojuego *s) {
	o << "Nombre: " << s->getNombre() << '\n';
	o << "Descripcin: " << s->getDescripcion() << '\n';
	o << "Costo Mensual: " << s->getCostoMensual() << '\n';
	o << "Costo Trimestral: " << s->getCostoTrimestral() << '\n';
	o << "Costo Anual: " << s->getCostoAnual() << '\n';
	o << "Costo Vitalicio: " << s->getCostoVitalicio() << '\n';
	o << "Categoras: " ;
	int i = 0;
	map<string, DtCategoria> :: iterator it;
	for(it = s->categorias.begin(); it != s->categorias.end(); ++it){
        i++;
        if ( i == s->categorias.size()){
            o << it->first << '\n';
        }else{
            o << it->first << ", ";
        }
	}
	return o;
}
