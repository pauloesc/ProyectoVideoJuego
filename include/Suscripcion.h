#ifndef SUSCRIPCION
#define SUSCRIPCION

#include "DtPago.h"
#include "DtFecha.h"
#include "DtSuscripcion.h"

#include "Jugador.h"
#include "Reloj.h"
#include "Videojuego.h"


#include <string>

class Videojuego;
class Jugador;

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
	Videojuego* getVideojuegoAsociado();
	Jugador* getJugador();
    virtual DtSuscripcion* crearDtSuscripcion() = 0;
    bool esActiva();
    bool esActiva(string juego);
    virtual void cancelarSuscripcion()= 0;

    virtual ~Suscripcion();
};




#endif
