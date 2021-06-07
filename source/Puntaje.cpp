Puntaje::Puntaje(int Puntos, Videojuego* punteroVj) {
    this->Puntos = Puntos;
    this->Videojuego = punteroVj;
}

int Puntaje::getPuntos(){
    return Nombre;
}

Videojuego* Puntaje::getVideoJuego(){
    return Videojuego;
}

Puntaje::setPuntos(int p){
    this->Puntos = p;
}

Puntaje::setVideoJuego(Videojuego* vj){
    this->Videojuego = vj;
}

Puntaje::~Puntaje(){
}
