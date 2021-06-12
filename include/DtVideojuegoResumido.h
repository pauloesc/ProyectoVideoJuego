#ifndef DTVIDEOJUEGORESUMIDO
#define DTVIDEOJUEGORESUMIDO

#include <string>
#include <iostream>

using namespace std;

class DtVideojuegoResumido {
private:
	string Nombre;
    string Descripcion;
public:
    DtVideojuegoResumido();
	DtVideojuegoResumido(string nom, string des);
    
	string getNombre();
    string getDescripcion();
    
 
    
    friend ostream& operator<<(ostream &o, DtVideojuegoResumido* d);
    
};

#endif
