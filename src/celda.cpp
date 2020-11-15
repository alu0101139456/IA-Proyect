/**
  * @author Alberto Mendoza Rodríguez, Ángel Julián Bolaño Campos, Iris Estefanía Pereira Domínguez
  * @file celda.cpp
  * @brief Clase Celda que representa cada una de las posiciones del tablero, estas pueden ser la posición inicial o final, estar libre o constituir un obstáculo.
  * @details Inteligencia Artificial. Práctica 1 Estrategias de Búsqueda.
  */

#include "celda.hpp"

Celda::Celda(void) : sf::Sprite() {}

Celda::Celda(int i, int j, int estado) : sf::Sprite() {
  i_ = i;
  j_ = j;
  estado_ = estado;
  cargar_textura(estado_);
  costeG_ = MAXFLOAT;
  costeF_ = MAXFLOAT;
  padre_ = nullptr;
  cerrada_ = false;
  abierta_ = false;
}

 Celda::~Celda(void) {}

int Celda::get_estado(void) const {
  return estado_;
}

float Celda::get_costeF(void) const {
  return costeF_;
}

float Celda::get_costeG(void) const {
  return costeG_;
}

Celda* Celda::get_padre(void) {
  return padre_;
}

int Celda::get_i(void) const {
  return i_;
}

int Celda::get_j(void) const {
  return j_;
}

bool Celda::get_cerrada(void) {
  return cerrada_;
}

bool Celda::get_abierta(void) {
  return abierta_;
}

void Celda::set_estado(int estado) {
  estado_ = estado;
  cargar_textura(estado);
}

void Celda::set_costeF(float coste) {
  costeF_ = coste;
}

void Celda::set_costeG(float coste) {
  costeG_ = coste;
}

void Celda::set_padre(Celda* padre) {
  padre_ = padre;
}

void Celda::set_cerrada(bool cerrada) {
  cerrada_ = cerrada;
}

void Celda::set_abierta(bool abierta) {
  abierta_ = abierta;
}

void Celda::cargar_textura(int estado) {
  switch(estado) {
    case 0:
      texture.loadFromFile("images/celda_libre.png", sf::IntRect(0,0,45,45));
      break;
    case 1:
      texture.loadFromFile("images/inicio.png", sf::IntRect(0,0,45,45));
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
