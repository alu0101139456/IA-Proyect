#include <iostream>
#include "../include/tablero.hpp"

int main(void) {
  int modo;
  std::cout << "¿Desea introducir las características del entorno mediante fichero(0) o de forma manual(1)? ";
  std::cin >> modo;
  if (modo == 0) {
    //Aquí va el código para el fichero.
 
  } else {
    int filas, columnas;
    std::cout << "Introduzca las dimensiones del entorno:" << std::endl;
    std::cout << "Filas: ";
    std::cin >> filas;
    std::cout << "Columnas: ";
    std::cin >> columnas;

    //Hay que controlar si el usuario introduce números menores o iguales que cero.

    Tablero tablero(filas, columnas);

    int num_obstaculos, i_pos, j_pos;
    std::cout << "Introduzca la posición (i, j) de la casilla inicial: " << std::endl;
    std::cout << "i: ";
    std::cin >> i_pos;
    std::cout << "j: ";
    std::cin >> j_pos;
    tablero.set_inicial(i_pos, j_pos);
    std::cout << "Introduzca la posición (i, j) de la casilla final: " << std::endl;
    std::cout << "i: ";
    std::cin >> i_pos;
    std::cout << "j: ";
    std::cin >> j_pos;
    tablero.set_final(i_pos, j_pos);
    std::cout << "Introduzca el número de obstáculos que habrán en el entorno: ";
    std::cin >> num_obstaculos;

    //Controlar que las posiciones inicial y final están dentro del tablero y que el número de obstáculos es mayor o igual que cero y menor que el número total de celdas.

    std::cout << "¿Desea introducir los obstáculos de manera aleatoria(0) o manual(1)? ";
    std::cin >> modo;

    if (modo == 0) {
      srand(time(NULL));
      tablero.modo_aleatorio(num_obstaculos);
    } else {
      for (int i = 0; i < num_obstaculos; i++) {
        std::cout << "Introduzca la posición (i, j) del obstáculo " << i + 1 << ":" << std::endl;
        std::cout << "i: ";
        std::cin >> i_pos;
        std::cout << "j: ";
        std::cin >> j_pos;
        
        //Controlar que las posiciones de los obstáculos están dentro del tablero y que no coinciden con la posición inicial ni con la final.
   
        tablero.set_obstaculo(i_pos, j_pos);
      }
    }
    std::cout << "\nRESULTADO:\n" << tablero;
  }
 
  return 0;
}
