#include <string>
#include "../include/DtVideojuego.h"
#include <iostream>
#include <vector>
using namespace std;


DtVideojuego::DtVideojuego(){}

DtVideojuego::DtVideojuego (string Snombre, string Sdescripcion, float ScostoMensual, float ScostoTrimestral, float ScostoAnual, float ScostoVitalicio, vector<string> Scategorias) {
	nombre = Snombre;
	descripcion = Sdescripcion;
	costoMensual = ScostoMensual;
	costoTrimestral = ScostoTrimestral;
	costoAnual = ScostoAnual;
	costoVitalicio = ScostoVitalicio;
	vector<string> :: iterator it;
	for(it = Scategorias.begin(); it != Scategorias.end(); ++it){
        categorias.push_back(*it);
	}
}

DtVideojuego::~DtVideojuego () {
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

vector<string> DtVideojuego::getCategorias() {
	vector<string> resu;
	vector<string> :: iterator it;
	for(it =categorias.begin(); it !=categorias.end(); ++it){
        resu.push_back(*it);

	return resu;
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

void DtVideojuego::setCategorias(vector<string> scategorias) {
	
	categorias.clear();
	vector<string> :: iterator it;
	for(it = Scategorias.begin(); it != Scategorias.end(); ++it){
        categorias.push_back(*it);
	}
}

ostream& operator<<(ostream &o, DtVideojuego* s) {
	o << "Nombre: " << s->getNombre() << '\n';
	o << "Descripción: " << s->getDescripcion() << '\n';
	o << "Costo Mensual: " << s->getCostoMensual() << '\n';
	o << "Costo Trimestral: " << s->getCostoTrimestral() << '\n';
	o << "Costo Anual: " << s->getCostoAnual() << '\n';
	o << "Costo Vitalicio: " << s->getCostoVitalicio() << '\n';
	o << "Categoras: " ;
	int i = 0;
	vector<string> :: iterator it;
	for(it = s->categorias.begin(); it != s->categorias.end(); ++it){
        if ( i == s->categorias.size()){
            o << (*it) << '\n';
        }else{
            o << (*it) << ", ";
        }
	}
	return o;
}
