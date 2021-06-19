
#ifndef FABRICA
#define FABRICA

#include "ControladorUsuario.h"
#include "ControladorVideojuego.h"
#include "ControladorSuscripciones.h"
#include "ControladorPartida.h"
#include "ControladorEstadistica.h"

#include "IControladorUsuario.h"
#include "IControladorVideojuego.h"
#include "IControladorSuscripciones.h"
#include "IControladorPartida.h"
#include "IControladorEstadistica.h"


class Fabrica {

private:
	static IControladorUsuario* IUsuario;
	static IControladorVideojuego* IVideojuego;
	static IControladorSuscripciones* ISuscripcion;
	static IControladorPartida* IPartida;
	static IControladorEstadistica* IEstadistica;

	static void destruirFabrica(); //ejecutada una vez al final del programa

public:
	static IControladorUsuario* getIUsuario();
	static IControladorVideojuego* getIVideojuego();
	static IControladorSuscripciones* getISuscripcion();
	static IControladorPartida* getIPartida();
	static IControladorEstadistica* getIEstadistica();


};




#endif