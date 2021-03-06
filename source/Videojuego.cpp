#include "../include/Videojuego.h"

Videojuego::Videojuego(string Nombre, string Descripcion, float CostoMensual, float CostoTrimestral, float CostoAnual, float CostoVitalicio){
    this->Nombre = Nombre;
    this->Descripcion = Descripcion;
    this->CostoVitalicio = CostoVitalicio;
    this->CostoMensual = CostoMensual;
    this->CostoTrimestral = CostoTrimestral;
    this->CostoAnual = CostoAnual;
}


string Videojuego::getNombre(){
    return Nombre;
}

string Videojuego::getDescripcion(){
    return Descripcion;
}

float Videojuego::getCostoVitalicio(){
    return CostoVitalicio;
}


float Videojuego::getCostoMensual(){
    return CostoMensual;
}

float Videojuego::getCostoTrimestral(){
    return CostoTrimestral;
}

float Videojuego::getCostoAnual(){
    return CostoAnual;
}

void Videojuego::AsociarPartida(Partida* p) {
    VectorDePunterosPartidasDelVideojuego.push_back(p);
}

void Videojuego::setDesarrollador(Desarrollador* des){
    Desarolladores=des;
}

Desarrollador* Videojuego::getDesarrolador(){
    return Desarolladores;
}

bool Videojuego::esDesarrolador(string email){
    return (Desarolladores->getemail()==email);
}

    


bool Videojuego::TodasFinalizadas(){
    
    bool todasfinalizadas = 1;
    long unsigned int i = 0;
    
    while (i < VectorDePunterosPartidasDelVideojuego.size()) {
        if (VectorDePunterosPartidasDelVideojuego[i]->getenCurso()) {
            todasfinalizadas = false;
        }
        i++;
    }

    return todasfinalizadas;
}

void Videojuego::EliminarPartidas(){
    
    
    for(long unsigned int i=0; i < VectorDePunterosPartidasDelVideojuego.size(); i++ ){
        
        (*VectorDePunterosPartidasDelVideojuego[i]).eliminarPartida();
        delete VectorDePunterosPartidasDelVideojuego[i];
    }
    
    
    VectorDePunterosPartidasDelVideojuego.clear();
    
}


void Videojuego::eliminarPuntajes(){
    
    for (unsigned long int i = 0; i < VectorDeObjetosPuntaje.size(); i++) {
        delete VectorDeObjetosPuntaje[i];
    }

    VectorDeObjetosPuntaje.clear();
    
}


float Videojuego::totalHorasJugadas(){
    
    float valorTotal = 0;
    
    for(long unsigned int i=0; i < VectorDePunterosPartidasDelVideojuego.size(); i++ ){
        
        valorTotal = valorTotal + (*VectorDePunterosPartidasDelVideojuego[i]).tiempoTotal();
    }
    
    return valorTotal;
    
}

void Videojuego::asignar(Puntaje* punt){
    VectorDeObjetosPuntaje.push_back(punt);
}


Videojuego::~Videojuego(){

        for (long unsigned int i = 0; i< VectorDePunterosPartidasDelVideojuego.size(); i++ ){
            Partida* eliminar= VectorDePunterosPartidasDelVideojuego[i];
            delete eliminar;
        }

        for(long unsigned int i = 0; i< VectorDeObjetosPuntaje.size(); i++ ){
            Puntaje* eliminar = VectorDeObjetosPuntaje[i];
            delete eliminar;
        }

        VectorDePunterosPartidasDelVideojuego.clear();
        VectorDeObjetosPuntaje.clear();

}

vector<DtSuscripcion*> Videojuego::crearDtsuscripcion() {
    vector<DtSuscripcion*> res;
    DtSuscripcion* d;

    d = new DtSuscripcion(this->Nombre,this->CostoMensual,"mensual");
    res.push_back(d);

    d = new DtSuscripcion(this->Nombre,this->CostoTrimestral,"trimestral");
    res.push_back(d);

    d = new DtSuscripcion(this->Nombre,this->CostoAnual,"anual");
    res.push_back(d);

    d = new DtSuscripcion(this->Nombre,this->CostoVitalicio,"vitalicia");
    res.push_back(d);

    return res;
}


string Videojuego::darEmpresaDesarroladora(){
    return Desarolladores->getnomEmpresa();
    }

float Videojuego::darPromedioPuntaje(){
        float resu;
        float suma= 0;
        long unsigned int cant= 0;

        for(cant=0; cant < VectorDeObjetosPuntaje.size(); cant++ ){
            suma = suma + VectorDeObjetosPuntaje[cant]->getPuntos();
        }
        if (suma == 0)
            resu = 0;
        else
            resu= suma/cant;
        return resu;
}
