#ifndef CONTROLADORUSUARIO
#define CONTROLADORUSUARIO

#include ".../include/Usuario.h"
using namespace std;
#include <string>
#include <vector>

class ControladorUsuario {

private:
static ControladorUsuario* instance;
ControladorUsuario(); //tiene que ir protected?
vector<Usuario*> Usuarios;
static string email;
static string contrasenia;
static string nomEmpresa;
static bool desarrollador;
static string nickname;
static string desc;
static Usuario* uenlinea;

public:
static ControladorUsuario* getInstance();

void IngresardatosUsuario(string email, string contrasenia); //caso de uso Alta usuario
void IngresardatosDesarrollador(string nomEmpresa);
bool IngresardatosJugador(string nickname, string desc);
void ConfirmarAltaUsuario();
void cancelarAltaUsuario();

bool ingresarDatos(string email, string contrasenia) //caso de uso iniciar sesion
Jugador* darJugador(); 
Desarrollador* darDesarrollador();

vector<string> darNombreJugadoresConSuscripcionActiva(string nombrevid);
vector<Jugadores*> darJugadores(vector<string> jugadoresUnidos); 
void eliminarSuscripcionesVideoJuego(string nomVJ);

~ControladorUsuario();
}
