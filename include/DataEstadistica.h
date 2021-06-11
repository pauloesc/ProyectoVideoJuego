#ifndef DATAESTADISTICA
#define DATAESTADISTICA

#include <string>
#include <iostream>

using namespace std;

class DataEstadistica {
private:
	string Nombre;
    string Descripcion;
public:
    DataEstadistica();
	DataEstadistica(string nom, string des);
    
	string getNombre();
    string getDescripcion();
    
    void string setNombre();
    void string setDescripcion();
    
    friend ostream& operator<<(ostream &o, DataEstadistica* d);
    
};

#endif