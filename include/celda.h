#include "coordenada.h"

class Celda {
  private:
		bool obstaculo;
		Coordenada c;
  public:
		Celda();
		~Celda() { }
		void setObstaculo();
		bool getObstaculo();
		void setCoordenada(int a, int b);
		Coordenada getCoordenada();
		void print();
};
