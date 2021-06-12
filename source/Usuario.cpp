#include "../include/Usuario.h"


Usuario::Usuario (string unEmail, string unaContrasenia) {
	email = unEmail;
	contrasenia = unaContrasenia;
}

string Usuario :: getemail () {
	return email;
}

string Usuario :: getcontrasenia () {
	return contrasenia;
}