#ifndef CONTROLADORVIDEOJUEGO
#define CONTROLADORVIDEOJUEGO

#include ".../include/Videojuego.h"
using namespace std;
#include <vector>

class ControladorVideojuego {

private:
static ControladorVideojuego * instance;
ControladorUsuario();
vector<VideoJuego*> Videojuegos;

public:
static ControladorUsuario * getInstance();

