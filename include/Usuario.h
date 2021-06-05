#ifndef USUARIO
#define USUARIO

#include <string>

class Usuario {
	private:
		string email;
		string contraseña;
	public:
		Usuario (string unEmail, string unaContraseña);
		string getemail();
		string getcontraseña();
		virtual bool esJugador();
};

#endif