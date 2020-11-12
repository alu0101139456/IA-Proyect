#include "../include/tablero.hpp"

//Constructor por defecto.
Tablero::Tablero(void) {
  malla_ = NULL;
  inicial_ = NULL;
  final_ = NULL;
}

//Constructor.
Tablero::Tablero(int filas, int columnas) {
  filas_ = filas;
  columnas_ = columnas;
  celdas_size_ = 45;
  malla_ = new Celda*[filas_ * columnas_];
  for (int i = 0; i < filas_; i++) {
    for (int j = 0; j < columnas_; j++) {			
        malla_[position(i, j)] = new Celda(i, j, VACIO);
    }
  }
  inicial_ = 0;
  final_ = 0;
}

//Destructor.
Tablero::~Tablero(void) {
  for (int i = 0; i < (filas_ * columnas_); i++)
    delete malla_[i];
  delete[] malla_;
}

int Tablero::get_filas(void) {
  return filas_;
}

int Tablero::get_columnas(void) {
  return columnas_;
}

Celda* Tablero::get_celda(int i, int j) {
  return malla_[position(i, j)];
}

Celda* Tablero::get_inicial(void) {
  return inicial_;
}

Celda* Tablero::get_final(void) {
  return final_;
}

void Tablero::set_inicial(int i, int j, bool graphic) {
  if( graphic)  position_cursor(i, j);
  malla_[position(i, j)] -> setEstado(INICIO);
  if (inicial_ != nullptr ) {
    inicial_ -> setEstado(VACIO);
  }
  if (inicial_ == malla_[position(i, j)]) {
    inicial_ = nullptr;
  } else {
      inicial_ = &(*malla_[position(i, j)]);
  }
}

void Tablero::set_final(int i, int j, bool graphic) {
  if( graphic)  position_cursor(i, j);
  malla_[position(i, j)] -> setEstado(FINAL);
  if (final_ != nullptr) {
    final_ -> setEstado(VACIO);
  } 
  if (final_ == malla_[position(i, j)]) {
    final_ = nullptr;
  } else {
      final_ = &(*malla_[position(i, j)]);
  }
}


void Tablero::set_obstaculo(int i, int j, bool graphic) {
  if( graphic)  position_cursor(i, j);
  if (malla_[position(i, j)]->getEstado() == OBSTACULO) {
    malla_[position(i, j)]->setEstado(VACIO);
  } else {
      malla_[position(i, j)]->setEstado(OBSTACULO);
  }
}

void Tablero::modo_aleatorio(int num_obstaculos) {
  int i_pos, j_pos, contador = 0;
  while (contador < num_obstaculos) {
    i_pos = rand() % filas_;
    j_pos = rand() % columnas_;
    if (malla_[position(i_pos, j_pos)]->getEstado() == 0) {
      malla_[position(i_pos, j_pos)]->setEstado(OBSTACULO);
      contador++;
    }
  }
}

void Tablero::redimensionar(sf::RenderWindow& window) {
  celdas_size_ = window.getSize().x / columnas_;
  if ((filas_ * celdas_size_) > window.getSize().y)
    celdas_size_ = window.getSize().y / filas_;
    
  for (int i = 0; i < filas_; i++) {
    for (int j = 0; j < columnas_; j++) {
        malla_[position(i, j)]-> setPosition(celdas_size_*j, celdas_size_*i);
        malla_[position(i, j)] -> setScale(celdas_size_/45, celdas_size_/45);
      }
    }
}

void Tablero::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  for (int i = 0; i < filas_; i++) {
    for (int j = 0; j < columnas_; j++) {
      target.draw(*malla_[position(i, j)]);
    }
  }
}

//Método que calcula la posición del vector en memoria dinámica que es equivalente a la posición (i,j) de la malla.
int Tablero::position(int i, int j) const {
  return i * columnas_ + j;
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

void Tablero::PrintTable() {
  for (int i = 0; i < filas_; i++) {
    for (int j = 0; j < columnas_; j++) {			
        std::cout << malla_[position(i, j)]->getEstado() << " ";
    }
    std::cout << "\n";
  }

}
