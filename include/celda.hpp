/**
  * @author Alberto Mendoza Rodríguez, Ángel Julián Bolaño Campos, Iris Estefanía Pereira Domínguez
  * @file celda.hpp
  * @brief Clase Celda que representa cada una de las posiciones del tablero, estas pueden ser la posición inicial o final, estar libre o constituir un obstáculo.
  * @details Inteligencia Artificial. Práctica 1 Estrategias de Búsqueda.
  */

#ifndef CELDA
#define CELDA

#include <iostream>
#include <values.h>
#include <SFML/Graphics.hpp>

enum Estado{ LIBRE, INICIO, FINAL, OBSTACULO, CAMINO};

class Celda : public sf::Sprite {
 private:  
  int i_;
  int j_;
  int estado_;
  float costeF_;
  float costeG_;
  Celda* padre_;
  bool cerrada_;
  bool abierta_;
  sf::Texture texture;
  
 public:
 /**
  * @brief Costructor por defecto
  * 
  */
  Celda(void);
  /**
   * @brief Constructor parametrizado
   * 
   * @param i Coordenada i
   * @param j Coordenada j
   * @param estado Estado de la celda, libre, inicial, final, obstaculo
   */
  Celda(int i, int j, int estado);
  /**
   * @brief Destructor de Celda
   * 
   */
  ~Celda(void);
  /**
   * @brief Getter de estado
   * 
   * @return int Devuelve un entero
   */
  int get_estado(void) const;
  /**
   * @brief Getter de CosteF
   * 
   * @return float Devuelve un tipo float con el coste F de la celda
   */
  float get_costeF(void) const;
  /**
   * @brief Getter de CosteG
   * 
   * @return float Devuelve un tipo float con el coste G de la celda
   */
  float get_costeG(void) const;
  /**
   * @brief Getter de la celda padre
   * 
   * @return Celda* Devuelve un puntero
   */
  Celda* get_padre(void);
  /**
   * @brief Getter de la coordenada i
   * 
   * @return int 
   */
  int get_i(void) const;
  /**
   * @brief Getter de la coordenada j
   * 
   * @return int 
   */
  int get_j(void) const;
  /**
   * @brief Utilizado en el algoritmo A* para comprobar si la celda está en la lista cerrada
   * 
   * @return true 
   * @return false 
   */
  bool get_cerrada(void);
  /**
   * @brief Utilizado en el algoritmo A* para comprobar si la celda está en la lista abierta
   * 
   * @return true 
   * @return false 
   */
  bool get_abierta(void);
   /**
   * @brief Set del estado
   * 
   * @param estado 
   */
  void set_estado(int estado);
  /**
   * @brief Set del coste f de la celda
   * 
   * @param coste Recibe una variable float
   */
  void set_costeF(float coste);
  /**
   * @brief Set del coste g de la celda
   * 
   * @param coste Recibe una variable float
   */
  void set_costeG(float coste);
  /**
   * @brief Set del padre de una celda 
   * 
   * @param padre Padre de la celda con puntero
   */
  void set_padre(Celda* padre);
  /**
   * @brief Utilizado en el algoritmo A* para introducir a la celda en la lista cerrada 
   * 
   * @param cerrada 
   */
  void set_cerrada(bool cerrada);
  /**
   * @brief Utilizado en el algoritmo A* para introducir a la celda en la lista abierta 
   * 
   * @param abierta 
   */
  void set_abierta(bool abierta);
  /**
   * @brief Carga las texturas utilizando las imagenes de la carpeta images/
   * 
   * @param estado 
   */
  void cargar_textura(int estado);
  /**
   * @brief Sobrecarga de operador ==
   * 
   * @param celda1 
   * @return true 
   * @return false 
   */
  bool operator==(const Celda& celda1) const;

};

#endif

