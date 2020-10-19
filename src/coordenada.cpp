#include "coordenada.h"

Coordenada::Coordenada(int a, int b):
x(a),
y(b) { }

Coordenada::Coordenada():
x(0),
y(0) { }

int Coordenada::getX() {
  return x;
}
int Coordenada::getY() {
  return y;
}
void Coordenada::setX(int a) {
  x = a;
}
void Coordenada::setY(int b) {
  y = b;
}