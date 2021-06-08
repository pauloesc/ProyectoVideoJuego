#ifndef CONTROLADORESTADISTICA
#define CONTROLADORESTADISTICA

#include <string>
#include <vector>

#include "ControladorUsuario.h"
#include "ControladorVideojuego.h"
#include "Desarrollador.h"
#include "Videojuego.h"
#include "DataEstadisticaDeSegundoTipo.h"
#include "Estadistica.h"

using namespace std;


class ControladorEstadistica {

private:
    static ControladorEstadistica* instance;
    
    vector<Estadistica*> EstadisticasDelSistema;

    //momoria caso de uso seleccionar estadistica
    vector<string> EstadisticasSeleccionadas;

public:
    static ControladorEstadistica* getInstance();
    vector<string> JuegosDelDesarollador();
    vector<DataEstadisticaDeSegundoTipo> SeleccionEstadisticasDeCiertoJuego(string nombreJuego);
    
    vector<DataEstadistica> TiposDeEstadistica();
    SeleccionEstadisticas( vector<strings> elecciones );
    ConfirmarSeleccionEstaditicas();
    CancelarSeleccionEstaditicas();
    
}
 
#endif