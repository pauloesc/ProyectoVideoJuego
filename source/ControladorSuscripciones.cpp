#include "../include/ControladorSuscripciones.h"

using namespace std;

ControladorSuscripciones* ControladorSuscripciones::Instance = NULL;


ControladorSuscripciones* ControladorSuscripciones::getInstance() {
    if (ControladorSuscripciones::Instance == NULL) {
        ControladorSuscripciones::Instance = new ControladorSuscripciones;
    } 
    return ControladorSuscripciones::Instance;
}



vector<DtSuscripcion*> ControladorSuscripciones::obtenerSuscripcionesActivas() {
    ControladorUsuario* cu = ControladorUsuario::getInstance();
    Jugador* jug = cu->darJugador();
    return jug->darSuscripcionesActivas();
}

vector<string> ControladorSuscripciones::obtenerNombresSuscripcionesActivas() {
    vector<DtSuscripcion*> aux = this->obtenerSuscripcionesActivas();
    vector<string> res;

    for (long unsigned int i = 0; i < aux.size(); i++) {
       res.push_back(aux[i]->getNombre());
    }
    return res;
}

vector<DtSuscripcion*> ControladorSuscripciones::obtenerSuscripcionesNoActivas() {
    vector<DtSuscripcion*> susActivas =  this->obtenerSuscripcionesActivas();
    
    
    // todas las posibles suscripciones
    ControladorVideojuego* cvj = ControladorVideojuego::getInstance();
    vector<DtSuscripcion*> res = cvj->costosDeTodosLosVideojuegos();


    
    // diferencia de conjuntos
    bool borro = false;
    long unsigned int y = 0;
    while (y < res.size()) {  // no se puede usar for porque modificaria la guarda en tiempo de ejecucion
        for (long unsigned int j = 0; j < susActivas.size(); j++) {
            if ((res[y]->getNombre() == susActivas[j]->getNombre()) and (res[y]->getTipoSuscripcion() == susActivas[j]->getTipoSuscripcion()) and !borro) {
                delete res[y];
                res.erase(res.begin() + y);
                borro = true;
            } 
        }

        if (borro) {
            borro = false;
        } else {
            y = y + 1;
        }
   

    }

    //libero memoria "auxiliar"
    for (long unsigned int i = 0; i < susActivas.size(); i++) {
        delete susActivas[i];
    }
    susActivas.clear();    

    return res;
}

void ControladorSuscripciones::IngresarDatosSuscripcion(string tiposuscripcion, DtPago pag) {
    tiposus = tiposuscripcion;
    pago = pag;
}

void ControladorSuscripciones::SeleccionarVideojuego(string Juego) {
    ControladorVideojuego* cvj = ControladorVideojuego::getInstance();
    vj = cvj->darVideojuego(Juego);
    nomJ = Juego;
}


void ControladorSuscripciones::ConfirmarSuscripcion() {
    ControladorUsuario* cu = ControladorUsuario::getInstance();
    Jugador* jug = cu->darJugador();
    jug->cancelarSuscripcionActiva(this->nomJ);
    
    
    Suscripcion* sus;

    if (tiposus == "vitalicia") {
        sus = new SuscripcionVitalicia(Reloj::getFecha(),pago,vj->getCostoVitalicio(),vj,jug);
    } else {
        float cos;
        int val;
        
        if (tiposus == "mensual") {
            cos = vj->getCostoMensual();
            val = 30;
        } else if (tiposus == "trimestral") {
            cos = vj->getCostoTrimestral();
            val = 90;
        } else {
            cos = vj->getCostoAnual();
            val = 365;
        }
   
        sus = new SuscripcionTemporal(Reloj::getFecha(),pago,cos,vj,jug,true,val,false);
    }

    jug->asociarSuscripcion(sus); 


}

void ControladorSuscripciones::Cancelar() {
}

