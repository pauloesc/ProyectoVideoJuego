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
	vector<string> categorias;
public:
    DtVideojuego();
	DtVideojuego(string titulo,string descripcion,float costoMensual,float costoTrimestral,float costoAnual, float costoVitalicio, vector<string> categorias);
	string getNombre();
	string getDescripcion();
	float getCostoMensual();
	float getCostoTrimestral();
	float getCostoAnual();
	float getCostoVitalicio();
	vector<string> getCategorias();
	void setNombre(string nombre);
	void setDescripcion(string descripcion);
	void setCostoMensual(float costoMensual);
	void setCostoTrimestral(float costoTrimestral);
	void setCostoAnual(float costoAnual);
	void setCostoVitalicio(float costoVitalicio);
	void setCategorias(vector<string> categorias);
	friend ostream& operator<<(ostream &o, DtVideojuego *s);
	virtual ~DtVideojuego();
};





#endif
