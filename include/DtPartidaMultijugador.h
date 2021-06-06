#ifndef DTPARTIDAMULTIJUGADOR
#define DTPARTIDAMULTIJUGADOR

#include <string>
#include <iostream>
#include "DtPartida.h"
#include "DtFecha.h"

using namespace std;





class DtPartidaMultijugador : public DtPartida {
private:
	bool transmitidaEnVivo;
public:
	DtPartidaMultijugador();
	DtPartidaMultijugador(DtFecha sfecha, float sduracion, int codigo, bool enCurso, bool transmitidaEnVivo);
	bool getTransmitidaEnVivo() const;

	void setTransmitidaEnVivo(bool transmitidaEnVivo);
	~DtPartidaMultijugador();

};
#endif
