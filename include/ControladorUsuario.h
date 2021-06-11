#ifndef CONTROLADORUSUARIO
#define CONTROLADORUSUARIO

#include "Usuario.h"
#include "Jugador.h"
#include "Desarrollador.h"
#include "Videojuego.h"

#include "DtPartidaMultijugador.h"

#include <string>
#include <vector>

using namespace std;


class ControladorUsuario {

private:
static ControladorUsuario* instance;
ControladorUsuario(); //tiene que ir protected?
vector<Usuario*> Usuarios;
string email;
string contrasenia;
string nomEmpresa;
bool desarrollador;
string nickname;
string desc;
Usuario* uenlinea;

public:
static ControladorUsuario* getInstance();

void IngresardatosUsuario(string email, string contrasenia); //caso de uso Alta usuario
void IngresardatosDesarrollador(string nomEmpresa);
bool IngresardatosJugador(string nickname, string desc);
void ConfirmarAltaUsuario();
void cancelarAltaUsuario();

bool ingresarDatos(string email, string contrasenia); //caso de uso iniciar sesion
Jugador* darJugador(); 
Desarrollador* darDesarrollador();

vector<string> darNombreJugadoresConSuscripcionActiva(string nombrevid); //caso de uso iniciar partida
vector<Jugador*> darJugadores(vector<string> jugadoresUnidos); 
void eliminarSuscripcionesVideoJuego(string nomVJ); //caso de uso eliminar videojuego
int totalSuscriptos(Videojuego* v);  //caso de uso consultar estadistica2

vector<DtPartidaMultijugador*> obtenerPartidasEnCursoUnido(); //caso de uso abandonar partida
void jugadorAbandona(int identificador);

bool esUsuarioEnLineaJugador(); //sirve para ver info videojuego


~ControladorUsuario();

//paulo agregue lo siguente 
void asignarEstadisticas( vector<Estadistica*> VectorDePunterosAEstadisticasEspecificas );

};

#endif
