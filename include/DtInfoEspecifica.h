#ifndef DTINFOESPECIFICA
#define DTINFOESPECIFICA

#include <string>
#include <iostream>
#include <vector>
#include "DtCategoria.h"

using namespace std;

class DtInfoEspecifica {
private:
	string descripcion;
	float costoMensual;
	float costoTrimestral;
	float costoAnual;
	float costoVitalicio;
	vector<string> categorias;
    string empresadesarrolladora;
    float promedio;

public:
    DtInfoEspecifica();
	DtInfoEspecifica(string sdescripcion, float scostoMensual,float scostoTrimestral,float scostoAnual, float scostoVitalicio, vector<string> scategorias, string sempresadesarrolladora, float spromedio);
	string getDescripcion();
	float getCostoMensual();
	float getCostoTrimestral();
	float getCostoAnual();
	float getCostoVitalicio();
	vector<string> getCategorias();
    string getEmpresa();
    float getpromedio();

	
	void setDescripcion(string descripcion);
	void setCostoMensual(float costoMensual);
	void setCostoTrimestral(float costoTrimestral);
	void setCostoAnual(float costoAnual);
	void setCostoVitalicio(float costoVitalicio);
	void setCategorias(vector<string> categorias);
    void setEmpresa(string empresadesarroladora);
    void setpromedio(float promedio);

	friend ostream& operator<<(ostream &o, DtInfoEspecifica *s);
	~DtInfoEspecifica();
};

#endif
