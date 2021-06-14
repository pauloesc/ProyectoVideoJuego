#include "../include/Fabrica.h"

//creando las interfaces (unicas)
IControladorUsuario* Fabrica::IUsuario = ControladorUsuario::getInstance();
IControladorVideojuego* Fabrica::IVideojuego = ControladorVideojuego::getInstance();
IControladorSuscripciones* Fabrica::ISuscripcion = ControladorSuscripciones::getInstance();
IControladorPartida* Fabrica::IPartida = ControladorPartida::getInstance();
IControladorEstadistica* Fabrica::IEstadistica = ControladorEstadistica::getInstance();


IControladorUsuario* Fabrica::getIUsuario() {
	return IUsuario;
}

IControladorVideojuego* Fabrica::getIVideojuego() {
	return IVideojuego;
}

IControladorSuscripciones* Fabrica::getISuscripcion() {
	return ISuscripcion;
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