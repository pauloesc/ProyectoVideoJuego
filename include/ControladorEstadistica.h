#ifndef CONTROLADORESTADISTICA
#define CONTROLADORESTADISTICA

#include "../include/IControladorEstadistica.h"


#include <string>
#include <vector>


#include "ControladorUsuario.h"
#include "ControladorVideojuego.h"
#include "Desarrollador.h"
#include "Videojuego.h"
#include "DtEstadisticaDeSegundoTipo.h"
#include "Estadistica.h"
#include "DataEstadistica.h"

#include "TotalJugadoresSuscriptos.h"
#include "TotalHorasJugadas.h"

using namespace std;

class IControladorEstadistica;

class ControladorEstadistica : public IControladorEstadistica {

private:
    static ControladorEstadistica* instance;
    
    vector<Estadistica*> EstadisticasDelSistema;

    //momoria caso de uso seleccionar estadistica
    vector<string> EstadisticasSeleccionadas;

    ControladorEstadistica();

public:
    static ControladorEstadistica* getInstance();
    vector<string> JuegosDelDesarollador();
    vector<DtEstadisticaDeSegundoTipo*> SeleccionEstadisticasDeCiertoJuego(string nombreJuego);
    
    vector<DataEstadistica> TiposDeEstadistica();
    void SeleccionEstadisticas( vector<string> elecciones );
    void ConfirmarSeleccionEstaditicas();
    void CancelarSeleccionEstaditicas();
    ~ControladorEstadistica();
    
};
 
#endif