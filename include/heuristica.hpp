#ifndef F_HEURISTICAS_H
#define F_HEURISTICAS_H

#include <cmath>
#include "celda.hpp"

class FunHeuristica {
 public:
  FunHeuristica();
  virtual ~FunHeuristica();
  virtual int operator()(const Celda&, const Celda&) = 0;
};


//-----------------------DISTANCIA EUCLIDEA-------------------------

class DistanciaEuclidea : public FunHeuristica {
 public:
  DistanciaEuclidea();
  int operator()(const Celda&, const Celda&);
};


//-----------------------DISTANCIA RECTILINEA-----------------------

class DistanciaManhattan : public FunHeuristica {
 public:
  DistanciaManhattan();
  int operator()(const Celda&, const Celda&);
};

#endif // F_HEURISTICAS_H