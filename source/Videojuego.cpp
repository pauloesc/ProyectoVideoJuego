VideoJuego::VideoJuego(string Nombre, string Descripcion, float CostoVitalicio, float CostoMensual, float CostoTrimestral, float CostoAnual){
    this->Nombre = Nombre;
    this->Descripcion = Descripcion;
    this->CostoVitalicio = CostoVitalicio;
    this->CostoMensual = CostoMensual;
    this->CostoTrimestral = CostoTrimestral;
    this->CostoAnual = CostoAnual;
}


string VideoJuego::getNombre(){
    return Nombre;
}

string VideoJuego::getDescripcion(){
    return Descripcion;
}

float VideoJuego::getCostoVitalicio(){
    return CostoVitalicio;
}


float VideoJuego::getCostoMensual(){
    return CostoMensual;
}

float VideoJuego::CostoTrimestral(){
    return CostoTrimestral;
}

float VideoJuego::CostoAnual(){
    return CostoAnual;
}



VideoJuego::sDesarrollador(des:Desarrollador){
    
}

bool VideoJuego::TodasFinalizadas(){
    
    bool Todasfinalizadas = 1;
    int i = 0;
    while( Todasfinalizadas && ( i < VectorDePunterosPartidasDelVideojuego.size() ) ){
        
        Todasfinalizadas = (*VectorDePunterosPartidasDelVideojuego[i]).getEsPartidaEnCurso();
        i=i+1;
    }
    return Todasfinalizadas;
}

VideoJuego::EliminarPartidas(){
    
    
    for(int i=0; i < VectorDePunterosPartidasDelVideojuego.size(); i++ ){
        
        (*VectorDePunterosPartidasDelVideojuego[i]).eliminarPartida();
    }
    
    //no se si es necesario
    //elimino toda la info dentro del vector;
    iterator1= VectorDePunterosVideojuegos.begin();
    iterator2= VectorDePunterosVideojuegos.end();
    VectorDePunterosVideojuegos.erase(iterator1, iterator2);
    
}


VideoJuego::eliminarPuntajes(){
    
    iterator1= VectorDeObjetosPuntaje.begin();
    iterator2= VectorDeObjetosPuntaje.end();
    VectorDePunterosVideojuegos.erase(iterator1, iterator2);
    
}


float VideoJuego::totalHorasJugadas(){
    
    float valorTotal = 0;
    
    for(int i=0; i < VectorDePunterosPartidasDelVideojuego.size(); i++ ){
        
        valorTotal = valorTotal + (*VectorDePunterosPartidasDelVideojuego[i]).tiempoTotal();
    }
    
    return valorTotal;
    
}

void VideoJuego::asignar(Puntaje* punt){
    VectorDeObjetosPuntaje.push_back(punt);
}


VideoJuego::~VideoJuego(){

    for(int i = 0; i< VectorDeObjetosPuntaje.size(); i++ ){
        Puntaje* eliminar = VectorDeObjetosPuntaje[i];
        delete eliminar;
        }

}
