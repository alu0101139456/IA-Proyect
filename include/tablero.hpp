#ifndef TABLERO

#define TABLERO

#include <iostream>
#include "celda.hpp"

class Tablero {
 public:
  Tablero(void);
  Tablero(int filas, int columnas);
  ~Tablero(void);
  void set_inicial(int i, int j);
  void set_final(int i, int j);
  void set_obstaculo(int i, int j);
  void modo_aleatorio(int num_obstaculos);
  friend std::ostream& operator<<(std::ostream& os, const Tablero& tablero);

 private:
  int filas_;
  int columnas_;
  Celda** malla_;
  int position(int i, int j) const;
};

#endif
