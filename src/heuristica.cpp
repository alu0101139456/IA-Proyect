#include "heuristica.hpp"


FunHeuristica::FunHeuristica(){}

FunHeuristica::~FunHeuristica(){}


DistanciaEuclidea::DistanciaEuclidea(): FunHeuristica(){}

float DistanciaEuclidea::operator()(const Celda* i, const Celda* f){
  return (sqrt(pow((f->Get_i()-i->Get_i()),2) +pow((f->Get_j()-i->Get_j()),2)));
}


DistanciaManhattan::DistanciaManhattan(): FunHeuristica(){}

float DistanciaManhattan::operator()(const Celda* i, const Celda* f){
  return (abs((i->Get_i() - f->Get_i())) + abs((i->Get_j() - f->Get_j())));
}