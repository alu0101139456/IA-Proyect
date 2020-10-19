#include "tablero.h"

int main (void) {
  int x = 10;
  int y = 10;
  Coordenada c(5, 5);
  Tablero malla(x, y);
  malla.setObst(c);
  malla.print();
}