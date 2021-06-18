#ifndef DTPARTIDA
#define DTPARTIDA

#include <string>
#include <iostream>
#include "DtFecha.h"

using namespace std;

class DtPartida {
	private:
		DtFecha *fechaIniciada;
		float duracion;
		int codigo;
		bool enCurso;

	public:
		DtPartida();
		DtPartida(DtFecha* Sfecha, float duracionPartida, int codigo, bool enCurso);

		DtFecha* getFecha();
		float getDuracion();
		int getCodigo();
		bool getEnCurso();

        void setFecha(DtFecha* fechaIniciada);
        void setDuracion(float duracion);
        void setCodigo(int codigo);
        void setEnCurso(bool enCurso);


		virtual void imprimir() = 0;

		virtual ~DtPartida();
		friend ostream& operator<<(ostream &o, DtPartida *s);
};











#endif
