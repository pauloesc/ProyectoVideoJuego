#ifndef SUSCRIPCIONVITALICIA
#define SUSCRIPCIONVITALICIA

#include "Suscripcion.h"
#include "DtPago.h"
#include "DtFecha.h"
#include "Reloj.h"
#include "Jugador.h"
#include "Videojuego.h"

using namespace std;

class SuscripcionVitalicia : public Suscripcion{
private:

public:
	SuscripcionVitalicia(DtFecha* fecha, DtPago medioDePago, float costo, Videojuego* vj, Jugador* j);
    DtSuscripcion*  crearDtSuscripcion();
    void cancelarSuscripcion();
};





#endif
