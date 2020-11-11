#ifndef F_HEURISTICAS_H
#define F_HEURISTICAS_H

#include <cmath>
#include "celda.hpp"

class FunHeuristica {
 public:
  FunHeuristica();
  virtual ~FunHeuristica();
  virtual float operator()(const Celda*, const Celda*) = 0;
};



class DistanciaEuclidea : public FunHeuristica {
 public:
  DistanciaEuclidea();
  float operator()(const Celda*, const Celda*);
};



class DistanciaManhattan : public FunHeuristica {
 public:
  DistanciaManhattan();
  float operator()(const Celda*, const Celda*);
};

#endif // F_HEURISTICAS_H