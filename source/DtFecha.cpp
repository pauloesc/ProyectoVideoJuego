#include <string>
#include <iostream>
#include "../include/DtFecha.h"
using namespace std;


DtFecha::DtFecha(int Sdia, int Smes, int Sanio, int Shora, int Sminuto){
      if ((Sdia>31)|| (Sdia<1)|| (Smes>12)|| (Smes<1)|| (Sanio<1900) || (Shora<0) || (Shora>23) || (Sminuto<0) || (Sminuto>59)) {
          throw std::invalid_argument("fecha imposible");
      }
      dia=Sdia;
      mes=Smes;
      anio=Sanio;
      hora=Shora;
      minuto=Sminuto;
};


int DtFecha::getDia(){
    return this->dia;
};
int DtFecha::getMes(){
    return this->mes;
};
int DtFecha::getAnio(){
    return this->anio;
};
int DtFecha::getHora(){
    return this->hora;
};
int DtFecha::getMinuto(){
    return this->minuto;
};



ostream& operator<<(ostream &o, DtFecha* d) {
  o << "Fecha partida: " << d->getDia() << "/" << d->getMes() << "/" << d->getAnio() << " " << d->getHora() << ":" << d->getMinuto() <<'\n';

  return o;
}

