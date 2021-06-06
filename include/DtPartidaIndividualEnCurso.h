#ifndef DTPARTIDAINDIVIDUALENCURSO
#define DTPARTIDAINDIVIDUALENCURSO
#include <string>
#include <iostream>
#include "DtPartidaEnCurso.h"
#include "DtFecha.h"

using namespace std;






class DtPartidaIndividualEnCurso : public DtPartidaEnCurso {
private:
	bool continuarPartidaAnterior;
public:
    DtPartidaIndividualEnCurso();
	DtPartidaIndividualEnCurso(DtFecha fecha, int codigo, string nombreVideojuego, bool continuarPartidaAnterior);
	bool getContinuaPartidaAnterior();
	void setContinuaPartidaAnterior(bool continuarPartidaAnterior);
	~DtPartidaIndividualEnCurso();
};
#endif