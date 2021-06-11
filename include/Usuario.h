#ifndef USUARIO
#define USUARIO

#include <string>

using namespace std;


class Usuario {
	private:
		string email;
		string contrasenia;
	public:
		Usuario (string unEmail, string unaContrasenia);
		string getemail();
		string getcontrasenia();
		virtual bool esJugador();

		virtual ~Usuario() = 0;
};

#endif