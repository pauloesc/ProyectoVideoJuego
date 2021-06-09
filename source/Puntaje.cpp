Puntaje::Puntaje(int Puntos, Jugador* punteroj) {
    this->Puntos = Puntos;
    this->Videojuego = punteroj;
}

int Puntaje::getPuntos(){
    return Nombre;
}

Jugador* Puntaje::getJugador(){
    return Jugador;
}

Puntaje::setPuntos(int p){
    this->Puntos = p;
}

Puntaje::setJugador(Jugador* j){
    this->Jugador = j;
}

Puntaje::~Puntaje(){
}
