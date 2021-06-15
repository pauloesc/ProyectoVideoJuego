#ifndef DTPARTIDAMULTIJUGADORENCURSO
#define DTPARTIDAMULTIJUGADORENCURSO

#include <string>
#include <iostream>
#include "DtPartidaEnCurso.h"
#include "DtFecha.h"
#include "list"

using namespace std;





class DtPartidaMultijugadorEnCurso : public DtPartidaEnCurso {
private:
	bool transmitidaEnVivo;
	list<string> nicknameJugadoresUnidos;
	int cantidadJugadoresUnidos;
public:
	DtPartidaMultijugadorEnCurso();
	DtPartidaMultijugadorEnCurso(DtFecha fecha, int codigo, string nombreVideojuego, bool transmitidaEnVivo, list<string> nickJugadores, int cantIntegrantes);

	bool getTransmitidaEnVivo() const;
	list<string> getNicknameJugadoresUnidos();
	int getCantidadJugadoresUnidos() const;

	void setTransmitidaEnVivo(bool transmitidaEnVivo);
	void setNicknameJugadoresUnidos(list<string> nicknameJugadoresUnidos);
    void setCantidadJugadoresUnidos(int cantidadJugadoresUnidos);

	void imprimir();

	virtual ~DtPartidaMultijugadorEnCurso();
	friend ostream& operator<<(ostream &o, DtPartidaMultijugadorEnCurso *s);

};
#endif
