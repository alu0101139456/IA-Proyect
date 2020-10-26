#ifndef CELDA
#define CELDA

#include <iostream>

class Celda {
 public:
  Celda(void);
  Celda(int i, int j);
  virtual ~Celda(void);
  virtual int getEstado(void) const;
  virtual std::ostream& mostrar(std::ostream& os) const;

 private: 
  int i_;
  int j_;
};

#endif

