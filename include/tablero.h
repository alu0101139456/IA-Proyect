#include "celda.h"
#include <random>

class Tablero {
  private:
    int N, M;
    Celda** tablero;
    Coordenada inicio;
    Coordenada fin;
  public:
    Tablero(int x, int y); //Tener en cuenta los bordes
    ~Tablero();
    void setObst(Coordenada c);
    void print();
};
