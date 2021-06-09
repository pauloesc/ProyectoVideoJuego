#include <string> 
#include <vector>
#include ".../include/ControladorUsuario.h"

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
       vector<Usuario*>::iterator it = Usuarios.begin();
       While ((!existe) && (it!=Usuarios.end()){
              if ((dynamic_cast<Jugador*>(*it))!=NULL){  
                  if ((*it)->getnickname()==nickname)
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
              Usuarios.push_back (&d);
       }
       else {
              Jugador* j= new Jugador(email, contrasenia, nickname, desc);
              Usuarios.push_back (&j);
       }
}

void ControladorUsuario::cancelarAltaUsuario(){} //puedeo volver los valores a 0



bool ControladorUsuario::ingresarDatos(string email, string contrasenia){
       bool existe=false;
       vector<Usuario*>::iterator it = Usuarios.begin();
       While ((!existe) && (it!=Usuarios.end()){
               if (((*it)->getemail()==email)&&((*it)->getcontrasenia==contrasenia)){
                     existe=true;
                     uenlinea=(*it);
               }
       ++it;
       }

       return existe;
}

Jugador* ControladorUsuario::darJugador(){
       return uenlinea;
} 

Desarrollador* ControladorUsuario::darDesarrollador(){
       return uenlinea;
} 


vector<string> ControladorUsuario::darNombreJugadoresConSuscripcionActiva(string nombrevid){
       vector<string> jug;
       vector<Usuario*>::iterator it;

       for (it = Usuarios.begin(); it!=Usuarios.end(); ++it){
              if ((dynamic_cast<Jugador*>(*it))!=NULL){
                if ((*it)->tieneSuscripcionActiva(nombrevid))
                   jug.push_back((*it)->getnickname());
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
              While ((!resu) && (j<tamCol)){
                     if (dynamic_cast<Jugador*>(Usuarios[j])!=NULL){
                            if (Usuarios[j]->getnickname()==jugadoresUnidos[i]){ 
                                  jug.push_back(Usuarios[j]);
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
              if (dynamic_cast<Jugador*>(Usuarios[i])!=NULL){
                   Usuarios[i]->eliminarSuscripciones(nomVJ);
                   Usuarios[i]->desvincularPartidas(nomVJ);
              }
       }
}

bool ControladorUsuario::esUsuarioEnLineaJugador(){
       bool resu=false;
       if (dynamic_cast<Jugador*>(uenlinea)!=NULL)
              resu=true;
       
       return resu;

}

int ControladorUsuario::totalSuscriptos(v:VideoJuego){
       int tamCol=Usuarios.size();
       int total=0;

       for (int i=0; i<tamCol; i++){
              if (dynamic_cast<Jugador*>(Usuarios[i])!=NULL){
                   if (Usuarios[i]->tieneSuscripcionActiva(v))   //ven en jugador
                      total++;
              }
       }
       return total;
}


ControladorUsuario::~ControladorUsuario() {
       vector<Usuario*>::iterator it;
       for ( it = Usuarios.begin(); it!=Usuarios.end(); ++i){
              delete (*it);
       }	
       Usuarios.clear();
}


void ControladorUsuario::asignarEstadisticas( vector<Estadistica*> VectorDePunterosAEstadisticasEspecificas ){

       Desarrollador* Desaor = darDesarrollador();

       //en desarollador tiene que existir una funcion para poder cargar el vector

}