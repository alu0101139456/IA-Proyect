#include "../include/celda2.hpp"

//Constructor por defecto.
Celda2::Celda2(void) {}

//Constructor.
Celda2::Celda2(int i, int j) : Celda(i, j) {}

//Destructor.
Celda2::~Celda2(void) {} 

int Celda2::getEstado(void) const {
  return 2;
}

std::ostream& Celda2::mostrar(std::ostream& os) const {
  os << "FINISH";
  return os;
}

