#ifndef DTUSUARIO
#define DTUSUARIO

#include <string>
#include <iostream>
using namespace std;

class DtUsuario {
private:
	string email;
	string contrasenia;
public:
    DtUsuario();
	DtUsuario(string Semail, string Scontrasenia);
	string getEmail();
	string getContrasenia();
	void setEmail(string email);
	void setContrasenia(string contrasenia);
	virtual ~DtUsuario();
	friend ostream& operator<<(ostream &o, DtUsuario *s);
};



#endif
