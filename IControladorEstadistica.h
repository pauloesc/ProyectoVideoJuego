#ifndef ICONTROLADORESTADISTICA
#define ICONTROLADORESTADISTICA

#include <string>
#include <vector>


#include "DtEstadisticaDeSegundoTipo.h"
#include "DataEstadistica.h"

using namespace std;


class IControladorEstadistica {

public:
   
    virtual vector<string> JuegosDelDesarollador()=0;
    virtual vector<DtEstadisticaDeSegundoTipo*> SeleccionEstadisticasDeCiertoJuego(string nombreJuego)=0;
    
    virtual vector<DataEstadistica> TiposDeEstadistica()=0;
    virtual void SeleccionEstadisticas( vector<string> elecciones )=0;
    virtual void ConfirmarSeleccionEstaditicas()=0;
    virtual void CancelarSeleccionEstaditicas()=0;
    
};
 
#endif
