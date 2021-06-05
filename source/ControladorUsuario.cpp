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

static string email;
static string contrasenia;
static string nomEmpresa;
static bool desarrollador;
static string nickname;
static string desc;


void ControladorUsuario::IngresardatosUsuario(string email, string contrasenia){
       ControladorUsuario::email=email;
       ControladorUsuario::contrasenia=contrasenia;
}

void ControladorUsuario::IngresardatosDesarrollador(string nomEmpresa){
       ControladorUsuario::nomEmpresa=nomEmpresa;
       ControladorUsuario::derrollador=true;
}

bool ControladorUsuario::IngresardatosJugador(string nickname, string desc){
       bool existe=false;
       vector<Usuario*>::iterator it = Usuarios.begin();
       While ((!existe) && (it!=suarios.end()){
              if (dynamic_cast<Jugador*>(it)){  
                  if (it->getnickname()==nickname)
                     existe=true;
              }
             ++it;
       }
       if(!existe){
              ControladorUsuario::desarrollador=false; 
              ControladorUsuario::nickname=nickname;
              ControladorUsuario::desc=desc;
       }
       return (!existe);
}

void ControladorUsuario::ConfirmarAltaUsuario(){
      
       if (ControladorUsuario::desarrollador){
              Desarrollador* d= new Desarrollador (ControladorUsuario::email, ControladorUsuario::contrasenia,  ControladorUsuario::nomEmpresa)
              Usuario u*=dynamic_cast <*Usurio>(d); //no se si esto es necesario
       }
       else {
              Desarrollador* d= new Desarrollador (ControladorUsuario::email, ControladorUsuario::contrasenia,  ControladorUsuario::nomEmpresa)
              Usuario u*=dynamic_cast <*Usurio>(d); //no se si esto es necesario

       }
              

usuarios.push_back (u);
}
void ControladorUsuario::cancelarAltaUsuario();

Jugador* ControladorUsuario::darJugador(); 

