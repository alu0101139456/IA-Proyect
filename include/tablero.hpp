#ifndef TABLERO

#define TABLERO

#include <iostream>
#include <SFML/Graphics.hpp>
#include "celda.hpp"
#include "heuristica.hpp"
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
  int i_inicial_ = -1;
  int j_inicial_ = -1;
  int i_final_ = -1;
  int j_final_ = -1;
  Celda** malla_;
  float celdas_size_;
  void position_cursor(int &i, int &j);
  int position(int i, int j) const;
  FunHeuristica* heuristica_;

 public:
  Tablero(void);
  Tablero(int filas, int columnas);
  ~Tablero(void);
  void set_inicial(int i, int j);
  void set_final(int i, int j);
  void set_obstaculo(int i, int j, bool grafico);
  void modo_aleatorio(int num_obstaculos);
  void redimensionar(sf::RenderWindow& window);
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  void EliminarDeListasVecinos(Celda* celda_obstaculo);
  void update_vecinos( int i, int j);
  bool isInMalla(int i, int j);

  void PrintTest();

  std::vector<Celda*> Aestrella();
  void checkCeldaMenorCoste( std::vector<Celda*>& s_a, uint& win);
  void ReconstruirCamino( std::vector<Celda*>& v, Celda* actual, Celda* temp);

  bool InSet( Celda* celda, std::vector<Celda*> set);
  

};

#endif
