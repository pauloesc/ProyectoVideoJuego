#include <string> 
#include <vector>
#include ".../include/ControladorVideojuego.h"
#include ".../include/DtVideojuego.h"
#include ".../include/DtCategoria.h"
#include ".../include/Videojuego.h"
#include ".../include/Categoria.h"
#include ".../include/ControladorUsuario.h"
#include ".../include/Usuario.h"
#include ".../include/Desarrolador.h"


using namespace std;

ControladorVideojuego* ControladorVideojuego::instance = NULL; 
ControladorVideojuego::ControladorVideojuego() {}

ControladorVideojuego* ControladorVideojuego::getInstance() {
 if (instance == NULL)
 instance = new ControladorVideojuego();
 return instance;
} 

string ControladorVideojuego::nombreJuego=0;
string ControladorVideojuego::descrip=0;
float ControladorVideojuego::costoMensual=0;
float ControladorVideojuego::costoTrimestral=0;
float ControladorVideojuego::costoAnual=0;
float ControladorVideojuego::costoVitalicia=0;

void ControladorVideojuego::datosVideojuego(string nombreJuego, string descrip, float costoMensual, float costoTrimestral, float costoAnual, float costoVitalicia){

    ControladorVideojuego::nombreJuego=nombreJuego;
    ControladorVideojuego::descrip=descrip;
    ControladorVideojuego::costoMensual=costoMensual;
    ControladorVideojuego::costoTrimestral=costoTrimestral;
    ControladorVideojuego::costoAnual=costoAnual;
    ControladorVideojuego::costoVitalicia=costoVitalicia;

}

vector<DtCategoria> ControladorVideojuego::ObtenerCategoriaPlataforma(){
    
    vector<DtCategoria> colplataforma; 
    int tamCol=Categorias.size();
    for (int i=0; i<tamCol; i++){
        if(Categorias[i]->getTipo()=plataforma){  //mirarlo despues en categoria
            colplataforma.push_back(Categorias[i]->ObtenerDataCategoria()); //mirarlo en cat
        }
    }
    return colplataforma;
}

vector<DtCategoria> ControladorVideojuego::ObtenerCategoriaGenero(){
    
    vector<DtCategoria> colgenero; 
    int tamCol=Categorias.size();
    for (int i=0; i<tamCol; i++){
        if(Categorias[i]->getTipo()=genero){  //mirarlo despues en categoria
            colgenero.push_back(Categorias[i]->ObtenerDataCategoria());
        }
    }
    return colgenero;
}

vector<DtCategoria> ControladorVideojuego::ObtenerCategoriaOtros(){

    vector<DtCategoria> colotro; 
    int tamCol=Categorias.size();
    for (int i=0; i<tamCol; i++){
        if(Categorias[i]->getTipo()=otro){  //mirarlo despues en categoria
            colotro.push_back(Categorias[i]->ObtenerDataCategoria());
        }
    }
    return colotro;
} 
vector<string> ControladorVideojuego::cats; //no sé si queda bien inicializado

void ControladorVideojuego::agregarcategoria (string categoria){
    ControladorVideojuego::cats.push_back(categoria);
}

DtVideojuego ControladorVideojuego::ObtenerInfoVideojuego(){
    DtVideojuego info(nombreJuego, descrip, costoMensual, costoTrimestral, costoAnual, costoVitalicio, cats);
    return info;
}//ver la parte de DtVideojuego

void ControladorVideojuego::ConfirmarAltavideoJuego(){
    
    Videojuego* nuevo=new Videojuego (nombreJuego, descrip, costoMensual, costoTrimestral, costoAnual, costoVitalicio);
    int tamcats=cats.size();
    int tamCol=Categorias.size();

    for (int i=0; i<tamcats; i++){
        int j=0;
        bool resu=false;
        While ((!resu) && (j<tamCol)){
            if ((Categorias[j]->getNombre())==cats[i]){ //Fijarse en categoria
                Categorias[j]->adicionarVideojuego(nombreJuego);
                resu=true;
            }
        j++;                      
        }
    }
    ControladorUsuario* cu;
    cu= ControladorUsuario::getInstance();
    Desarrollador* des=cu->darDesarrollador();
    nuevo->setDesarrollador(des);   //fijarse en videojuego
    Videojuegos.push_back[nuevo];
    cats.clear();
}

void ControladorVideojuego::CancelarAltavideoJuego(){//puedo volver todos a cero, pero el que si hay que borrar es el vector
    cats.clear();
}

Videojuego* ControladorVideojuego::darVideojuego(string Juego){
    Videojuego* vid;
    int tamCol=Videojuegos.size();
    int i=0;
    bool resu=false;

    while ((!resu)&& (i<tamCol){
        if (Videojuegos[i]->getNombre()==Juego){
            resu=true;
            vid=Videojuego[i];
        }  //ver en videojuego 
        i++;
    }
    return vid;
}

vector<string> ControladorVideojuego::obtenerVideoJuegosConTodasLasPartidasFinalizadas(){
    vector<string> parfin;
    int tamCol=Videojuegos.size();

    for (int i=0; i<tamCol; i++){
        if (Videojuegos[i]->TodasFinalizadas()){
            parfin.push_back[Videojuegos[i]->getNombre()];
        }
    }
    return parfin;
}

Videojuego* ControladorVideojuego::vid=NULL;

void ControladorVideojuego::seleccionarVideoJuego(string nomVJ){
    int tamCol=Videojuegos.size();
    int i=0;
    bool resu=false;

    while ((!resu)&& (i<tamCol){
        if (Videojuegos[i]->getNombre()==nomVJ){
            resu=true;
            ControladorVideojuego::vid=Videojuego[i];
        }  
        i++;
    }
} 

void ControladorVideojuego::eliminarVideoJuego(){
    
    int tamCol=Videojuegos.size();
    int i=0;
    bool resu=false;

    while ((!resu)&& (i<tamCol){
        if (Videojuegos[i]->getNombre()==vid->getNombre()){
            resu=true;
            Videojuegos.erase(Videojuegos.begin()+i);
        }  
        i++;
    }

    int tamCol=Categorias.size();
    for (int i=0; i<tamCol; i++){
        Categorias[i]->desvincularVideojuego(vid) //mirarlo despues en categoria
    }

    ControladorVideojuego* cvid;
    cvid= ControladorVideojuego::getInstance();
    cvid->eliminarPartidas(vid);

    ControladorUsuario* cu;
    cu= ControladorUsuario::getInstance();
    cu->eliminarSuscripcionesVideoJuego(vid->getNombre());

    vid->eliminarPuntajes(); // ven en videojuego
    delete vid;
    ControladorVideojuego::vid=NULL;
}
