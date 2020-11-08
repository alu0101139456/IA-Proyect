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
  for (int i = 1; i < (filas_ + 1); i++) {
    for (int j = 1; j < (columnas_ + 1); j++) {
      update_vecinos(i,j);
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

void Tablero::PrintTest() {
  for (int i = 1; i < (filas_ + 1); i++) {
    for (int j = 1; j < (columnas_ + 1); j++) {
      std::cout << malla_[position(i,j)]->GetVecinos().size() << " ";
    }
    std::cout << '\n';
  }

}


//De los vecinos que tiene esta celda, se elimina de sus listas el obstaculo
void Tablero::EliminarDeListasVecinos(Celda* celda_obstaculo) {

  for ( Celda* vecino : celda_obstaculo->GetVecinos() ) {
    vecino->EliminaVecino(celda_obstaculo);
  }
  celda_obstaculo->ResetVecinos();
}

//Este metodo comprueba que las coordenadas estan dentro de la malla
bool Tablero::isInMalla(int i, int j) {
  if( i <= 0 || i >= filas_+1 || j <= 0 || j >= columnas_+1) {
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
  if (i_inicial_ != -1) {
    malla_[position(i_inicial_, j_inicial_)] -> setEstado(FINAL);
  } 
  if ((i_inicial_ == i) && (j_inicial_ == j)) {
    i_inicial_ = -1;
    j_inicial_ = -1;
  } else {
      i_inicial_ = i;
      j_inicial_ = j;
  }
}

void Tablero::set_final(int i, int j) {
  position_cursor(i, j);
  malla_[position(i, j)] -> setEstado(FINAL);
  if (i_final_ != -1) {
    malla_[position(i_final_, j_final_)] -> setEstado(VACIO);
  } 
  if ((i_final_== i) && (j_final_ == j)) {
    i_final_ = -1;
    j_final_ = -1;
  } else {
      i_final_ = i;
      j_final_ = j;
  }
}


void Tablero::set_obstaculo(int i, int j, bool grafico) {
  if (grafico) position_cursor(i, j);
  if (malla_[position(i, j)] -> getEstado() == OBSTACULO) {
    malla_[position(i, j)] -> setEstado(VACIO);
  } else {
      EliminarDeListasVecinos(malla_[position(i, j)]);
      malla_[position(i, j)] -> setEstado(OBSTACULO);
  }
}

void Tablero::modo_aleatorio(int num_obstaculos) {
  int i_pos, j_pos, contador = 0;
  while (contador < num_obstaculos) {
    i_pos = rand() % filas_ + 1;
    j_pos = rand() % columnas_ + 1;
    if (malla_[position(i_pos, j_pos)] -> getEstado() == VACIO) {
      // malla_[position(i_pos, j_pos)] -> setEstado(OBSTACULO);
      set_obstaculo(i_pos, j_pos, false);
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

std::vector<Celda*> Tablero::Aestrella() {
  std::vector<Celda*> camino_final;
  std::vector<Celda*> set_abierto;
  std::vector<Celda*> set_cerrado;
  Celda* inicio = malla_[position(i_inicial_, j_inicial_)];
  Celda* final = malla_[position(i_final_, j_final_)];
  inicio->SetCosteAcumulado(0);
  inicio->SetCosteFinal((*heuristica_)(inicio, final));


  set_abierto.push_back(inicio);

  while ( !set_abierto.empty()) {
    uint win = 0;
    checkCeldaMenorCoste(set_abierto, win);

    Celda* actual = malla_[position(set_abierto[win]->Get_i(), set_abierto[win]->Get_j())];

    //Si es la misma celda, obtenemos el camino óptimo
    if ((actual->Get_i() == i_final_) && (actual->Get_j() == j_final_) ) {
      ReconstruirCamino(camino_final, actual, inicio);
      return camino_final;
    }
    
    set_abierto.erase(set_abierto.begin() + win);
    set_cerrado.push_back(actual);
    
    for ( Celda* vecino : actual->GetVecinos() ) {
      if( InSet(vecino, set_cerrado))
        continue;
      int aux = actual->GetCosteAcumulado() + 1;

      if( !InSet(vecino, set_abierto)) {
        set_abierto.push_back(vecino);
      } else if ( aux >= vecino->GetCosteAcumulado())
            continue;
      
      vecino->SetPadre(actual);
      vecino->SetCosteAcumulado(aux);
      vecino->SetCosteFinal(aux + (*heuristica_)(vecino, final));
    }
  }
  return camino_final;
}


void Tablero::checkCeldaMenorCoste( std::vector<Celda*>& s_a, uint& win) {
for (uint i = 0; i < s_a.size(); i++) {
    if(s_a[i]->GetCosteFinal() < s_a[win]->GetCosteFinal())
      win = i; //Buscamos la celda con menor coste final;
  }
}


void Tablero::ReconstruirCamino( std::vector<Celda*>& v, Celda* actual, Celda* temp) {
  Celda* a = actual;
  v.push_back(a);
  while (a->Get_i() != temp->Get_i() || a->Get_j() != temp->Get_j()) { //Controla que no llegue a la celda inicial
    v.push_back(a->GetPadre());
  }  
}


bool Tablero::InSet(Celda* celda, std::vector<Celda*> set) {
  for(unsigned int i = 0; i < set.size(); i++) {
    if (set[i] == celda)
      return true;
  }
  return false;
}


