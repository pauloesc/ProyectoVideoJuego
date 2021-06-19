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
  o << "Fecha partida: " << d->getDia() << "/" << d->getMes() << "/" << d->getAnio() << " " << d->getHora() << ":";
  if ((d->getMinuto())>9)
      o << d->getMinuto() <<'\n';
  else 
      o << "0" << d->getMinuto() <<'\n';
  return o;
}

ostream& operator<<(ostream &o, DtFecha d) {
  o << "Fecha partida: " << d.getDia() << "/" << d.getMes() << "/" << d.getAnio() << " " << d.getHora() << ":";
  if ((d.getMinuto()) > 9)
      o << d.getMinuto() <<'\n';
  else
      o << "0" << d.getMinuto() <<'\n';
  return o;
}

// retorna true si a es una fecha menor que b
bool AmenorB(DtFecha* a, DtFecha* b){
    bool res;
    if (a->getAnio() < b->getAnio()) {
        res = true;
    } else if (a->getAnio() > b->getAnio()) {
        res = false;
    } else {

        if (a->getMes() < b->getMes()) {
            res = true;
        } else if (a->getMes() > b->getMes()) {
            res = false;
        } else {

            if (a->getDia() < b->getDia()) {
                res = true;
            } else if (a->getDia() > b->getDia()) {
                res = false;
            } else {

                 if (a->getHora() < b->getHora()) {
                    res = true;
                } else if (a->getHora() > b->getHora()) {
                    res = false;
                } else {

                     if (a->getMinuto() < b->getMinuto()) {
                        res = true;
                    } else {
                        res = false;
                    } 
                }
            }
        }

    }
    return res;
}

