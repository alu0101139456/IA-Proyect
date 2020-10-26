#include "../include/tablero.hpp"
#include "../include/celda1.hpp"
#include "../include/celda2.hpp"
#include "../include/celda3.hpp"
#include "../include/celda4.hpp"

//Constructor por defecto.
Tablero::Tablero(void) {
  malla_ = NULL;
}

//Constructor.
Tablero::Tablero(int filas, int columnas) {
  filas_ = filas;
  columnas_ = columnas;
  malla_ = new Celda*[(filas_ + 2) * (columnas_ + 2)];
  for (int i = 0; i < (filas_ + 2); i++) {
    for (int j = 0; j < (columnas_ + 2); j++) {
      if ((i == 0) || (i == filas + 1) || (j == 0) || (j == columnas_ + 1))
        malla_[position(i, j)] = new Celda3(i, j);					//Para crear el borde mediante obstáculos.
      else
        malla_[position(i, j)] = new Celda(i, j);
    }
  }
}

//Destructor.
Tablero::~Tablero(void) {
  for (int i = 0; i < ((filas_ + 2) * (columnas_ + 2)); i++)
    delete malla_[i];
  delete[] malla_;
}

void Tablero::set_inicial(int i, int j) {
  delete malla_[position(i, j)];
  malla_[position(i, j)] = new Celda1(i, j);
}

void Tablero::set_final(int i, int j) {
  delete malla_[position(i, j)];
  malla_[position(i, j)] = new Celda2(i, j);
}

void Tablero::set_obstaculo(int i, int j) {
  delete malla_[position(i, j)];
  malla_[position(i, j)] = new Celda3(i, j);
}

void Tablero::modo_aleatorio(int num_obstaculos) {
  int i_pos, j_pos, contador = 0;
  while (contador < num_obstaculos) {
    i_pos = rand() % filas_ + 1;
    j_pos = rand() % columnas_ + 1;
    if (malla_[position(i_pos, j_pos)] -> getEstado() == 0) {
      set_obstaculo(i_pos, j_pos);
      contador++;
    }
  }
}

//Sobrecarga del operador de salida.
std::ostream& operator<<(std::ostream& os, const Tablero& tablero) {
  int columna_aux = 0;
  os << "   ▄";
  while (columna_aux < tablero.columnas_) {
    os << "▄▄▄▄▄▄▄▄";
    columna_aux++;
  }
  os << "▄\n";
  for (int i = 1; i <= tablero.filas_; i++) {
    os << "   █";
      for (int j = 1; j <= tablero.columnas_; j++)
        os << "╔══════╗";
      os << "█\n" << "   █";
      for (int k = 1; k <= tablero.columnas_; k++) {
        os << "║";
        tablero.malla_[tablero.position(i, k)]->mostrar(std::cout);
        os << "║";
      }
      os << "█\n" << "   █";
      for (int l = 1; l <= tablero.columnas_; l++)
        os << "╚══════╝";
    os << "█\n";
  }
  os << "   ▀";
  columna_aux = 0;
  while (columna_aux < tablero.columnas_) {
    os << "▀▀▀▀▀▀▀▀";
    columna_aux++;
  }
  os << "▀\n";
  return os;
}
     
//Método que calcula la posición del vector en memoria dinámica que es equivalente a la posición (i,j) de la malla.
int Tablero::position(int i, int j) const {
  return i * (columnas_ + 2) + j;
}
