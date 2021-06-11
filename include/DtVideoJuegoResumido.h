#ifndef DTVIDEOJUEGORESUMIDO
#define DTVIDEOJUEGORESUMIDO

#include <string>
#include <iostream>

using namespace std;

class DtVIdeoJuegoResumido {
private:
	string Nombre;
    string Descripcion;
public:
    DtVIdeoJuegoResumido();
	DtVIdeoJuegoResumido(string nom, string des);
    
	string getNombre();
    string getDescripcion();
    
    void string setNombre();
    void string setDescripcion();
    
    friend ostream& operator<<(ostream &o, DataEstadistica* d);
    
};

#endif
