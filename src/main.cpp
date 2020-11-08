#include <iostream>
#include "tablero.hpp"
#include <fstream>
#include <SFML/Graphics.hpp>



int main(void) {

        /*if (!texture.loadFromFile("textura3.png", sf::IntRect(0,0,80,80)));
        	return EXIT_FAILURE;
        }*/

  int modo;
  // std::cout << "¿Desea introducir las características del entorno mediante fichero(0) o de forma manual(1)? ";
  // std::cin >> modo;

  if ( 1) {


    Tablero tablero(10, 10);
    
    srand(time(NULL));
    tablero.modo_aleatorio(15);
    tablero.PrintVecinoTest();
    tablero.set_inicial(3,1,false);
    tablero.set_final(9,4,false);
    std::cout << "\n\n";
    tablero.PrintEstadoTest();
    tablero.CaminoMinimo();
    tablero.PrintEstadoTest();







 
  } else {
    int filas, columnas, modo;
    std::cout << "Introduzca las dimensiones del entorno:" << std::endl;
    std::cout << "Filas: ";
    std::cin >> filas;
    std::cout << "Columnas: ";
    std::cin >> columnas;

    //Hay que controlar si el usuario introduce números menores o iguales que cero.

    Tablero tablero(filas, columnas);
    
    std::cout << "¿Desea introducir los obstáculos de manera aleatoria(0) o manual(1)? ";
    std::cin >> modo;

    if (modo == 0) {
      int num_obstaculos;
      std::cout << "Introduzca el número de obstáculos que habrán en el entorno: ";
      std::cin >> num_obstaculos;
      srand(time(NULL));
      tablero.modo_aleatorio(num_obstaculos);
    }
    
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "My window", sf::Style::Fullscreen);		//Se crea la ventana de la aplicacion en modo pantalla completa.
    tablero.redimensionar(window);
    window.setVerticalSyncEnabled(true);  //Para hacer que la aplicación se ejecute con la misma frecuencia que el monitor.

    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)){
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
            	window.close();
            if ((event.type == sf::Event::KeyPressed) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))
              tablero.set_inicial(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, true);
            if ((event.type == sf::Event::KeyPressed) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)))
              tablero.set_final(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, true);
            if((event.type == sf::Event::MouseButtonPressed) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
            	tablero.set_obstaculo(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, true);
        }
        window.clear(sf::Color::Black);   //Limpia la ventana con el color negro.   ES OBLIGATORIO.

        window.draw(tablero);   //Para dibujar cualquier cosa.
        
        window.display(); //Muestra lo dibujado en la ventana.	ES OBLIGATORIO.
    }
    
    //Para dibujar hay que seguir el ciclo borrar/ dibujar y mostrar.


    
    //Controlar que las posiciones inicial y final están dentro del tablero y que el número de obstáculos es mayor o igual que cero y menor que el número total de celdas.
        
        
    //Controlar que las posiciones de los obstáculos están dentro del tablero y que no coinciden con la posición inicial ni con la final.
   
       
  }
 
  return 0;
}
