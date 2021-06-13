#ifndef ICONTROLADORUSUARIO
#define ICONTROLADORUSUARIO


#include <string>
#include <vector>

using namespace std;


class IControladorUsuario {

public:

virtual void IngresardatosUsuario(string email, string contrasenia)=0;
virtual void IngresardatosDesarrollador(string nomEmpresa)=0;
virtual bool IngresardatosJugador(string nickname, string desc)=0;
virtual void ConfirmarAltaUsuario()=0;
virtual void cancelarAltaUsuario()=0;

virtual bool ingresarDatos(string email, string contrasenia)=0; //caso de uso iniciar sesion

virtual bool esUsuarioEnLineaJugador()=0; //lo va pedir tambien la capa presentacion


virtual~IControladorUsuario(){};

};

#endif
