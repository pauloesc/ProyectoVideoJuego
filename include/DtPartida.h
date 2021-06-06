#ifndef DTPARTIDA
#define DTPARTIDA

#include <string>
#include <iostream>
#include "DtFecha.h"

using namespace std;

class DtPartida {
	private:
		DtFecha fechaIniciada;
		float duracion;
		int codigo;
		bool enCurso;

	public:
		DtPartida();
		DtPartida(DtFecha, float, int, bool);

		DtFecha getFecha() const;
		float getDuracion() const;
		int getCodigo() const;
		bool getEnCurso() const;

        void setFecha(DtFecha fechaIniciada);
        void setDuracion(float duracion);
        void setCodigo(int codigo);
        void setEnCurso(bool enCurso);


		virtual ~DtPartida();
		friend ostream& operator<<(ostream &o, DtPartida *s);
};











#endif
