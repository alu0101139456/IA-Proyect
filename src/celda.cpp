#include "../include/celda.hpp"

//Constructor por defecto.
Celda::Celda(void) {}

//Constructor.
Celda::Celda(int i, int j) {
  i_ = i;
  j_ = j;
}

//Destructor.
 Celda::~Celda(void) {}

int Celda::getEstado(void) const {
  return 0;
}

//Sobrecarga del operador de salida.
std::ostream& Celda::mostrar(std::ostream& os) const {
  os << "      ";
  return os;
}
