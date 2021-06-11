#ifndef DTPARTIDAMULTIJUGADOR
#define DTPARTIDAMULTIJUGADOR

#include <string>
#include <iostream>
#include <vector>

#include "DtFecha.h"

using namespace std;





class DtPartidaMultijugador {
private:
	int codigo;
	DtFecha* fecha;
	string nombrevid;
	bool transmitidaEnVivo;
	string inicio;
	vector<string> nicknameJugadoresUnidos;
public:
	DtPartidaMultijugador(int Scodigo, DtFecha* Sfecha, string Snombrevid, bool StransmitidaEnVivo, string Sinicio, vector<string> SnicknameJugadoresUnidos);
	
	int getCodigo();
	DtFecha* getFecha();
	string getNombreVid();
	bool getTransmitidaEnVivo();
	string getInicio();
	vector<string> getNicknameJugadoresUnidos();

	friend ostream& operator<<(ostream &o, DtPartidaMultijugador* d);

	~DtPartidaMultijugador();

};
#endif
