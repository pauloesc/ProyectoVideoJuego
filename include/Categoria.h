#ifndef CATEGORIA
#define CATEGORIA
#include "../include/Categoria.h"
#include "../include/DataCategoria.h"
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
    
    DataCategoria ObtenerDataCategoria();
    adicionarVideojuego(vid:Videojuego);
    desvincularVideoJuego(vj:VideoJuego);
    
    ~Categoria();
};


#endif
