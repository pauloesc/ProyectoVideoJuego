#include <string> 
#include <vector>
#include ".../include/ControladorVideojuego.h
#include Videojuego.h

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

}

vector<DtCategoria> ControladorVideojuego::ObtenerCategoriaPlataforma();

vector<DtCategoria> ControladorVideojuego::ObtenerCategoriaGenero();

vector<DtCategoria> ControladorVideojuego::ObtenerCategoriaOtros(); 



