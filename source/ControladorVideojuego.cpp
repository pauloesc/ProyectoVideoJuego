#include <string> 
#include <vector>
#include ControladorVideojuego.h
#include Videojuego.h

using namespace std;

ControladorVideojuego* ControladorVideojuego::instance = NULL; 
ControladorVideojuego::ControladorVideojuego() {}

ControladorVideojuego *ControladorVideojuego::getInstancia() {
 if (instance == NULL)
 instance = new ControladorVideojuego();
 return instance;
} 
