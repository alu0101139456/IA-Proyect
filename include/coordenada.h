#include <iostream>
class Coordenada {
  private:
		int x; //Fila
		int y; //Columna
  public:
		Coordenada(int a, int b);
		Coordenada();
		~Coordenada() { }
		int getX();
		int getY();
		void setX(int a);
		void setY(int b);
};
   