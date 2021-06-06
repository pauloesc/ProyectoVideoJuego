#ifndef CONTROLADORVIDEOJUEGO
#define CONTROLADORVIDEOJUEGO

#include Videojuego.h
#include DtVideojuego.h
#include DtCategoria.h
#include Categoria.h
#include <vector>
#include <string>

using namespace std;

class ControladorVideojuego {

private:
static ControladorVideojuego * instance;
ControladorVideojuego();
vector<Videojuego*> Videojuegos;
vector<Categoria*> Categorias;
static string nombreJuego;
static string descrip;
static float costoMensual;
static float costoTrimestral;
static float costoAnual;
static float costoVitalicia;
static vector<string> cats;
static Videojuego* vid;
static DtCategoria datacat;




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

Videojuego* darVideojuego(string Juego); //caso de uso suscripcion y iniciar partida y estadistica
vector<string> obtenerVideoJuegosConTodasLasPartidasFinalizadas(); //eliminar videojuego
void seleccionarVideoJuego(string nomVJ); 
void eliminarVideoJuego();
void cancelarLaEliminacion();

vector<string> DarJuegos(nombDes:string); //caso uso estadistica

vector<string> ObtenerCategorias(); //caso de uso agregar categorias
void NuevaCategoria(DtCategoria datos);
void ConfirmarCategoria();
void CancelarCategoria();




~ControladorVideoJuego();
//string getTipo(); //de donde es?
}