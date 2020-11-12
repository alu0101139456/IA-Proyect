#ifndef CELDA
#define CELDA

#include <iostream>
#include <values.h>    ////////MIRARLO
#include <SFML/Graphics.hpp>

enum Estado {VACIO, INICIO, FINAL, OBSTACULO, CAMINO};

class Celda : public sf::Sprite {

 private:  
  int i_;
  int j_;
  int estado_;
  float costeF_ = 0.0;
  float costeG_= 0.0;
  Celda* padre_ = nullptr;
  bool evaluado_;
  bool frontera_;
  sf::Texture texture;
 
 public:
  Celda(void);
  Celda(int i, int j, int estado);
  ~Celda(void);
  int getEstado(void) const;
  float getCosteF(void) const;
  float getCosteG(void) const;
  Celda* getPadre(void);
  int Get_i(void) const;
  int Get_j(void) const;
  bool get_evaluado(void);
    bool get_frontera(void);
  void setEstado(int estado);
  void setCosteF(float coste);
  void setCosteG(float coste);
  void setPadre(Celda* padre);
  void set_evaluado(bool evaluado);
  void set_frontera(bool frontera);
  void cargar_textura(int estado);
  bool operator==(const Celda& celda1) const;		//MIRAR SI QUITARLO
  bool operator<(const Celda& celda1) const;


};

#endif

