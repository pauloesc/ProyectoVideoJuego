#ifndef CONTROLADORSUSCRIPCIONES
#define CONTROLADORSUSCRIPCIONES

#include "IControladorSuscripciones.h"

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

class IControladorSuscripciones;

class ControladorSuscripciones : public IControladorSuscripciones {
    private:
        static ControladorSuscripciones* Instance;
        ControladorSuscripciones();
        Videojuego *vj;
        string nomJ;
        string tiposus;
        DtPago pago;    // es un enumerado
    public:
        static ControladorSuscripciones* getInstance();

        vector<string> obtenerNombresSuscripcionesActivas();
        vector<DtSuscripcion*> obtenerSuscripcionesActivas();
        vector<DtSuscripcion*> obtenerSuscripcionesNoActivas();
        bool VerificarSuscripcionVitalicia();
        bool VerificarSuscripcionActiva();
        void IngresarDatosSuscripcion(string tiposuscripcion, DtPago pag);
        void SeleccionarVideojuego(string Juego);
        void Finalizarproceso(); 
        void ConfirmarSuscripcion();
        void Cancelar();
        ~ControladorSuscripciones();
};

#endif