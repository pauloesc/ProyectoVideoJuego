#ifndef DTDESARROLLADOR
#define DTDESARROLLADOR

#include <string>
#include <iostream>
#include "DtUsuario.h"
using namespace std;

class DtDesarrollador : public DtUsuario{
private:
	string nombreEmpresa;
public:
    DtDesarrollador();
	DtDesarrollador(string Semail, string Scontrasenia, string SnombreEmpresa);
	string getNombreEmpresa();
	void setNombreEmpresa(string nombreEmpresa);
	virtual ~DtDesarrollador();
};

#endif
