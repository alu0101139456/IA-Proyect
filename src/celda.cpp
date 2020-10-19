#include "celda.h"

Celda::Celda():
obstaculo(false) { }

void Celda::setObstaculo() {
  obstaculo = true;
}
bool Celda::getObstaculo(){
  return obstaculo;
}
void Celda::setCoordenada(int a, int b) {
   c.setX(a);
   c.setY(b);
}
Coordenada Celda::getCoordenada() {
  return c;
}
void Celda::print() {
  if (obstaculo == false) std::cout << " ";
  else std::cout << "@";
}