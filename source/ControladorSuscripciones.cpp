#include "ControladorSuscripciones.h"

using namespace std;

ControladorSuscripciones* ControladorSuscripciones::Instance = NULL;


ControladorSuscripciones* ControladorSuscripciones::getInstance() {
    if (ControladorSuscripciones::Instance == NULL) {
        ControladorSuscripciones::Instance = new ControladorSuscripciones;
    } 
    return ControladorSuscripciones::Instance
}



vector<DtSuscripcion*> ControladorSuscripciones::obtenerSuscripcionesActivas() {
    ControladorUsusario* cu = ControladorUsuario::getInstance();
    Jugador* jug = cu->darJugador();
    return jug->darSuscripcionesActivas();
}

vector<DtSuscripcion*> ControladorSuscripciones::obtenerNombresSuscripcionesActivas() {
    vector<DtSuscripcion*> aux = this->obtenerSuscripcionesActivas();
    vector<string> res;

    for (int i = 0; i < aux.size(); i++) {
       res.push_back(aux[i]->getNombre());
    }
    return res;
}

vector<DtSuscripcion*> ControladorSuscripciones::obtenerSuscripcionesNoActivas() {
    vector<DtSuscripcion*> susActivas =  this->obtenerSuscripcionesActivas();
    
    vector<DtSuscripcion*> res;
    vector<DtSuscripcion*> inter;
    
    ControladorVideojuego* cvj = ControladorVideojuego::getInstance();
    vector<Videojuego*> vidoejue = cvj->DarVideojuegos();
   
    
    // todas las posibles suscripciones
    for (int i = 0; i < videojue.size(); i++) {
        inter = videojue[i]->crearDtsuscripcion();
        for (int j = 0; j < inter.size(); i++) {
            res.push_back(inter[j]);
        }

        // libero memoria
        for (int p = 0; i < inter.size(); p++) {
            delete inter[p]
        }
    }

    
    // diferencia de conjuntos
    bool borro = false;
    int y = 0;
    while (y < res.size()) {  // no se puede usar for porque modificaria la guarda en tiempo de ejecucion
        for (int j = 0; j < susActivas.size(); j++) {
            if ((res[y]->getNombre() == susActivas[j]->getNombre()) and (res[y]->getTipoSuscripcion() == susActivas[j]->getTipoSuscripcion())) {
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
    for (int i = 0; i < susActivas.size(); i++) {
        delete susActivas[i]
    }
    

    return res;
}

void ControladorSuscripciones::IngresarDatosSuscripcion(string tiposuscripcion, DtPago *pag) {
    tiposus = tiposuscripcion;
    pago = pag;
}

void ControladorSuscripciones::SeleccionarVideojuego(string Juego) {
    ControladorVideojuego* cvj = ControladorVideojuego::getInstance();
    vj = cvj->darVideojuego(Juego);
    nomJ = Juego;
}


void ControladorSuscripciones::ConfirmarSuscripcion() {
    ControladorUsusario* cu = ControladorUsuario::getInstance();
    Jugador* jug = cu->darJugador();
    jug->cancelarSuscripcionActiva(this->nomJ);
    
    
    // revisar Suscripcion, errores en los constructores
    Suscripcion* sus = crearSuscripcion()

    jug->asociarSuscripcion(sus); 


}

void ControladorSuscripciones::Cancelar() {
}

