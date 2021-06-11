#include <string>
#include "../include/DtInfoEspecifica.h"
#include <iostream>
#include <vector>
using namespace std;

DtInfoEspecifica::DtInfoEspecifica(){}

DtInfoEspecifica::DtInfoEspecifica(string sdescripcion, float scostoMensual,float scostoTrimestral,float scostoAnual, float scostoVitalicio, vector<string> scategorias, string sempresadesarrolladora, float spromedio);{
	descripcion = sdescripcion;
	costoMensual = scostoMensual;
	costoTrimestral = scostoTrimestral;
	costoAnual = scostoAnual;
	costoVitalicio = scostoVitalicio;
	empresadesarrolladora= sempresadesarrolladora;
    promedio= spromedio;
    
    vector<string> :: iterator it;
	for(it = scategorias.begin(); it!= scategorias.end(); ++it){
        categorias.push_back(*it);
	}
}

DtInfoEspecifica::~DtInfoEspecifica () {
    categorias.clear();
}

string DtInfoEspecifica::getDescripcion() {
	return descripcion;
}


float DtInfoEspecifica::getCostoMensual() {
	return costoMensual;
}

float DtInfoEspecifica::getCostoTrimestral() {
	return costoTrimestral;
}

float DtInfoEspecifica::getCostoAnual() {
	return costoAnual;
}

float DtInfoEspecifica::getCostoVitalicio() {
	return costoVitalicio;
}

vector<string> DtInfoEspecifica::getCategorias() {
	vector<string> resu;
	vector<string> :: iterator it;
	for(it =categorias.begin(); it !=categorias.end(); ++it){
        resu.push_back(*it);

	return resu;
}

void DtInfoEspecifica::setNombre(string nombre) {
	this->nombre = nombre;
}

void DtInfoEspecifica::setDescripcion(string descripcion) {
	this->descripcion = descripcion;
}

void DtInfoEspecifica::setCostoMensual(float costoMensual) {
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
