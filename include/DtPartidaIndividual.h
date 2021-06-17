#ifndef DTPARTIDAINDIVIDUAL
#define DTPARTIDAINDIVIDUAL
#include <string>
#include <iostream>
#include "DtPartida.h"
#include "DtFecha.h"

using namespace std;






class DtPartidaIndividual : public DtPartida {
private:
	bool continuarPartidaAnterior;
public:
    DtPartidaIndividual();
	DtPartidaIndividual(DtFecha fecha, float duracion, int codigo, bool enCurso, bool continuarPartidaAnterior);
	bool getContinuaPartidaAnterior();
	void setContinuaPartidaAnterior(bool continuarPartidaAnterior);
	void imprimir();
	friend ostream& operator<<(ostream &o, DtPartidaIndividual *s);
	~DtPartidaIndividual();
};
#endif
