#ifndef SUSCRIPCIONVITALICIA
#define SUSCRIPCIONVITALICIA

#include "Suscripcion.h"
#include "DtPago.h"
#include "DtFecha.h"
#include "Reloj.h"


using namespace std;

class Videojuego;
class Jugador;

class SuscripcionVitalicia : public Suscripcion{
private:

public:
	SuscripcionVitalicia(DtFecha* fecha, DtPago medioDePago, float costo, Videojuego* vj, Jugador* j);
    DtSuscripcion*  crearDtSuscripcion();
    void cancelarSuscripcion();

    ~SuscripcionVitalicia();
};


#include "Videojuego.h"
#include "Jugador.h"


#endif
