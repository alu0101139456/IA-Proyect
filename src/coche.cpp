/**
  * @author Alberto Mendoza Rodríguez, Ángel Julián Bolaño Campos, Iris Estefanía Pereira Domínguez
  * @file coche.cpp
  * @brief Clase Coche que contiene los sensores del coche autónomo, el algoritmo A* y las funciones heurísticas.
  * @details Inteligencia Artificial. Práctica 1 Estrategias de Búsqueda.
  */

#include "coche.hpp"

Coche::Coche(void) {
  inicial_ = nullptr;
  final_ = nullptr;
  actual_ = nullptr;
  longitud_camino_ = 0;
  nodos_expandidos_ = 0;
}

Coche::~Coche(void) {}

bool Coche::sensor_norte(Tablero& tablero) {
  if (actual_ -> get_i() == 0)
    return true;
  return (((tablero.get_celda(actual_ -> get_i() - 1, actual_ -> get_j())) -> get_estado()) == OBSTACULO);
}
 
bool Coche::sensor_sur(Tablero& tablero) {
  if (actual_ -> get_i() == tablero.get_filas() - 1)
    return true;
  return (((tablero.get_celda(actual_ -> get_i() + 1, actual_ -> get_j())) -> get_estado()) == OBSTACULO);
}

bool Coche::sensor_oeste(Tablero& tablero) {
  if (actual_ -> get_j() == 0)
    return true;
  return (((tablero.get_celda(actual_ -> get_i(), actual_ -> get_j() - 1)) -> get_estado()) == OBSTACULO);
}

bool Coche::sensor_este(Tablero& tablero) {
  if (actual_ -> get_j() == tablero.get_columnas() - 1)
    return true;
  return (((tablero.get_celda(actual_ -> get_i(), actual_ -> get_j() + 1)) -> get_estado()) == OBSTACULO);
}

float Coche::heuristicas(Celda* celda) {
  if (heuristica_ == 0) 
    return (abs((celda -> get_i()) - (final_ -> get_i())) + abs((celda -> get_j()) - (final_ -> get_j())));    //Distancia Manhattan
  else
    return (sqrt(pow(((celda -> get_i()) - (final_ -> get_i())), 2) + pow(((celda -> get_j()) - (final_ -> get_j())), 2)));  //Distancia euclidea
}

bool Coche::a_estrella(Tablero& tablero, int heuristica) {
  float min;
  int pos = 0;
  inicial_ = tablero.get_inicial();
  final_ = tablero.get_final();
  heuristica_ = heuristica;
  time_ = clock();
  std::vector<Celda*> open;
  actual_ = tablero.get_inicial();

  actual_ -> set_costeG(0.0);
  actual_ -> set_costeF(heuristicas(actual_));
  open.push_back(actual_);
  actual_ -> set_abierta(true);
  
  while (!open.empty()) {
    min = MAXFLOAT;
    for (unsigned int i = 0; i < open.size(); i++) {
      if (open[i] -> get_costeF() < min) { 
        min = open[i] -> get_costeF();
        actual_ = open[i];
        pos = i;
      }
    }
   
    if (*actual_ == *final_) {
      time_ = clock() - time_;
      reconstruir_camino(actual_);
      return true;
    }
    
    open.erase(open.begin() + pos);
    actual_ -> set_abierta(false);
    actual_ -> set_cerrada(true);
    nodos_expandidos_++;

    if (!sensor_norte(tablero))
      gestionar_vecino(open, tablero.get_celda(actual_ -> get_i() - 1, actual_ -> get_j()));
    if (!sensor_sur(tablero))
      gestionar_vecino(open, tablero.get_celda(actual_ -> get_i() + 1, actual_ -> get_j()));
    if (!sensor_oeste(tablero))
      gestionar_vecino(open, tablero.get_celda(actual_ -> get_i(), actual_ -> get_j() - 1));
    if (!sensor_este(tablero))
      gestionar_vecino(open, tablero.get_celda(actual_ -> get_i(), actual_ -> get_j() + 1));
  }
  time_ = clock() - time_;
  return false;
}

void Coche::gestionar_vecino(std::vector<Celda*>& open, Celda* celda_vecina) {
  float costeG = actual_ -> get_costeG() + 1.0;
  if (celda_vecina -> get_cerrada()) {
    if (costeG < celda_vecina -> get_costeG()) {
      celda_vecina -> set_cerrada(false);
      celda_vecina -> set_abierta(true);
      open.push_back(celda_vecina);
    } else {
        return;
    }
  } else if (celda_vecina -> get_abierta()) {
      if (costeG >= celda_vecina -> get_costeG()) {
        return;
      }
  } else {
      celda_vecina -> set_abierta(true);
      open.push_back(celda_vecina);
  }
  celda_vecina -> set_costeG(costeG);
  celda_vecina -> set_costeF(costeG + heuristicas(celda_vecina));
  celda_vecina -> set_padre(actual_); 
} 

void Coche::reconstruir_camino(Celda* celda) {
  Celda* optima = celda->get_padre();
  longitud_camino_++;
  while (optima->get_padre() != nullptr) {
    optima->set_estado(CAMINO);
    longitud_camino_++;
    optima = (optima -> get_padre());
  }
}

int Coche::nodos_expandidos(void) {
  return nodos_expandidos_;   
}

int Coche::longitud_camino(void) {
  return longitud_camino_;
}

clock_t Coche::tiempo(void) {
  return time_;
}

