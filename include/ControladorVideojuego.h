#ifndef CONTROLADORVIDEOJUEGO
#define CONTROLADORVIDEOJUEGO

#include Videojuego.h
#include DtVideojuego.h
#include DtCategoria.h
#include Categoria.h
#include DtInfoEspecifica.h
#include DtVideoJuegoResumido.h
#include <vector>
#include <string>

using namespace std;

class ControladorVideojuego {

private:
static ControladorVideojuego * instance;
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
DtCategoria* datacat;




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

vector<string> DarJuegos(string email); //caso uso estadistica

vector<string> ObtenerCategorias(); //caso de uso agregar categorias
void NuevaCategoria(DtCategoria* datos);
void ConfirmarCategoria();
void CancelarCategoria();

vector<string> ObtenerVideoJuegos(); //caso uso ver info de videojuego
DtInfoEspecifica* SeleccionarVideojuego(string nombVJ);
int MostrarHorasTotalJugadas();

vector<DtVideoJuegoResumido*> ObtenerVideoJuegos(); //asignar puntaje
void AsignarPuntajeVJ (string nomVJ; int puntaje);


~ControladorVideoJuego();
//string getTipo(); //de donde es?
}

#endif