#ifndef CONTROLADORSUSCRIPCION
#define CONTROLADORSUSCRIPCION

#include <string>
#include <map>
#include <vector>
#include <iterator>

#include "Suscripcion.h"
#include "Jugador.h"
#include "DtSuscripcion.h"



class ControladorSuscripciones {
    private:
        static ControladorSuscripcion* instance;
        static Videojuego vj;
        static string tiposus;
        static DtPago pago;
    public:
        vector<DtSuscripcion> obtenerNombresSuscripcionesActivas();
        vector<DtSuscripcion> obtenerSuscripcionesNoActivas();
        void IngresarDatosSuscripcion(string tiposuscripcion, DtPago pag);
        void SeleccionarVideojuego(string Juego);
        void IngresarDatosSuscripcion(string tiposuscripcion, DtPago pag);
        vector<string> obtenerNombresSuscripcionesActivas();
        void Finalizarproceso();
        void ConfirmarSuscripcion();
        void Cancelar();
        int totalSuscriptos(VideoJuego v);     
}

#endif