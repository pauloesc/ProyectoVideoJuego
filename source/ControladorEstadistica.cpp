#include "../include/ControladorEstadistica.h"

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
    InstanciaDesarollador = ControlUsuario->darDesarrollador();
    
    string nombDes;
    nombDes = InstanciaDesarollador->getemail();
    
    ControladorVideojuego* ControlVideojuego;
    ControlVideojuego = ControladorVideojuego::getInstance();
 
    vector<string>  infoRetornar;
    infoRetornar = ControlVideojuego->DarJuegos(nombDes);
    
    return infoRetornar;
    
}

vector<DtEstadisticaDeSegundoTipo*> SeleccionEstadisticasDeCiertoJuego(string nombreJuego){
    
    ControladorUsuario* ControlUsuario;
    ControlUsuario = ControladorUsuario::getInstance();
    
    Desarrollador* InstanciaDesarollador;
    InstanciaDesarollador = ControlUsuario->darDesarrollador();
    
    ControladorVideojuego* ControlVideojuego;
    ControlVideojuego = ControladorVideojuego::getInstance();
    
    Videojuego* vj =0;
    vj = ControlVideojuego->darVideojuego(nombreJuego);
    
    vector<DtEstadisticaDeSegundoTipo*> vectorRetornar;
    vectorRetornar = InstanciaDesarollador->DarEstadisticas(vj);
    
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


void SeleccionEstadisticas( vector<string> elecciones ){
    EstadisticasSeleccionadas = elecciones;
}

void ConfirmarSeleccionEstaditicas(){

    ControladorUsuario* ControlUsuario;
    ControlUsuario = ControladorUsuario::getInstance();

    vector<Estadistica*> VectorDePunterosAEstadisticasEspecificas;


    for(int i=0; EstadisticasSeleccionadas.size(); i++ ){

        for(int j=0; EstadisticasDelSistema.size(); j++ ){

            if( EstadisticasSeleccionadas[i].getNombre() == EstadisticasDelSistema[j]->getNombre() ){

                VectorDePunterosAEstadisticasEspecificas.push_back( EstadisticasDelSistema[j] );

            }
    
        }

    }

    ControlUsuario.asignarEstadisticas( VectorDePunterosAEstadisticasEspecificas );

}

void CancelarSeleccionEstaditicas(){
    EstadisticasSeleccionadas.clear();
    }
    