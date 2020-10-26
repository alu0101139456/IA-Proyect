#ifndef CELDA4
#define CELDA4

#include <iostream>
#include "celda.hpp"

class Celda4 : public Celda {
 public:
  Celda4(void);
  Celda4(int i, int j);
  ~Celda4(void);
  int getEstado(void) const;
  std::ostream& mostrar(std::ostream& os) const;
};

#endif
