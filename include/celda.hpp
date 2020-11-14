#ifndef CELDA
#define CELDA

#include <iostream>
#include <values.h>
#include <SFML/Graphics.hpp>

enum Estado{ LIBRE, INICIO, FINAL, OBSTACULO, CAMINO};

class Celda : public sf::Sprite {
 public:
  Celda(void);
  Celda(int i, int j, int estado);
  ~Celda(void);
  int get_estado(void) const;
  float get_costeF(void) const;
  float get_costeG(void) const;
  Celda* get_padre(void);
  int get_i(void) const;
  int get_j(void) const;
  bool get_evaluado(void);
  bool get_frontera(void);
  void set_estado(int estado);
  void set_costeF(float coste);
  void set_costeG(float coste);
  void set_padre(Celda* padre);
  void set_evaluado(bool evaluado);
  void set_frontera(bool frontera);
  void cargar_textura(int estado);
  bool operator==(const Celda& celda1) const;

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
};

#endif

