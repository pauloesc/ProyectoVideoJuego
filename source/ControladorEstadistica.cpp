#include "../include/ControladorEstadistica.h"


ControladorEstadistica* ControladorEstadistica::instance = NULL; 


ControladorEstadistica* ControladorEstadistica::getInstance() {
 if (instance == NULL)
 instance = new ControladorEstadistica();
 return instance;
} 

ControladorEstadistica::ControladorEstadistica() {

    Estadistica* e1 = new TotalJugadoresSuscriptos("Total de jugadores suscriptos", "Calcula la cantidad de jugadores suscritos a un videojuego");
    Estadistica* e2 = new TotalHorasJugadas("Total de horas jugadas", "Calcula la cantidad de horas que se juego a un determinado videojuego");

    EstadisticasDelSistema.push_back(e1);
    EstadisticasDelSistema.push_back(e2);
} 


vector<string> ControladorEstadistica::JuegosDelDesarollador(){
 
    ControladorUsuario* ControlUsuario;
    ControlUsuario = ControladorUsuario::getInstance();

    Desarrollador* InstanciaDesarollador;
    InstanciaDesarollador = ControlUsuario->darDesarrollador();
    
    string nombDes;
    nombDes = InstanciaDesarollador->getemail();
    
    ControladorVideojuego* ControlVideojuego;
    ControlVideojuego = ControladorVideojuego::getInstance();
 
    vector<string>  infoRetornar;
    infoRetornar = ControlVideojuego->DarJuegos(nombDes);
    
    return infoRetornar;
    
}

vector<DtEstadisticaDeSegundoTipo*> ControladorEstadistica::SeleccionEstadisticasDeCiertoJuego(string nombreJuego){
    
    ControladorUsuario* ControlUsuario;
    ControlUsuario = ControladorUsuario::getInstance();
    
    Desarrollador* InstanciaDesarollador;
    InstanciaDesarollador = ControlUsuario->darDesarrollador();
    
    ControladorVideojuego* ControlVideojuego;
    ControlVideojuego = ControladorVideojuego::getInstance();
    
    Videojuego* vj =0;
    vj = ControlVideojuego->darVideojuego(nombreJuego);
    
    vector<DtEstadisticaDeSegundoTipo*> vectorRetornar;

    if( vj != 0){
        vectorRetornar = InstanciaDesarollador->DarEstadisticas(vj);
    }
    
    return vectorRetornar;
}

vector<DataEstadistica> ControladorEstadistica::TiposDeEstadistica(){


    vector<DataEstadistica> infoRetornar;

    int maxx = EstadisticasDelSistema.size(); 
    for( int i=0; i< maxx; i++ ){

        infoRetornar.push_back( DataEstadistica(    EstadisticasDelSistema[i]->getNombre(),
                                                    EstadisticasDelSistema[i]->getDescripcion() ));

    }

    return infoRetornar;

}


void ControladorEstadistica::SeleccionEstadisticas( vector<string> elecciones ){
    EstadisticasSeleccionadas = elecciones;
}

void ControladorEstadistica::ConfirmarSeleccionEstaditicas(){

    ControladorUsuario* ControlUsuario;
    ControlUsuario = ControladorUsuario::getInstance();

    vector<Estadistica*> VectorDePunterosAEstadisticasEspecificas;


    int max1 = EstadisticasSeleccionadas.size();
    for(int i=0; i < max1; i++ ){

        int max2 = EstadisticasDelSistema.size();
        for(int j=0; j < max2; j++ ){

            if( EstadisticasSeleccionadas[i] == EstadisticasDelSistema[j]->getNombre() ){

                VectorDePunterosAEstadisticasEspecificas.push_back( EstadisticasDelSistema[j] );

            }
    
        }

    }

    ControlUsuario->asignarEstadisticas( VectorDePunterosAEstadisticasEspecificas );

}

void ControladorEstadistica::CancelarSeleccionEstaditicas(){
    EstadisticasSeleccionadas.clear();
}

ControladorEstadistica::~ControladorEstadistica(){

    int max = EstadisticasDelSistema.size();
    for(int i=0; i< max; i++ ){
        delete EstadisticasDelSistema[i];
    }
    EstadisticasDelSistema.clear();
}