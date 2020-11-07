#include "celda.hpp"

//Constructor por defecto.
Celda::Celda(void) : sf::Sprite() {}

//Constructor.
Celda::Celda(int i, int j, int estado) : sf::Sprite() {
  i_ = i;
  j_ = j;
  estado_ = estado;
  cargar_textura(estado_);
}

//Destructor.
 Celda::~Celda(void) {}

int Celda::getEstado(void) const {
  return estado_;
}

void Celda::setEstado(int estado) {
  estado_ = estado;
  cargar_textura(estado);
}

void Celda::cargar_textura(int estado) {
  switch(estado) {
    case 0:
      texture.loadFromFile("images/celda_libre.png", sf::IntRect(0,0,45,45));
      break;
    case 1:
      texture.loadFromFile("images/salida.png", sf::IntRect(0,0,45,45));
      break;
    case 2:
      texture.loadFromFile("images/final.png", sf::IntRect(0,0,45,45));
      break;
    case 3:
      texture.loadFromFile("images/obstaculo.png", sf::IntRect(0,0,45,45));
      break;
  }
  this->setTexture(texture);
}
