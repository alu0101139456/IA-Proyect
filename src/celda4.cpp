#include "../include/celda4.hpp"

//Constructor por defecto.
Celda4::Celda4(void) {}

//Constructor.
Celda4::Celda4(int i, int j) : Celda(i, j) {}

//Destructor.
Celda4::~Celda4(void) {} 

int Celda4::getEstado(void) const {
  return 4;
}

std::ostream& Celda4::mostrar(std::ostream& os) const {
  os << "ÓPTIMO";
  return os;
}
