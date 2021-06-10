#ifndef SUSCRIPCION
#define SUSCRIPCION

#include "DtPago.h"
#include "DtFecha.h"
#include "Reloj.h"
#include "Jugador.h"
#include "Videojuego.h"

#include <string>


using namespace std;

class Suscripcion{
private:
	DtFecha* fecha;
	DtPago medioDePago;
	float costo;
	Videojuego* videoj;
	Jugador* jug;
public:
	Suscripcion(DtFecha* fecha, DtPago medioDePago, float costo, Videojuego* vj, Jugador* j);
	DtFecha* getFecha();
	DtPago getMedioDePago();
	float getCosto();
	VideoJuego* getVideojuegoAsociado();
	Jugador* getJugador();
    virtual DtSuscripcion  crearDtSuscripcion() = 0;
    bool esActiva();
    bool esActiva(string juego);
    virtual void cancelarSuscripcion()= 0;
};





#endif
