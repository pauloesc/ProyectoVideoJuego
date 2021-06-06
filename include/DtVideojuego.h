#ifndef DTVIDEOJUEGO
#define DTVIDEOJUEGO

#include <string>
#include <iostream>
#include "map"
#include "DtCategoria.h"

using namespace std;

class DtVideojuego {
private:
	string nombre;
	string descripcion;
	float costoMensual;
	float costoTrimestral;
	float costoAnual;
	float costoVitalicio;
	map<string, DtCategoria> categorias;
public:
    DtVideojuego();
	DtVideojuego(string titulo,string descripcion,float costoMensual,float costoTrimestral,float costoAnual, float costoVitalicio, map<string, DtCategoria> categorias);
	string getNombre();
	string getDescripcion();
	float getCostoMensual();
	float getCostoTrimestral();
	float getCostoAnual();
	float getCostoVitalicio();
	map<string, DtCategoria> getCategorias();
	void setNombre(string nombre);
	void setDescripcion(string descripcion);
	void setCostoMensual(float costoMensual);
	void setCostoTrimestral(float costoTrimestral);
	void setCostoAnual(float costoAnual);
	void setCostoVitalicio(float costoVitalicio);
	void setCategorias(map<string, DtCategoria> categorias);
	friend ostream& operator<<(ostream &o, DtVideojuego *s);
	virtual ~DtVideojuego();
};





#endif
