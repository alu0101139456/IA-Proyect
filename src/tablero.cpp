#include "tablero.h"

Tablero::Tablero(int x, int y) {
  N = x + 2;
  M = y + 2;
  tablero = new Celda*[x + 2];
  for (int i = 0; i < x + 2; i++) {
    tablero[i] = new Celda [y + 2];
  }
  for (int i = 0; i < x + 2; i++) {
    for (int j = 0; j < y + 2; j++) {
      tablero[i][j].setCoordenada(i - 1, j - 1); //posición relativa a la malla útil (sin contar los bordes)
      if ((i == 0) || (i == x + 1) || (j == 0) || (j == y + 1)) {
        tablero[i][j].setObstaculo();
      } 
    }
  }
}

Tablero::~Tablero() {
  for (int i = 0; i < N; i++) {
    delete[] tablero[i];
  }
  delete[] tablero;
}

void Tablero::setObst(Coordenada c) {
  tablero[c.getX()][c.getY()].setObstaculo();
}

void Tablero::print() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      tablero[i][j].print();
    }
    std::cout << std::endl;
  }
}