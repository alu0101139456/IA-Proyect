#include "../include/celda1.hpp"

//Constructor por defecto.
Celda1::Celda1(void) {}

//Constructor.
Celda1::Celda1(int i, int j) : Celda(i, j) {}

//Destructor.
Celda1::~Celda1(void) {} 

int Celda1::getEstado(void) const {
  return 1;
}

std::ostream& Celda1::mostrar(std::ostream& os) const {
  os << " START";
  return os;
}

