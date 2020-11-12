#include "../include/coche.hpp"

Coche::Coche(void) {}

/*Coche::Coche(Tablero& tablero) {
  tablero_ = tablero;
}*/

Coche::~Coche(void) {}

bool Coche::SensorUp( Tablero& tablero) {
  if (GetI() == 0)
    return true;
  return (tablero.get_celda(GetI()- 1, GetJ())->getEstado() == OBSTACULO);
}
 
bool Coche::SensorDown( Tablero& tablero) {
  if (GetI() == tablero.get_filas() - 1)
    return true;
  return (tablero.get_celda(GetI() + 1, GetJ())->getEstado() == OBSTACULO);
}

bool Coche::SensorLeft( Tablero& tablero) {
  if (GetJ() == 0)
    return true;
  return (tablero.get_celda(GetI(), GetJ() - 1)->getEstado() == OBSTACULO);
}

bool Coche::SensorRight(Tablero& tablero) {
  if (GetJ() == tablero.get_columnas() - 1)
    return true;
  return (tablero.get_celda(GetI(), GetJ() + 1)->getEstado() == OBSTACULO);
}

 

bool Coche::a_estrella(Tablero& tablero) {
  
  clock_t t;
  t = clock();
  std::vector<Celda*> open;
  std::vector<Celda*> close;
  celda_final_ = tablero.get_final();
  Celda* celda_actual = tablero.get_inicial();

  celda_actual->setCosteG(0.0);
  celda_actual->setCosteF((*heuristica_)(celda_actual, GetMeta()));
  open.push_back(celda_actual);
  celda_actual -> set_frontera(true);
  
  while (!open.empty()) {
    
    float min = MAXFLOAT;
    for (size_t i = 0; i < open.size(); i++) {
      // std::cout << "[" << open[i]->getCosteF() << "] "; 
      if( open[i]->getCosteF() < min ) { 
        min = open[i]->getCosteF();
        celda_actual = open[i];
      }
    }
    // std::cout << " Minimo: " << min << std::endl;    

    if (*celda_actual == *GetMeta()) {
      t = clock() - t;
      std::cout << "Execution time: " << float(t)/CLOCKS_PER_SEC << "\n";
      reconstruir_camino(celda_actual, tablero);
      return true;
    }
        
    open.erase(open.begin());
    celda_actual -> set_frontera(false);
    celda_actual -> set_evaluado(true);

  UpdatePosition(celda_actual);
    if (!SensorUp(tablero))
      gestionar_vecino(open, celda_actual, tablero.get_celda(celda_actual->Get_i() - 1, celda_actual->Get_j()));
    if (!SensorDown(tablero))
      gestionar_vecino(open, celda_actual, tablero.get_celda(celda_actual->Get_i() + 1, celda_actual->Get_j()));
    if (!SensorLeft(tablero))
      gestionar_vecino(open, celda_actual, tablero.get_celda(celda_actual->Get_i(), celda_actual->Get_j() - 1));
    if (!SensorRight(tablero))
      gestionar_vecino(open, celda_actual, tablero.get_celda(celda_actual->Get_i(), celda_actual->Get_j() + 1));

    
  }
  t = clock() - t;
  std::cout << "Execution time: " << float(t)/CLOCKS_PER_SEC << "\n";
  return false;
}

void Coche::gestionar_vecino(std::vector<Celda*>& open, Celda* celda_actual, Celda* celda_vecina) {
  float costeG = celda_actual->getCosteG() + 1.0;
  if (celda_vecina -> get_evaluado()) {
    if (costeG < celda_vecina->getCosteG()) {
      celda_vecina -> set_evaluado(false);
      celda_vecina->setCosteG(costeG);
      celda_vecina->setCosteF(costeG + (*heuristica_)(celda_vecina, GetMeta()));
      celda_vecina -> set_frontera(true);
      open.push_back(celda_vecina);
    } else {
        return;
    }
  } else if (celda_vecina->get_frontera()) {
    if (costeG < celda_vecina->getCosteG()) {
      celda_vecina->setCosteG(costeG);
      celda_vecina->setCosteF(costeG + (*heuristica_)(celda_vecina, GetMeta()));
    } else {
        return;
    }
  } else {
      celda_vecina->setCosteG(costeG);
      celda_vecina->setCosteF(costeG + (*heuristica_)(celda_vecina, GetMeta()));
      celda_vecina -> set_frontera(true);
      open.push_back(celda_vecina);
  }
  celda_vecina->setPadre(celda_actual);
  // std::sort (open.begin(), open.end()); 
 
  
}
  
void Coche::reconstruir_camino(Celda* celda, Tablero& tablero) {
  Celda* optima = celda->getPadre();
  while (optima->getPadre() != nullptr ) {
    optima->setEstado(CAMINO);
    optima = optima -> getPadre();
  }
  std::cout << "SOLUCIÓN ENCONTRADA" << std::endl;
}


void Coche::SetHeuristic(uint option) {
  switch (option) {
  case 0:
  std::cout << "Seleccionada Manhattan\n";
      heuristica_ = new DistanciaManhattan();
    break;
  case 1:
      std::cout << "Seleccionada Euclidea\n";
      heuristica_ = new DistanciaEuclidea();
    break;
  //More heuristics cases
  default:
      std::cout << "Seleccionada Euclidea\n";
      heuristica_ = new DistanciaManhattan();
    break;
  }
}

void Coche::UpdatePosition( Celda* updateP) {
  pos_i_ = updateP->Get_i();
  pos_j_ = updateP->Get_j();
}

