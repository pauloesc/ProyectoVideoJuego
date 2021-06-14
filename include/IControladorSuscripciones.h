#ifndef ICONTROLADORSUSCRIPCIONES
#define ICONTROLADORSUSCRIPCIONES

#include <string>
#include <vector>

#include "DtSuscripcion.h"
#include "DtPago.h"
#include "DtFecha.h"





using namespace std;


class IControladorSuscripciones {
    
    public:
        
        virtual vector<string> obtenerNombresSuscripcionesActivas()=0;
        virtual vector<DtSuscripcion*> obtenerSuscripcionesActivas()=0;
        virtual vector<DtSuscripcion*> obtenerSuscripcionesNoActivas()=0;
        virtual bool VerificarSuscripcionVitalicia()=0;
        virtual void IngresarDatosSuscripcion(string tiposuscripcion, DtPago pag)=0;
        virtual void SeleccionarVideojuego(string Juego)=0;
        virtual void Finalizarproceso()=0;
        virtual void ConfirmarSuscripcion()=0;
        virtual void ConfirmarSuscripcion(DtFecha* d)=0; // para cargar los datos de "inicio"
        virtual void Cancelar()=0;
        virtual~IControladorSuscripciones(){};
};

#endif
