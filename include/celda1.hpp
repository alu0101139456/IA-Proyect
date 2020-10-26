#ifndef CELDA1
#define CELDA1

#include <iostream>
#include "celda.hpp"

class Celda1 : public Celda {
 public:
  Celda1(void);
  Celda1(int i, int j);
  ~Celda1(void);
  int getEstado(void) const;
  std::ostream& mostrar(std::ostream& os) const;
};

#endif
