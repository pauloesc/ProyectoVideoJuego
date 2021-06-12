DtEstadisticaDeSegundoTipo* TotalHorasJugadas::DarEstadistica(VideoJuego* vjp){
    
    DtEstadisticaDeSegundoTipo* infoRetornar = new DtEstadisticaDeSegundoTipo( vjp->getNombre(), vjp->totalHorasJugadas() );
    return infoRetornar;
}
