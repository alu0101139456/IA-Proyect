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
  void set_inicial(int i, int j);
  void set_final(int i, int j);
  void set_obstaculo(int i, int j);
  void modo_aleatorio(int num_obstaculos);
 void redimensionar(sf::RenderWindow& window);
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

 private:
  int filas_;
  int columnas_;
  int i_inicial;
  int j_inicial;
  int i_final;
  int j_final;
  Celda** malla_;
  float celdas_size_;
  void position_cursor(int &i, int &j);
  int position(int i, int j) const;
};

#endif
