#ifndef CONTROLADORSUSCRIPCION
#define CONTROLADORSUSCRIPCION

#include <string>
#include <vector>

#include "SuscripcionTemporal.h"
#include "SuscripcionVitalicia.h"
#include "Jugador.h"
#include "Reloj.h"

#include "DtSuscripcion.h"
#include "DtPago.h"
#include "DtFecha.h"

#include "ControladorVideojuego.h"
#include "ControladorUsuario.h"



using namespace std;


class ControladorSuscripciones {
    private:
        static ControladorSuscripciones* Instance;
        
        Videojuego *vj;
        string nomJ;
        string tiposus;
        DtPago pago;    // es un enumerado
    public:
        static ControladorSuscripciones* getInstance();

        vector<string> obtenerNombresSuscripcionesActivas();
        vector<DtSuscripcion*> obtenerSuscripcionesActivas();
        vector<DtSuscripcion*> obtenerSuscripcionesNoActivas();
        void IngresarDatosSuscripcion(string tiposuscripcion, DtPago pag);
        void SeleccionarVideojuego(string Juego);
        void Finalizarproceso();
        void ConfirmarSuscripcion();
        void Cancelar();
};

#endif