
#include <string>
#include "../include/DtDesarrollador.h"
#include "../include/DtUsuario.h"

DtDesarrollador::DtDesarrollador () :DtUsuario() {
	nombreEmpresa = " ";
}


DtDesarrollador::DtDesarrollador (string Semail, string Scontrasenia, string SnombreEmpresa) :DtUsuario (Semail,Scontrasenia){
	nombreEmpresa = SnombreEmpresa;
}

DtDesarrollador::~DtDesarrollador () {
}

string DtDesarrollador::getNombreEmpresa() {
	return nombreEmpresa;
}

void DtDesarrollador::setNombreEmpresa(string nombreEmpresa){
	this->nombreEmpresa = nombreEmpresa;
}

