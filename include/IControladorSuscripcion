#ifndef ICONTROLADORSUSCRIPCION
#define ICONTROLADORSUSCRIPCION

#include <string>
#include <vector>

#include "DtSuscripcion.h"




using namespace std;


class IControladorSuscripciones {
    
    public:
        
        virtual vector<string> obtenerNombresSuscripcionesActivas()=0;
        virtual vector<DtSuscripcion*> obtenerSuscripcionesActivas()=0;
        virtual vector<DtSuscripcion*> obtenerSuscripcionesNoActivas()=0;
        virtual void IngresarDatosSuscripcion(string tiposuscripcion, DtPago pag)=0;
        virtual void SeleccionarVideojuego(string Juego)=0;
        virtual void Finalizarproceso()=0;
        virtual void ConfirmarSuscripcion()=0;
        virtual void Cancelar()=0;
};

#endif
