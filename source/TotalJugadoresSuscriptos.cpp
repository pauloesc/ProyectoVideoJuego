#include "../include/TotalHorasJugadas.h"


DtEstadisticaDeSegundoTipo* TotalHorasJugadas::DarEstadistica(VideoJuego* vjp){
    
    ControladorUsuario* ControlUsuario;
    ControlUsuario = ControladorUsuario::getInstance();
    
    int cantSusc = ControlUsuario->totalSuscriptos(vjp)
    
    DtEstadisticaDeSegundoTipo* infoRetornar = new DtEstadisticaDeSegundoTipo( vjp->getNombre(), cantSusc );
    return infoRetornar;
}
