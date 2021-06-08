#ifndef CATEGORIA
#define CATEGORIA
#include <string>
#include "DtCategoria.h"
#include "vector"
using namespace std;

class Categoria {
private:
	string Nombre;
	string Descripcion;
	string Tipo;

    vector<Videojuego*> VectorDePunterosVideojuegos;

public:
	Categoria(string Nombre, string Descripcion, string Tipo);

    string getNombre();
	string getDescripcion();
    string getTipo();


    DtCategoria ObtenerDataCategoria();
    void adicionarVideojuego(vid Videojuego);
    void desvincularVideoJuego(vj VideoJuego);

    bool esCategoriaDelVideojuego(string vid); //es necesario para el caso de uso de pedir info video juego

    ~Categoria();
};


#endif
