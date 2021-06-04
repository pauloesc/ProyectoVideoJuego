#include "Usuario.h"


Usuario::Usuario (string unEmail, string unaContraseña) {
	email = unEmail;
	contraseña = unaContraseña;
}

string Usuario::getemail () {
	return email;
}

string Usuario::getcontraseña() {
	return contraseña;
}

bool Usuario::esJugador() {
	return true; //no se si era asi esta función
}