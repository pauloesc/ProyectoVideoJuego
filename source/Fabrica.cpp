#include "../include/Fabrica.h"

//creando las interfaces (unicas)
IControladorUsuario* Fabrica::IUsuario = new IControladorUsuario;
IControladorVideojuego* Fabrica::IVideojuego = new IControladorVideojuego;
IControladorSuscripcion* Fabrica::ISuscripcion = new IControladorSuscripcion;
IControladorPartida* Fabrica::IPartida = new IControladorPartida;
IControladorEstadistica* Fabrica::IEstadistica = new IControladorEstadistica;


IControladorUsuario* Fabrica::getIUsuario() {
	return IUsuario;
}

IControladorVideojuego* Fabrica::getIVideojuego() {
	return IVideojuego;
}

IControladorSuscripcion* Fabrica::getISuscripcion() {
	return ISuscripcion
}

IControladorPartida* Fabrica::getIPartida() {
	return IPartida;
}

IControladorEstadistica* Fabrica::getIEstadistica() {
	return IEstadistica;
}


void Fabrica::destruirFabrica() {
	delete IUsuario;
	delete IVideojuego;
	delete ISuscripcion;
	delete IPartida;
	delete IEstadistica;
}