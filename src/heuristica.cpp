#include "heuristica.hpp"


FunHeuristica::FunHeuristica(){}

FunHeuristica::~FunHeuristica(){}


DistanciaEuclidea::DistanciaEuclidea(): FunHeuristica(){}

int DistanciaEuclidea::operator()(const Celda* i, const Celda* f){
    return static_cast<int>(sqrt(pow((i->Get_i() - f->Get_i()),2) + pow((i->Get_j() - f->Get_j()), 2)));
}


DistanciaManhattan::DistanciaManhattan(): FunHeuristica(){}

int DistanciaManhattan::operator()(const Celda* i, const Celda* f){
    return static_cast<int>(fabs(static_cast<double>(i->Get_i() - f->Get_i())) + fabs(static_cast<double>(i->Get_j() - f->Get_j())));
}