#ifndef DTSUSCRIPCION
#define DTSUSCRIPCION

#include <string>
#include <iostream>
using namespace std;

class DtSuscripcion{
private:
	string nombre;
	float costo;
	string tipoSuscripcion;
public:
    DtSuscripcion();
	DtSuscripcion(string snombre, float scosto, string stipoSuscripcion);
	string getNombre();
	float getCosto();
	string getTipoSuscripcion();
	void setNombre(string nombre);
	void setCosto(float costo);
	void setTipoSuscripcion(string tipoSuscripcion);
	friend ostream& operator<<(ostream &o, DtSuscripcion *s);
	virtual ~DtSuscripcion();
};





#endif

