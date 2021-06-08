DataEstadisticaDeSegundoTipo TotalHorasJugadas::DarEstadistica(VideoJuego* vjp){
    
    DataEstadisticaDeSegundoTipo infoRetornar( vjp->getNombre(), vjp->totalHorasJugadas() );
    return infoRetornar;
}
