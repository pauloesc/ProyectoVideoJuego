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

public:
    static ControladorEstadistica* getInstance();
    vector<string> JuegosDelDesarollador();
    vector<DataEstadisticaDeSegundoTipo> SeleccionEstadisticasDeCiertoJuego(nombreJuego:string);
    
}
 
#endif