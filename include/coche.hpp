#ifndef COCHE

#define COCHE

#include <iostream>
#include <vector>
#include <ctime>
#include "tablero.hpp"
#include "celda.hpp"
#include "heuristica.hpp"
#include <set>

enum HeuristicFuntion{ Manhattan, Euclidea };

class Coche {

 private:
  int pos_i_;
  int pos_j_;
  FunHeuristica* heuristica_;
  Celda* celda_final_ = nullptr;

 public:
  Coche(void);
  Coche(Celda* inicio, Celda* meta);
  ~Coche(void);
  
  bool a_estrella(Tablero& tablero);
  void SetHeuristic(uint option);
  
 private:
  bool SensorUp(Tablero& tablero);
  bool SensorDown(Tablero& tablero);
  bool SensorLeft(Tablero& tablero);
  bool SensorRight(Tablero& tablero);
  void gestionar_vecino(std::vector<Celda*>& open, Celda* celda_actual, Celda* celda_vecina);
  void reconstruir_camino(Celda* celda, Tablero& tablero);
  void UpdatePosition( Celda* updateP);
  inline int GetI() const { return pos_i_; }
  inline int GetJ() const { return pos_j_; }
  inline Celda* GetMeta() { return celda_final_; }


};

#endif
