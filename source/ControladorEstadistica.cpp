ControladorEstadistica* ControladorEstadistica::instance = NULL; 


ControladorEstadistica* ControladorEstadistica::getInstance() {
 if (instance == NULL)
 instance = new ControladorEstadistica();
 return instance;
} 


vector<string> ControladorEstadistica::JuegosDelDesarollador(){
 
    ControladorUsuario* ControlUsuario;
    ControlUsuario = ControladorUsuario::getInstance();

    Desarrollador* InstanciaDesarollador;
    InstanciaDesarollador = ControlUsuario.darDesarrollador();
    
    string nombDes;
    nombDes = InstanciaDesarollador->getEmail();
    
    ControladorVideojuego* ControlVideojuego;
    ControlVideojuego = ControladorUsuario::getInstance();
 
    vector<string>  infoRetornar;
    infoRetornar = ControlVideojuego->DarJuegos(nombDes);
    
    return infoRetornar;
    
}

vector<DataEstadisticaDeSegundoTipo> SeleccionEstadisticasDeCiertoJuego(string nombreJuego){
    
    ControladorUsuario* ControlUsuario;
    ControlUsuario = ControladorUsuario::getInstance();
    
    Desarrollador* InstanciaDesarollador;
    InstanciaDesarollador = ControlUsuario.darDesarrollador();
    
    ControladorVideojuego* ControlVideojuego;
    ControlVideojuego = ControladorUsuario::getInstance();
    
    Videojuego* vj =0;
    vj = ControlVideojuego->darVideoJuego(nombreJuego);
    
    vector<DataEstadisticaDeSegundoTipo> vectorRetornar;
    vectorRetornar = InstanciaDesarollador.DarEstardisticas(vj);
    
    return vectorRetornar;
    
}

vector<DataEstadistica> TiposDeEstadistica(){


    vector<DataEstadistica> infoRetornar{

    for( int i=0; i< EstadisticasDelSistema.size(); i++ ){

        infoRetornar.push_back( DataEstadistica(    EstadisticasDelSistema[i].getNombre(),
                                                    EstadisticasDelSistema[i].getDescripcion() ));

    }

    return infoRetornar;

}