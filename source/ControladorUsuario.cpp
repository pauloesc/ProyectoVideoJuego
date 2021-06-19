#include <string> 
#include <vector>
#include "../include/ControladorUsuario.h"

using namespace std;

ControladorUsuario* ControladorUsuario::instance = NULL; 
ControladorUsuario::ControladorUsuario() {}

ControladorUsuario *ControladorUsuario::getInstance() {
 if (instance == NULL)
       instance = new ControladorUsuario();
 return instance;
} 


void ControladorUsuario::IngresardatosUsuario(string email, string contrasenia){
       this->email=email;
       this->contrasenia=contrasenia;
}

void ControladorUsuario::IngresardatosDesarrollador(string nomEmpresa){
       this->nomEmpresa=nomEmpresa;
       this->desarrollador=true;
}

bool ControladorUsuario::IngresardatosJugador(string nickname, string desc){
       bool existe=false;
       Jugador* j; 
       vector<Usuario*>::iterator it = Usuarios.begin();
       while ((!existe) && (it!=Usuarios.end())) {
              j = dynamic_cast<Jugador*>(*it);
              if (j!=NULL){  
                  if (j->getnickname()==nickname)
                     existe=true;
              }
             ++it;
       }
       if(!existe){
              this->desarrollador=false; 
              this->nickname=nickname;
              this->desc=desc;
       }
       return (!existe);
}

void ControladorUsuario::ConfirmarAltaUsuario(){
      
       if (desarrollador){
              Desarrollador* d= new Desarrollador(email, contrasenia, nomEmpresa);
              Usuarios.push_back(d);
       }
       else {
              Jugador* j= new Jugador(email, contrasenia, nickname, desc);
              Usuarios.push_back(j);
       }
}

void ControladorUsuario::cancelarAltaUsuario(){} //puedeo volver los valores a 0



bool ControladorUsuario::ingresarDatos(string email, string contrasenia){
       bool existe=false;
       vector<Usuario*>::iterator it = Usuarios.begin();
       while ((!existe) && (it!=Usuarios.end())) {
               if (((*it)->getemail()==email)&&((*it)->getcontrasenia()==contrasenia)){
                     existe=true;
                     uenlinea=(*it);
               }
       ++it;
       }

       return existe;
}

Jugador* ControladorUsuario::darJugador(){
       Jugador* j = dynamic_cast<Jugador*>(uenlinea);
       return j;
} 

Desarrollador* ControladorUsuario::darDesarrollador(){
       Desarrollador* d = dynamic_cast<Desarrollador*>(uenlinea);
       return d;
} 


vector<string> ControladorUsuario::darNombreJugadoresConSuscripcionActiva(string nombrevid){
       vector<string> jug;
       vector<Usuario*>::iterator it;
       Jugador* JqueInicia = this->darJugador();
       Jugador* j;

       for (it = Usuarios.begin(); it!=Usuarios.end(); ++it){
              j = dynamic_cast<Jugador*>(*it);
              if (j!=NULL){
                if (j->tieneSuscripcionActiva(nombrevid) and (j != JqueInicia))
                   jug.push_back(j->getnickname());
              }
       }

       return jug;
}


vector<Jugador*> ControladorUsuario::darJugadores(vector<string> jugadoresUnidos){
       vector<Jugador*> jug;
       int tamJug=jugadoresUnidos.size();
       int tamCol=Usuarios.size();

       for (int i=0; i<tamJug; i++){
              int j=0;
              bool resu=false;
              while ((!resu) && (j<tamCol)){
                     Jugador* juu = dynamic_cast<Jugador*>(Usuarios[j]);
                     if (juu!=NULL){
                            if (juu->getnickname()==jugadoresUnidos[i]){ 
                                  jug.push_back(juu);
                                  resu=true;
                            }
                     }
              j++;
              }
       }
       return jug;
}


void ControladorUsuario::eliminarSuscripcionesVideoJuego(string nomVJ){
       int tamCol=Usuarios.size();

       for (int i=0; i<tamCol; i++){
              Jugador* j = dynamic_cast<Jugador*>(Usuarios[i]);

              if (j!=NULL){
                   j->eliminarSuscripciones(nomVJ);
                   j->desvincularPartidas(nomVJ);
              }
       }
}

bool ControladorUsuario::esUsuarioEnLineaJugador(){
       bool resu=false;
       if (dynamic_cast<Jugador*>(uenlinea)!=NULL)
              resu=true;
       
       return resu;

}

int ControladorUsuario::totalSuscriptos(Videojuego* v){
       int tamCol=Usuarios.size();
       int total=0;

       for (int i=0; i<tamCol; i++){
              Jugador* j = dynamic_cast<Jugador*>(Usuarios[i]);
              if (j!=NULL){
                   if (j->tieneSuscripcionActiva(v))   //ven en jugador
                      total++;
              }
       }
       return total;
}

 
vector<DtPartidaMultijugador*> ControladorUsuario::obtenerPartidasEnCursoUnido() {
  vector<DtPartidaMultijugador*> res, inter;
  Jugador* iniciada = dynamic_cast<Jugador*>(uenlinea);


  for (unsigned long int i = 0; i < Usuarios.size(); i++) {
    if (Usuarios[i]->esJugador()) {
      Jugador* j = dynamic_cast<Jugador*>(Usuarios[i]);
      inter = j->partidasJuntos(iniciada); 

      for (unsigned long int j = 0; j < inter.size(); j++) {
        res.push_back(inter[j]);
      }
      inter.clear();
    }
  }
 return res;
}


void ControladorUsuario::jugadorAbandona(int identificador) {
  Jugador* iniciada = dynamic_cast<Jugador*>(uenlinea);

  for (unsigned long int i = 0; i < Usuarios.size(); i++) {
    if (Usuarios[i]->esJugador()) {
      Jugador* j = dynamic_cast<Jugador*>(Usuarios[i]);
      j->jugadorAbandona(identificador,iniciada);
    }
  }
}


ControladorUsuario::~ControladorUsuario() {
       vector<Usuario*>::iterator it;
       for ( it = Usuarios.begin(); it!=Usuarios.end(); ++it){
              delete (*it);
       }	
       Usuarios.clear();
}


void ControladorUsuario::asignarEstadisticas( vector<Estadistica*> VectorDePunterosAEstadisticasEspecificas ){

       Desarrollador* Desaor = darDesarrollador();

       Desaor->setEstadisticas(VectorDePunterosAEstadisticasEspecificas);

}