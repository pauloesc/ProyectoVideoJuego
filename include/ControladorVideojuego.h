#ifndef CONTROLADORVIDEOJUEGO
#define CONTROLADORVIDEOJUEGO

#include "Videojuego.h"
#include "Categoria.h"
#include "ControladorPartida.h"
#include "ControladorUsuario.h"
#include "Usuario.h"
#include "Desarrollador.h"

#include "DtVideojuego.h"
#include "DtCategoria.h"
#include "DtInfoEspecifica.h"
#include "DtVideojuegoResumido.h"


#include <vector>
#include <string>

using namespace std;

class ControladorVideojuego {

private:
static ControladorVideojuego* instance;
ControladorVideojuego();
vector<Videojuego*> Videojuegos;
vector<Categoria*> Categorias;
string nombreJuego;
string descrip;
float costoMensual;
float costoTrimestral;
float costoAnual;
float costoVitalicia;
vector<string> cats;
Videojuego* vid;
DtCategoria* datac;




public:
static ControladorVideojuego* getInstance();

void datosVideojuego(string nombreJuego, string descrip, float costoMensual, float costoTrimestral, float costoAnual, float costoVitalicia); //publicar videojuego
vector<DtCategoria*> ObtenerCategoriaPlataforma();
vector<DtCategoria*> ObtenerCategoriaGenero();
vector<DtCategoria*> ObtenerCategoriaOtros(); 
void agregarcategoria (string categoria);
DtVideojuego* ObtenerInfoVideojuego();
void ConfirmarAltavideoJuego();
void CancelarAltavideoJuego();

Videojuego* darVideojuego(string Juego); //caso de uso suscripcion y iniciar partida y estadistica
vector<string> obtenerVideoJuegosConTodasLasPartidasFinalizadas(); //eliminar videojuego
void seleccionarVideoJuego(string nomVJ); 
void eliminarVideoJuego();
void cancelarLaEliminacion();

vector<string> DarJuegos(string email); //caso uso estadistica

vector<string> ObtenerCategorias(); //caso de uso agregar categorias
void NuevaCategoria(DtCategoria* datos);
void ConfirmarCategoria();
void CancelarCategoria();


//vector<string> ObtenerVideoJuegos(); //caso uso ver info de videojuego
//esta funcion generaba un problema que es el siguiente tiene el mismo nombre q otra funcion que esta mas abajo
vector<string> ObtenerVideoJuegosString(); //caso uso ver info de videojuego

DtInfoEspecifica* SeleccionarVideojuego(string nombVJ);
int MostrarHorasTotalJugadas();

vector<DtVideojuegoResumido*> ObtenerVideoJuegos(); //asignar puntaje
void AsignarPuntajeVJ(string nomVJ, int puntaje);


~ControladorVideojuego();
//string getTipo(); //de donde es?
};

#endif