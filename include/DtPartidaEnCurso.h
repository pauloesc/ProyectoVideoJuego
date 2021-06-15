#ifndef DTPARTIDAENCURSO
#define DTPARTIDAENCURSO

#include <string>
#include <iostream>
#include "DtFecha.h"


class DtPartidaEnCurso {
	private:
		DtFecha fechaIniciada;
		int codigo;
		string nombreVideojuego;

	public:
		DtPartidaEnCurso();
		DtPartidaEnCurso(DtFecha, int, string);

		DtFecha getFecha() const;
		int getCodigo() const;
		string getNombreVideojuego() const;

        void setFecha(DtFecha fechaIniciada);
        void setCodigo(int codigo);
        void setNombreVideojuego(string nombreVideojuego);

		virtual void imprimir() = 0;

		virtual ~DtPartidaEnCurso();
		friend ostream& operator<<(ostream &o, DtPartidaEnCurso *s);
};











#endif
