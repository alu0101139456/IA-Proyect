#include "tablero.hpp"

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
        malla_[position(i, j)] = new Celda(i, j, OBSTACULO);					//Para crear el borde mediante obstáculos.
      else
        malla_[position(i, j)] = new Celda(i, j, VACIO);

    }
  }
}
//Cuando se crea la tabla se actualizan los vecinos, si no pertenece a la malla
//el vecino no se crea
void Tablero::update_vecinos( int i, int j) {
  for (size_t k = 0; k < f.size(); k++){
    if (isInMalla(i + f[k], j + c[k]) ) {
      //Si el vecino pertenece a la malla se guarda
      malla_[position(i,j)]->AddVecino(malla_[position(i+f[k], j+c[k])]);
    }
  }    
}


//De los vecinos que tiene esta celda, se elimina de sus listas el obstaculo
void Tablero::EliminarDeListasVecinos(Celda* celda_obstaculo) {
  for ( Celda* vecino : celda_obstaculo->GetVecinos() ) {
    vecino->EliminaVecino(celda_obstaculo);
  }
}

//Este metodo comprueba que las coordenadas estan dentro de la malla
bool Tablero::isInMalla(int i, int j) {
  if( i <= 0 || i > filas_+1 || j <= 0 || j >= columnas_+1) {
    return false;
  } else 
    return true;
}


//Destructor.
Tablero::~Tablero(void) {
  for (int i = 0; i < ((filas_ + 2) * (columnas_ + 2)); i++)
    delete malla_[i];
  delete[] malla_;
}

void Tablero::set_inicial(int i, int j) {
  position_cursor(i, j);
  malla_[position(i, j)] -> setEstado(INICIO);
  if (i_inicial != -1) {
    malla_[position(i_inicial, j_inicial)] -> setEstado(FINAL);
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
  malla_[position(i, j)] -> setEstado(FINAL);
  if (i_final != -1) {
    malla_[position(i_final, j_final)] -> setEstado(VACIO);
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
  if (malla_[position(i, j)] -> getEstado() == OBSTACULO) {
    malla_[position(i, j)] -> setEstado(VACIO);
  } else {
      set_vecinos(malla_[position(i, j)]);
      malla_[position(i, j)] -> setEstado(OBSTACULO);
  }
}

void Tablero::modo_aleatorio(int num_obstaculos) {
  int i_pos, j_pos, contador = 0;
  while (contador < num_obstaculos) {
    i_pos = rand() % filas_ + 1;
    j_pos = rand() % columnas_ + 1;
    if (malla_[position(i_pos, j_pos)] -> getEstado() == VACIO) {
      malla_[position(i_pos, j_pos)] -> setEstado(OBSTACULO);
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

