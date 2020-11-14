#ifndef COCHE
#define COCHE

#include <iostream>
#include <list>
#include <cmath>
#include <ctime>
#include <math.h>
#include <algorithm>
#include "tablero.hpp"
#include "celda.hpp"

class Coche {
 public:
  Coche(void);
  ~Coche(void);
  bool sensor_norte(Tablero& tablero);
  bool sensor_sur(Tablero& tablero);
  bool sensor_oeste(Tablero& tablero);
  bool sensor_este(Tablero& tablero);
  float heuristicas(Celda* celda, Tablero& tablero);
  bool a_estrella(Tablero& tablero, int heuristica);
  void gestionar_vecino(std::vector<Celda*>& open, Celda* celda_vecina, Tablero& tablero);
  void reconstruir_camino(Celda* celda);
  int nodos_expandidos(void);
  int longitud_camino(void);
  clock_t tiempo(void);
  
 private:
  Celda* inicial_;
  Celda* final_;
  Celda* actual_;
  int heuristica_;
  clock_t time_;
  int longitud_camino_;
  int nodos_expandidos_;
};

#endif
