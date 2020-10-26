#include "../include/celda3.hpp"

//Constructor por defecto.
Celda3::Celda3(void) {}

//Constructor.
Celda3::Celda3(int i, int j) : Celda(i, j) {}

//Destructor.
Celda3::~Celda3(void) {} 

int Celda3::getEstado(void) const {
  return 3;
}

std::ostream& Celda3::mostrar(std::ostream& os) const {
  os << "██████";
  return os;
}
