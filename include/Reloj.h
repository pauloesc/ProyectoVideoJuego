//para obtener la fecha del sistema: DtFecha* f = Reloj::getFecha();
#ifndef RELOJ
#define RELOJ

#include "DtFecha.h"


class Reloj {
private:
	static DtFecha *fecha;
public:
	static DtFecha* getFecha();
	static void setFecha(int Sdia, int Smes, int Sanio, int Shora, int Sminuto);
};

#endif
