#include <string> 
#include <vector>
#include ".../include/ControladorUsuario.h"
#include ".../include/Usuario.h"
#include ".../include/Jugador.h"
#include ".../include/Desarrolador.h"

using namespace std;

ControladorUsuario* ControladorUsuario::instance = NULL; 
ControladorUsuario::ControladorUsuario() {}

ControladorUsuario *ControladorUsuario::getInstancia() {
 if (instance == NULL)
 instance = new ControladorUsuario();
 return instance;
} 

string ControladorUsuario::email=0; //no sé si se escriben asi
string ControladorUsuario::contrasenia=0;
string ControladorUsuario::nomEmpresa=0;
bool ControladorUsuario::desarrollador=false;
string ControladorUsuario::nickname=0;
string ControladorUsuario::desc=0;


void ControladorUsuario::IngresardatosUsuario(string email, string contrasenia){
       controladorUsuario::email=email;
       controladorUsuario::contrasenia=contrasenia;
}

void ControladorUsuario::IngresardatosDesarrollador(string nomEmpresa){
       controladorUsuario::nomEmpresa=nomEmpresa;
       controladorUsuario::desarrollador=true;
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
              controladorUsuario::desarrollador=false; 
              controladorUsuario::nickname=nickname;
              controladorUsuario::desc=desc;
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

Usuario* ControladorUsuario::uenlinea=NULL;

bool ControladorUsuario::ingresarDatos(string email, string contrasenia){
       bool existe=false;
       vector<Usuario*>::iterator it = Usuarios.begin();
       While ((!existe) && (it!=Usuarios.end()){
               if (((*it)->getemail()==email)&&((*it)->getcontrasenia==contrasenia)){
                     existe=true;
                     ControladorUsuario::uenlinea=(*it);
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
                   jug.push_back((*it)->getnickname())
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


ControladorUsuario::~ControladorUsuario() {
       vector<Usuario*>::iterator it;
       for ( it = Usuarios.begin(); it!=Usuarios.end(); ++i){
              delete (*it);
       }	
       Usuarios.clear();
}