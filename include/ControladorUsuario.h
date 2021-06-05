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
vector<Usuario*> Usuarios;
static string email;
static string contrasenia;
static string nomEmpresa;
static bool desarrollador;
static string nickname;
static string desc;
static Usuario* uenlinea;

public:
static ControladorUsuario * getInstance();

void IngresardatosUsuario(string email, string contrasenia);
void IngresardatosDesarrollador(string nomEmpresa);
bool IngresardatosJugador(string nickname, string desc);
void ConfirmarAltaUsuario();
void cancelarAltaUsuario();
Jugador* darJugador(); 
vector<string> darNombreJugadoresConSuscripcionActiva(string nombrevid);
vector<Jugadores*> darJugadores(vector<string> jugadoresUnidos); 
Desarrollador* darDesarrollador();
void eliminarSuscripcionesVideoJuego(string nomVJ);
~ControladorUsuario();
}
