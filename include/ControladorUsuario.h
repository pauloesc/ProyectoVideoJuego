#ifndef CONTROLADORUSUARIO
#define CONTROLADORUSUARIO

#include ".../include/Usuario.h"
#include <vector>

class ControladorUsuario {

private:
static ControladorUsuario * instancia;
ControladorUsuario();
vector<Usuario*> Usuarios;

public:
static ControladorUsuario * getInstancia();
void operacion();
void IngresardatosUsuario(string email, string contrasenia);
void IngresardatosDesarrollador(string nomEmpresa);
bool IngresardatosJugador(string nickname, string desc);
void ConfirmarAltaUsuario();
void cancelarAltaUsuario();
Jugador* darJugador(); 
vector<string> darNombreJugadoresConSuscripcionActiva(string nombrevid);
vector<Jugadores*> darJugadores(jugadoresUnidos:set(string)); 
Desarrollador* darDesarrollador();
void eliminarSuscripcionesVideoJuego(string nomVJ);
}
