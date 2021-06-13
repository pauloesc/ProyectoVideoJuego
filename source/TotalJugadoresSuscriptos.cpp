#include "../include/TotalJugadoresSuscriptos.h"

TotalJugadoresSuscriptos::TotalJugadoresSuscriptos(string nom, string des) : Estadistica(nom,des) {
}

DtEstadisticaDeSegundoTipo* TotalJugadoresSuscriptos::DarEstadistica(Videojuego* vjp) {
    
    ControladorUsuario* ControlUsuario = ControladorUsuario::getInstance();
    
    float cantSusc = ControlUsuario->totalSuscriptos(vjp);
    
    DtEstadisticaDeSegundoTipo* infoRetornar = new DtEstadisticaDeSegundoTipo(vjp->getNombre(), cantSusc);
    return infoRetornar;
}

TotalJugadoresSuscriptos::~TotalJugadoresSuscriptos(){
    
}