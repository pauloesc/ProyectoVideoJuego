#include "../include/TotalHorasJugadas.h"

TotalHorasJugadas::TotalHorasJugadas(string nom, string desc) : Estadistica(nom,desc) {
}

DtEstadisticaDeSegundoTipo* TotalHorasJugadas::DarEstadistica(Videojuego* vjp){
    
    DtEstadisticaDeSegundoTipo* infoRetornar = new DtEstadisticaDeSegundoTipo( this->getNombre(), vjp->totalHorasJugadas() );
    return infoRetornar;
}

TotalHorasJugadas::~TotalHorasJugadas(){
    
}