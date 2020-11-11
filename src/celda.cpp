#include "../include/celda.hpp"

//Constructor por defecto.
Celda::Celda(void) : sf::Sprite() {}

//Constructor.
Celda::Celda(int i, int j, int estado) : sf::Sprite() {
  i_ = i;
  j_ = j;
  estado_ = estado;
  cargar_textura(estado_);
  costeG_ = MAXFLOAT;
  costeF_ = MAXFLOAT;
  padre_ = nullptr;
  evaluado_ = false;
  frontera_ = false;
}

//Destructor.
 Celda::~Celda(void) {}

int Celda::getEstado(void) const {
  return estado_;
}

float Celda::getCosteF(void) const {
  return costeF_;
}

float Celda::getCosteG(void) const {
  return costeG_;
}

int Celda::Get_i(void) const {
  return i_;
}

int Celda::Get_j(void) const {
  return j_;
}

bool Celda::get_evaluado(void) {
  return evaluado_;
}

bool Celda::get_frontera(void) {
  return frontera_;
}

void Celda::setCosteF(float coste) {
  costeF_ = coste;
}

void Celda::setCosteG(float coste) {
  costeG_ = coste;
}

void Celda::setEstado(int estado) {
  estado_ = estado;
  cargar_textura(estado);
}

void Celda::setPadre(Celda* padre) {
  padre_ = padre;
}

void Celda::set_evaluado(bool evaluado) {
  evaluado_ = evaluado;
}

void Celda::set_frontera(bool frontera) {
  frontera_ = frontera;
}

Celda* Celda::getPadre(void) {
  return padre_;
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
    case 4:
      texture.loadFromFile("images/camino.png", sf::IntRect(0,0,45,45));
      break;
  }
  this->setTexture(texture);
}

bool Celda::operator==(const Celda& celda1) const {
  return ((i_ == celda1.i_) && (j_ == celda1.j_));
} 

bool Celda::operator<(const Celda& celda1) const {
  return (costeF_ < celda1.costeF_);
}
