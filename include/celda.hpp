#ifndef CELDA
#define CELDA

#include <iostream>
#include <SFML/Graphics.hpp>

class Celda : public sf::Sprite {
 public:
  Celda(void);
  Celda(int i, int j, int estado);
  ~Celda(void);
  int getEstado(void) const;
  void setEstado(int estado);
  void cargar_textura(int estado);

 private: 
  int i_;
  int j_;
  int estado_;
  sf::Texture texture;
};

#endif

