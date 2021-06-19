#ifndef ICONTROLADORVIDEOJUEGO
#define ICONTROLADORVIDEOJUEGO




#include <vector>
#include <string>

using namespace std;

#include "DtVideojuego.h"
#include "DtCategoria.h"
#include "DtInfoEspecifica.h"
#include "DtVideojuegoResumido.h"
#include "DtSuscripcion.h"



class IControladorVideojuego {

public:

virtual void datosVideojuego(string nombreJuego, string descrip, float costoMensual, float costoTrimestral, float costoAnual, float costoVitalicia)=0; //publicar videojuego
virtual vector<DtCategoria*> ObtenerCategoriaPlataforma()=0;
virtual vector<DtCategoria*> ObtenerCategoriaGenero()=0;
virtual vector<DtCategoria*> ObtenerCategoriaOtros()=0; 
virtual void agregarcategoria (string categoria)=0;
virtual DtVideojuego* ObtenerInfoVideojuego()=0;
virtual void ConfirmarAltavideoJuego()=0;
virtual void CancelarAltavideoJuego()=0;

virtual vector<string> obtenerVideoJuegosConTodasLasPartidasFinalizadas()=0; //eliminar videojuego
virtual void seleccionarVideoJuego(string nomVJ)=0; 
virtual void eliminarVideoJuego()=0;
virtual void cancelarLaEliminacion()=0;


virtual vector<string> ObtenerCategorias()=0; //caso de uso agregar categorias
virtual void NuevaCategoria(DtCategoria* datos)=0;
virtual void ConfirmarCategoria()=0;
virtual void CancelarCategoria()=0;


virtual vector<string> ObtenerVideoJuegosString()=0; //caso uso ver info de videojuego

virtual DtInfoEspecifica* SeleccionarVideojuego(string nombVJ)=0;
virtual float MostrarHorasTotalJugadas()=0;

virtual vector<DtVideojuegoResumido*> ObtenerVideoJuegos()=0; //asignar puntaje
virtual void AsignarPuntajeVJ(string nomVJ, int puntaje)=0;

virtual ~IControladorVideojuego(){};

};

#endif
