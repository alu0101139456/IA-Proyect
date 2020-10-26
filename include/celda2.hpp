#ifndef CELDA2
#define CELDA2

#include <iostream>
#include "celda.hpp"

class Celda2 : public Celda {
 public:
  Celda2(void);
  Celda2(int i, int j);
  ~Celda2(void);
  int getEstado(void) const;
  std::ostream& mostrar(std::ostream& os) const;
};

#endif
