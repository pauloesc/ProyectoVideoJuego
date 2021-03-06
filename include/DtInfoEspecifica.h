#ifndef DTINFOESPECIFICA
#define DTINFOESPECIFICA

#include <string>
#include <iostream>
#include <vector>
#include "DtCategoria.h"
#include "DtVideojuego.h"

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

	

	friend ostream& operator<<(ostream &o, DtInfoEspecifica *s);
	~DtInfoEspecifica();
};

#endif
