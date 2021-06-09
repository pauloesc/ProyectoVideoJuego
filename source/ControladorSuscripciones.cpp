#include "ControladorSuscripciones.h"

vector<DtSuscripcion *> ControladorSuscripciones::obtenerSuscripcionesActivas() {
    ControladorUsusario* cu = ControladorUsuario::getInstance();
    Jugador* jug = cu->darJugador();
    return *jug->darSuscripcionesActivas();
}

vector<DtSuscripcion *> ControladorSuscripciones::obtenerSuscripcionesNoActivas() {
    vector<DtSuscripcion *> susActivas =  obtenerSuscripcionesActivas();
    vector<DtSuscripcion *> res;
    ControladorVideojuego* cvj = ControladorVideojuego::getInstance();
    vector<Videojuego*> vidoejue = cvj->DarVideojuegos();
    for (int i = 0; i < videojue.size(); i++)
        res.push_back(*videojue[i]->crearDtsuscripcion());
    //Falta hacer la diferencia entre susActivas y res
}

void ControladorSuscripciones::SeleccionarVideojuego(string Juego) {
    ControladorVideojuego* cvj = ControladorVideojuego::getInstance();
    ControladorSuscripciones::vj = cvj->darVideojuego(Juego);
}
void ControladorSuscripciones::IngresarDatosSuscripcion(string tiposuscripcion, DtPago *pag) {
    ControladorSuscripciones::tiposus = tiposuscripcion;
    ControladorSuscripciones::pago = pag;
}