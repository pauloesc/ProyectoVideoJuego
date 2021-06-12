#ifndef SUSCRIPCIONTEMPORAL
#define SUSCRIPCIONTEMPORAL

#include "Suscripcion.h"
#include "DtPago.h"
#include "DtFecha.h"
#include "Reloj.h"
#include "Jugador.h"
#include "Videojuego.h"

using namespace std;

class SuscripcionTemporal : public Suscripcion{
private:
	bool activa;
	int validez;
	bool cancelada;
public:
	SuscripcionTemporal (DtFecha* fecha, DtPago medioDePago, float costo, Videojuego* vj, Jugador* j, bool activa, int validez, bool cancelada);
	bool getActiva();
    int getValidez();
    bool getCancelada();
    DtSuscripcion* crearDtSuscripcion();
    void cancelarSuscripcion();
};





#endif
