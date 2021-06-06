#ifndef CONTROLADORVIDEOJUEGO
#define CONTROLADORVIDEOJUEGO

#include Videojuego.h
#include <vector>
#include <string>

using namespace std;

class ControladorVideojuego {

private:
static ControladorVideojuego * instance;
ControladorVideojuego();
vector<Videojuego*> Videojuegos;
static string nombreJuego;
static string descrip;
static float costoMensual;
static float costoTrimestral;
static float costoAnual;
static float costoVitalicia;
static DtCategoria categoria;
static vector<string> cats;


public:
static ControladorUsuario * getInstance();

void datosVideojuego(string nombreJuego, string descrip, float costoMensual, float costoTrimestral, float costoAnual, float costoVitalicia); //publicar videojuego
vector<DtCategoria> ObtenerCategoriaPlataforma();
vector<DtCategoria> ObtenerCategoriaGenero();
vector<DtCategoria> ObtenerCategoriaOtros(); 
void agregarcategoria (string categoria);
DtVideojuego ObtenerInfoVideojuego();
void ConfirmarAltavideoJuego();
void CancelarAltavideoJuego();
string getTipo();
Videojuego* darVideojuego(string Juego); 
void seleccionarVideoJuego(string nomVJ); 
vector<string> obtenerVideoJuegosConTodasLasPartidasFinalizadas();
void cancelarLaEliminacion();
void eliminarVideoJuego();
vector<string> busquedaVideojuegos(string criterio);

}