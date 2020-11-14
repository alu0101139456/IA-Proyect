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
  bool evaluado_;
  bool frontera_;
  sf::Texture texture;

 public:
 /**
  * @brief Costructor por defecto
  * 
  */
  Celda(void);
  /**
   * @brief Construct a new Celda object
   * 
   * @param i Coordenada i
   * @param j Coordenada j
   * @param estado Estado de la celda, libre, inicial, final, obstaculo
   */
  Celda(int i, int j, int estado);
  /**
   * @brief Destructor de celda
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
   * @brief Utilizado en el algoritmo A* para comprobar los estados evaluados por el algoritmo
   * 
   * @return true 
   * @return false 
   */
  bool get_evaluado(void);
  /**
   * @brief Devuelve si el objeto es frontera
   * 
   * @return true 
   * @return false 
   */
  bool get_frontera(void);
  /**
   * @brief Set del estado
   * 
   * @param estado 
   */
  void set_estado(int estado);
  /**
   * @brief Set el costeF de la celda
   * 
   * @param coste Recibe una variable int
   */
  void set_costeF(float coste);
  /**
   * @brief Set el coste F de la celda
   * 
   * @param coste Recibe una variable Float
   */
  void set_costeG(float coste);
  /**
   * @brief Set el padre de una celda 
   * 
   * @param padre Padre de la celda con puntero
   */
  void set_padre(Celda* padre);
  /**
   * @brief Setter de un objeto evaluado
   * 
   * @param evaluado 
   */
  void set_evaluado(bool evaluado);
  /**
   * @brief Ayuda a delimitar el limite de donde se hacen los caminos
   * 
   * @param frontera 
   */
  void set_frontera(bool frontera);
  /**
   * @brief Carga textura utiliza las texturas en la carpeta images/
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

