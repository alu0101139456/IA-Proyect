#ifndef CELDA3
#define CELDA3

#include <iostream>
#include "celda.hpp"

class Celda3 : public Celda {
 public:
  Celda3(void);
  Celda3(int i, int j);
  ~Celda3(void);
  int getEstado(void) const;
  std::ostream& mostrar(std::ostream& os) const;
};

#endif
