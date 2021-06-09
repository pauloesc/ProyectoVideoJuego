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

void Puntaje::setPuntos(int p){
    this->Puntos = p;
}

void Puntaje::setJugador(Jugador* j){
    this->Jugador = j;
}

Puntaje::~Puntaje(){
}
