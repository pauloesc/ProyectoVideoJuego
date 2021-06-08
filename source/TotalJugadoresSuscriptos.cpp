DataEstadisticaDeSegundoTipo TotalHorasJugadas::DarEstadistica(VideoJuego* vjp){
    
    ControladorUsuario* ControlUsuario;
    ControlUsuario = ControladorUsuario::getInstance();
    
    int cantSusc = ControlUsuario->totalSuscriptos(vjp)
    
    DataEstadisticaDeSegundoTipo infoRetornar( vjp->getNombre(), cantSusc );
    return infoRetornar;
}
