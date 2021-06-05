#ifndef CONTROLADORUSUARIO
#define CONTROLADORUSUARIO

#include ".../include/Usuario.h"
using namespace std;
#include <string>
#include <vector>

class ControladorUsuario {

private:
static ControladorUsuario * instance;
ControladorUsuario();
set<Usuario*> Usuarios;
static string email;
static string contrasenia;
static string nomEmpresa;
static bool desarrollador;
static string nickname;
static string desc;

public:
static ControladorUsuario * getInstance();

void IngresardatosUsuario(string email, string contrasenia);
void IngresardatosDesarrollador(string nomEmpresa);
bool IngresardatosJugador(string nickname, string desc);
void ConfirmarAltaUsuario();
void cancelarAltaUsuario();
Jugador* darJugador(); 
set<string> darNombreJugadoresConSuscripcionActiva(string nombrevid);
set<Jugadores*> darJugadores(set<string> jugadoresUnidos); 
Desarrollador* darDesarrollador();
void eliminarSuscripcionesVideoJuego(string nomVJ);
~ControladorUsuario();
}
