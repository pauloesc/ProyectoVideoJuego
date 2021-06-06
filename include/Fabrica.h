// para pedir una interfaz: Fabrica::getITipoInterfaz()
// NO HACER delete a la interfaz, hacer Fabrica::destruirFabrica() al final del programa
#ifndef FABRICA
#define FABRICA

#include "ControladorUsuario.h"
#include "ControladorVideojuego.h"
#include "ControladorSuscripcion.h"
#include "ControladorPartida.h"
#include "ControladorEstadistica.h"

#include "IControladorUsuario.h"
#include "IControladorVideojuego.h"
#include "IControladorSuscripcion.h"
#include "IControladorPartida.h"
#include "IControladorEstadistica.h"


class Fabrica {

private:
	static IControladorUsuario* IUsuario;
	static IControladorVideojuego* IVideojuego;
	static IControladorSuscripcion* ISuscripcion;
	static IControladorPartida* IPartida;
	static IControladorEstadistica* IEstadistica;

	static void destruirFabrica(); //ejecutada una vez al final del programa

public:
	static IControladorUsuario* getIUsuario();
	static IControladorVideojuego* getIVideojuego();
	static IControladorSuscripcion* getISuscripcion();
	static IControladorPartida* getIPartida();
	static IControladorEstadistica* getIEstadistica();


};




#endif