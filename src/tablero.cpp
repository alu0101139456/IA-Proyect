#include "../include/tablero.hpp"

//Constructor por defecto.
Tablero::Tablero(void) {
  malla_ = NULL;
}

//Constructor.
Tablero::Tablero(int filas, int columnas) {
  filas_ = filas;
  columnas_ = columnas;
  celdas_size_ = 45;
  malla_ = new Celda*[(filas_ + 2) * (columnas_ + 2)];
  for (int i = 0; i < (filas_ + 2); i++) {
    for (int j = 0; j < (columnas_ + 2); j++) {
      if ((i == 0) || (i == filas + 1) || (j == 0) || (j == columnas_ + 1))
        malla_[position(i, j)] = new Celda(i, j, 3);					//Para crear el borde mediante obstáculos.
      else
        malla_[position(i, j)] = new Celda(i, j, 0);
    }
  }
  i_inicial = -1;
  j_inicial = -1;
  i_final = -1;
  j_final = -1;
}

//Destructor.
Tablero::~Tablero(void) {
  for (int i = 0; i < ((filas_ + 2) * (columnas_ + 2)); i++)
    delete malla_[i];
  delete[] malla_;
}

void Tablero::set_inicial(int i, int j) {
  position_cursor(i, j);
  malla_[position(i, j)] -> setEstado(1);
  if (i_inicial != -1) {
    malla_[position(i_inicial, j_inicial)] -> setEstado(0);
  } 
  if ((i_inicial == i) && (j_inicial == j)) {
    i_inicial = -1;
    j_inicial = -1;
  } else {
      i_inicial = i;
      j_inicial = j;
  }
}

void Tablero::set_final(int i, int j) {
  position_cursor(i, j);
  malla_[position(i, j)] -> setEstado(2);
  if (i_final != -1) {
    malla_[position(i_final, j_final)] -> setEstado(0);
  } 
  if ((i_final == i) && (j_final == j)) {
    i_final = -1;
    j_final = -1;
  } else {
      i_final = i;
      j_final = j;
  }
}


void Tablero::set_obstaculo(int i, int j) {
  position_cursor(i, j);
  if (malla_[position(i, j)] -> getEstado() == 3) {
    malla_[position(i, j)] -> setEstado(0);
  } else {
      malla_[position(i, j)] -> setEstado(3);
  }
}

void Tablero::modo_aleatorio(int num_obstaculos) {
  int i_pos, j_pos, contador = 0;
  while (contador < num_obstaculos) {
    i_pos = rand() % filas_ + 1;
    j_pos = rand() % columnas_ + 1;
    if (malla_[position(i_pos, j_pos)] -> getEstado() == 0) {
      malla_[position(i_pos, j_pos)] -> setEstado(3);
      contador++;
    }
  }
}

void Tablero::redimensionar(sf::RenderWindow& window) {
  celdas_size_ = window.getSize().x / (columnas_ + 2);
  if (((filas_ + 2) * celdas_size_) > window.getSize().y)
    celdas_size_ = window.getSize().y / (filas_ + 2);
    
  for (int i = 1; i <= filas_; i++) {
    for (int j = 1; j <= columnas_; j++) {
        malla_[position(i, j)]-> setPosition(celdas_size_*j, celdas_size_*i);
        malla_[position(i, j)] -> setScale(celdas_size_/45, celdas_size_/45);
      }
    }
}

void Tablero::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  for (int i = 1; i <= filas_; i++) {
    for (int j = 1; j <= columnas_; j++) {
      target.draw(*malla_[position(i, j)]);
    }
  }
}

//Método que calcula la posición del vector en memoria dinámica que es equivalente a la posición (i,j) de la malla.
int Tablero::position(int i, int j) const {
  return i * (columnas_ + 2) + j;
}

void Tablero::position_cursor(int &i, int &j) {
  int i_aux = 0;
  int j_aux = 0;
  i = i - celdas_size_;
  j = j - celdas_size_;
  while (i > 0) {
    i = i - celdas_size_;
    i_aux++;
  }
  while (j > 0) {
    j = j - celdas_size_;
    j_aux++;
  }
  i = j_aux;
  j = i_aux;
}
