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
    string getTpo();

    DtCategoria ObtenerDataCategoria();
    adicionarVideojuego(vid:Videojuego);
    desvincularVideoJuego(vj:VideoJuego);

    ~Categoria();
};


#endif
