#include <string> 
#include <vector>
#include ".../include/ControladorVideojuego.h"
#include ".../include/DtVideojuego.h"
#include ".../include/DtCategoria.h"
#include ".../include/Videojuego.h"

using namespace std;

ControladorVideojuego* ControladorVideojuego::instance = NULL; 
ControladorVideojuego::ControladorVideojuego() {}

ControladorVideojuego* ControladorVideojuego::getInstancia() {
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



