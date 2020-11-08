#ifndef CELDA
#define CELDA

#include <iostream>
#include <SFML/Graphics.hpp>

enum Estado{ VACIO, INICIO, FINAL, OBSTACULO};

class Celda : public sf::Sprite {
 private: 
  int i_;
  int j_;
  int estado_;
  sf::Texture texture;
  int coste_acumulado_;
  int coste_final_;
  std::vector<Celda*> vecinos_; //Almacena las celdas accesibles(sin obstaculos)
  Celda* padre_; //Almacena la celda vecina con menor coste de llegada(CaminoMinimo)


 public:
  Celda(void);
  Celda(int i, int j, int estado);
  ~Celda(void);
  int getEstado(void) const;
  void setEstado(int estado);
  void cargar_textura(int estado);
  inline int Get_i() const { return i_; }
  inline int Get_j() const { return j_; }
  inline Celda* GetPadre() const {return padre_; }
  inline void SetPadre(Celda* padre) { padre_ = padre; }
  inline Celda* GetVecino(int i) { return vecinos_[i]; }
  inline void ResetVecinos() { vecinos_.clear(); }
  inline void AddVecino(Celda* celda) { vecinos_.push_back(celda); }
  inline std::vector<Celda*> GetVecinos() { return vecinos_; }
  bool EliminaVecino( Celda* eliminaVecino);


};

#endif

