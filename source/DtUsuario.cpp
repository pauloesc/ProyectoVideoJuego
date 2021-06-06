#include <string>
#include "../include/DtUsuario.h"
#include "../include/DtJugador.h"
#include "../include/DtDesarrollador.h"

DtUsuario::DtUsuario () {
	email = "";
    contrasenia = "";
}

DtUsuario::DtUsuario (string Semail, string Scontrasenia) {
	email = Semail;
    contrasenia = Scontrasenia;
}

DtUsuario::~DtUsuario () {
}

string DtUsuario::getEmail () {
	return email;
}

string DtUsuario::getContrasenia () {
	return contrasenia;
}
void DtUsuario::setEmail(string email) {
	this->email = email;
}

void DtUsuario::setContrasenia(string contrasenia) {
	this->contrasenia = contrasenia;
}

ostream& operator<<(ostream &o, DtUsuario *s) {
	o << "email: "<< s->getEmail() << " contraseña: " << s->getContrasenia() <<'\n';
	if (dynamic_cast<DtJugador*>(s) != NULL){
        DtJugador *j = dynamic_cast<DtJugador*>(s);
        o << "nickname: " << j->getNickname() << " descripción: " << j->getDescripcion() << '\n';
	} else {
        DtDesarrollador *d = dynamic_cast<DtDesarrollador*>(s);
        o << "empresa: "<< d->getNombreEmpresa() <<'\n';
	}

	return o;
}
