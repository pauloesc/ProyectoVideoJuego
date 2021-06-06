#ifndef DTJUGADOR
#define DTJUGADOR

#include <string>
#include <iostream>
#include "DtUsuario.h"
using namespace std;

class DtJugador : public DtUsuario{
private:
	string nickname;
	string descripcion;
public:
    DtJugador();
	DtJugador(string Semail, string Scontrasenia, string Snickname, string Sdescripcion);
	string getNickname();
	string getDescripcion();
	void setNickname(string nickname);
	void setDescripcion(string descripcion);
	virtual ~DtJugador();
};





#endif
