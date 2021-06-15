#ifndef DTESTADISTICA
#define DTESTADISTICA

#include <string>
#include <iostream>
using namespace std;

class DtEstadisticaDeSegundoTipo{
private:
	string nombre;
	string descripcion;
public:
    DtEstadistica();
	DtEstadistica(string nombre, string descripcion);
	string getNombre();
	string getDescripcion();
	void setNombre(string nombre);
	void setDescripcion(string descripcion);
	friend ostream& operator<<(ostream &o, DtEstadistica *s);
	virtual ~DtEstadistica();
};
#endif
