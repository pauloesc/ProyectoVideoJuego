#include <string> 

using namespace std;

ControladorUsuario *ControladorUsuario::instance = NULL; 

ControladorUsuario *ControladorUsuario::getInstancia() {
 if (instance == NULL)
 instance = new ControladorUsuario();
 return instance;
} 



void ControladorUsuario::IngresardatosUsuario(string email, string contrasenia){
       ControladorUsuario::email=email;
       ControladorUsuario::contrasenia=contrasenia;
}

void ControladorUsuario::IngresardatosDesarrollador(string nomEmpresa){
       ControladorUsuario::nomEmpresa=nomEmpresa;
       ControladorUsuario::derrollador=true;
}

bool ControladorUsuario::IngresardatosJugador(string nickname, string desc){
    
}
