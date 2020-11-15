/**
  * @author Alberto Mendoza Rodríguez, Ángel Julián Bolaño Campos, Iris Estefanía Pereira Domínguez
  * @file coche.hpp
  * @brief Clase Coche que contiene los sensores del coche autónomo, el algoritmo A* y las funciones heurísticas.
  * @details Inteligencia Artificial. Práctica 1 Estrategias de Búsqueda.
  */

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
 private:
 /**
  * @brief El coche conoce el lugar desde el que sale
  * 
  */
  Celda* inicial_;
  /**
   * @brief El coche conoce donde tiene que ir
   * 
   */
  Celda* final_;
  /**
   * @brief Lugar donde se encuentra el coche
   * 
   */
  Celda* actual_;
  int heuristica_;
  clock_t time_;
  int longitud_camino_;
  int nodos_expandidos_;
 public:
  /**
  * @brief Constructor por defecto
  * 
  */
  Coche(void);
  /**
   * @brief Destructor por defecto
   * 
   */
  ~Coche(void);
  /**
   * @brief Sensor Norte
   * 
   * @param tablero 
   * @return true 
   * @return false 
   */
  bool sensor_norte(Tablero& tablero);
  /**
   * @brief Sensor Sur
   * 
   * @param tablero 
   * @return true 
   * @return false 
   */
  bool sensor_sur(Tablero& tablero);
  /**
   * @brief Sensor Oeste
   * 
   * @param tablero 
   * @return true 
   * @return false 
   */
  bool sensor_oeste(Tablero& tablero);
  /**
   * @brief Sensor Este
   * 
   * @param tablero 
   * @return true 
   * @return false 
   */
  bool sensor_este(Tablero& tablero);
  /**
   * @brief Heuristicas que sigue el coche
   * 
   * @param celda Recibe la celda dede la que calcular el coste
   * @return float 
   */
  float heuristicas(Celda* celda);
  /**
   * @brief Algoritmo A* que busca el camino óptimo entre la posición inicial y final
   * 
   * @param tablero Tablero pasado por referencia
   * @param heuristica Entero indicando la heurística a utilizar
   * @return true 
   * @return false 
   */
  bool a_estrella(Tablero& tablero, int heuristica);
  /**
   * @brief Getionar Vecino se encarga de calcular las heurísticas desde el punto analizado hasta la meta y gestionar las listas abiertas y cerradas
   * 
   * @param open Conjunto de los posibles nodos a visitar 
   * @param celda_vecina Celda desde la que queremos verificar distancias
   */
  void gestionar_vecino(std::vector<Celda*>& open, Celda* celda_vecina);
  /**
   * @brief Recostruye el camino que se fue guardando en cada uno de los padres de las celdas elegidas como óptimas
   * 
   * @param celda 
   */
  void reconstruir_camino(Celda* celda);
  /**
   * @brief Getter de los nodos expandidos durante la ejecución del algoritmo
   * 
   * @return int 
   */
  int nodos_expandidos(void);
  /**
   * @brief Getter de la longitud camino mínimo
   * 
   * @return int 
   */
  int longitud_camino(void);
  /**
   * @brief Getter del tiempo que tarda en ejecutarse el A* 
   * 
   * @return clock_t 
   */
  clock_t tiempo(void);
  

};

#endif
