#ifndef DTCATEGORIA
#define DTCATEGORIA

#include <string>
#include <iostream>

using namespace std;

class DtCategoria {
	private:
		string nombreCat;
        string descripcion;
        string tipo;

	public:
		DtCategoria();
		DtCategoria(string nombreCat, string descripcion, string tipo);

		string getNombreCat();
		string getDescripcion();
		string getTipo();

        void setNombreCat(string nombreCat);
        void setDescripcion(string descripcion);
        void setTipo(string tipo);


		virtual ~DtCategoria();
		friend ostream& operator<<(ostream &o, DtCategoria *s);
};











#endif
