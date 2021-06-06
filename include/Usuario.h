#ifndef USUARIO
#define USUARIO

#include <string>

class Usuario {
	private:
		string email;
		string contrasenia;
	public:
		Usuario (string unEmail, string unaContrasenia);
		string getemail();
		string getcontrasenia();
		virtual bool esJugador();
};

#endif