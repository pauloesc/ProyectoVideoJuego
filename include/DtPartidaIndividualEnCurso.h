#ifndef DTPARTIDAINDIVIDUALENCURSO
#define DTPARTIDAINDIVIDUALENCURSO
#include <string>
#include <iostream>
#include "DtPartidaEnCurso.h"
#include "DtFecha.h"







class DtPartidaIndividualEnCurso : public DtPartidaEnCurso {
private:
	bool continuarPartidaAnterior;
public:
    DtPartidaIndividualEnCurso();
	DtPartidaIndividualEnCurso(DtFecha fecha, int codigo, string nombreVideojuego, bool continuarPartidaAnterior);
	bool getContinuaPartidaAnterior();
	void setContinuaPartidaAnterior(bool continuarPartidaAnterior);
	~DtPartidaIndividualEnCurso();
	
	void imprimir();

	friend ostream& operator<<(ostream &o, DtPartidaIndividualEnCurso *s);
};
#endif
