#ifndef TABLERO
#define TABLERO

#include <iostream>
#include <SFML/Graphics.hpp>
#include "celda.hpp"

class Tablero : public sf::Drawable {
 public:
  Tablero(void);
  Tablero(int filas, int columnas);
  ~Tablero(void);
  int get_filas(void);
  int get_columnas(void);
  Celda* get_celda(int i, int j);
  Celda* get_inicial(void);
  Celda* get_final(void);
  void set_inicial(int i, int j, bool graphic);
  void set_final(int i, int j, bool graphic);
  void set_obstaculo(int i, int j, bool graphic);
  void modo_aleatorio(int num_obstaculos);
  void redimensionar(sf::RenderWindow& window);
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  
 private:
  int filas_;
  int columnas_;
  Celda* inicial_;
  Celda* final_;
  Celda** malla_;
  float celdas_size_;
  void position_cursor(int &i, int &j);
  int position(int i, int j) const;
};

#endif
