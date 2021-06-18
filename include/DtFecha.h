#ifndef DTFECHA
#define DTFECHA
#include <string>
#include <iostream>
using namespace std;

class DtFecha {
private:
	int dia;
	int mes;
	int anio;
	int hora;
	int minuto;
public:

	DtFecha(int Sdia = 1, int Smes = 1, int Sanio = 1900, int Shora = 0, int Sminuto = 0);
	int getDia();
	int getMes();
	int getAnio();
	int getHora();
	int getMinuto();

	friend ostream& operator<<(ostream &o, DtFecha* d);
	friend ostream& operator<<(ostream &o, DtFecha d);



};





#endif
