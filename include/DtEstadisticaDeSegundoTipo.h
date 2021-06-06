#ifndef DTESTADISTICADESEGUNDOTIPO
#define DTESTADISTICADESEGUNDOTIPO

#include <string>
#include <iostream>
using namespace std;

class DtEstadisticaDeSegundoTipo{
private:
	string nombre;
	float valorNumeroDeEstadisica;
public:
    DtEstadisticaDeSegundoTipo();
	DtEstadisticaDeSegundoTipo(string nombre, float valorNumeroDeEstadisica);
	string getNombre();
	float getValorNumeroDeEstadisica();
	void setNombre(string nombre);
	void setValorNumeroDeEstadisica(float valorNumeroDeEstadisica);
	friend ostream& operator<<(ostream &o, DtEstadisticaDeSegundoTipo *s);
	virtual ~DtEstadisticaDeSegundoTipo();
};
#endif
