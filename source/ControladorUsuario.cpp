#include <string> 
#include ControladorUsuario.h
#include Usuario.h

using namespace std;

ControladorUsuario* ControladorUsuario::instance = NULL; 
ControladorUsuario::ControladorUsuario() {}

ControladorUsuario *ControladorUsuario::getInstancia() {
 if (instance == NULL)
 instance = new ControladorUsuario();
 return instance;
} 

string ControladorUsuario::email=$; //no sé si se escriben asi
string ControladorUsuario::contrasenia=$;
string ControladorUsuario::nomEmpresa;
bool ControladorUsuario::desarrollador=false;
string ControladorUsuario::nickname=$;
string ControladorUsuario::desc=$;


void ControladorUsuario::IngresardatosUsuario(string email, string contrasenia){
       this->email =email;
       this->contrasenia =contrasenia;
}

void ControladorUsuario::IngresardatosDesarrollador(string nomEmpresa){
       this->nomEmpresa=nomEmpresa;
       this->desarrollador=true;
}

bool ControladorUsuario::IngresardatosJugador(string nickname, string desc){
       bool existe=false;
       vector<Usuario*>::iterator it = Usuarios.begin();
       While ((!existe) && (it!=Usuarios.end()){
              if (dynamic_cast<Jugador*>(it)){  
                  if (it->getnickname()==nickname)
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
              Usuario u*=dynamic_cast <Usuario*>(d); //no se si esto es necesario
       }
       else {
              Jugador* j= new Jugador(email, contrasenia, nickname, desc);
              Usuario u*=dynamic_cast <Usuario*>(j); //no se si esto es necesario

       }
usuarios.push_back (u);
}
void ControladorUsuario::cancelarAltaUsuario(){} //puedeo volve los valores a $ o dejarlos como estan

Usuario* ControladorUsuario::uenlinea=NULL;

bool ControladorUsuario::ingresarDatos(string email, string contrasenia){
       bool existe=false;
       vector<Usuario*>::iterator it = Usuarios.begin();
       While ((!existe) && (it!=Usuarios.end()){
               if ((it->getemail()==email)&&(it->getcontrasenia==contrasenia)){
                     existe=true;
                     uenlinea=it;
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
              if (dynamic_cast<Jugador*>(it)){

              }
       }


}



















ControladorUsuario::~ControladorUsuario() {
       vector<Usuario*>::iterator it;
       for ( it = Usuarios.begin(); it!=Usuarios.end(); ++i){
              delete it;
       }	
       delete Usuarios;
}