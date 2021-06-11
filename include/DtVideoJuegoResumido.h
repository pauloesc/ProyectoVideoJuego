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
    
    void setNombre();
    void setDescripcion();
    
    friend ostream& operator<<(ostream &o, DtVIdeoJuegoResumido* d);
    
};

#endif
