#include "ControladorSuscripciones.h"

vector<DtSuscripcion> ControladorSuscripciones::obtenerSuscripcionesActivas() {
    ControladorUsusario* cu = ControladorUsuario::getInstance();
    Jugador* jug = cu->darJugador();
    return *jug->darSuscripcionesActivas();
}

vector<DtSuscripcion> ControladorSuscripciones::obtenerSuscripcionesNoActivas() {
    vector<DtSuscripcion> susActivas =  obtenerSuscripcionesActivas();
    vector<DtSuscripcion> res;
    ControladorVideojuego* cvj = ControladorVideojuego::getInstance();
    vector<Videojuego*> vidoejue = cvj->DarVideojuegos();
    videojue::iterator it;
    for (it = videojue.begin(); it != videojue.end(); ++it)
        res.push_back(it->crearDtsuscripcion()); //el it es asi o (*it) asi?
    //Me falta hacer la diferencia de res y susActivas
}

void ControladorSuscripciones::SeleccionarVideojuego(string Juego) {
    ControladorVideojuego* cvj = ControladorVideojuego::getInstance();
    ControladorSuscripciones::vj = cvj->darVideojuego(Juego);
}
void ControladorSuscripciones::IngresarDatosSuscripcion(string tiposuscripcion, DtPago pag) {
    ControladorSuscripciones::tiposus = tiposuscripcion;
    ControladorSuscripciones::pago = pag;
}