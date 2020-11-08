#ifndef TABLERO

#define TABLERO

#include <iostream>
#include <SFML/Graphics.hpp>
#include "celda.hpp"

// estados:
// 1 -> Inicio
// 2 -> Final
// 3 -> Obstaculo



class Tablero : public sf::Drawable {
 private:
  std::vector<int> f = {-1, 0, 1, 0};//Coordenadas para los vecinos
  std::vector<int> c = { 0,-1, 0, 1};
  int filas_;
  int columnas_;
  int i_inicial = -1;
  int j_inicial = -1;
  int i_final = -1;
  int j_final = -1;
  Celda** malla_;
  float celdas_size_;
  void position_cursor(int &i, int &j);
  int position(int i, int j) const;

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
  void EliminarDeListasVecinos(Celda* celda_obstaculo);
  void update_vecinos( int i, int j);
  bool isInMalla(int i, int j);


};

#endif
