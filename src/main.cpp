#include <iostream>
#include "../include/tablero.hpp"
#include "../include/coche.hpp"
#include <fstream>
#include <SFML/Graphics.hpp>

int main(void) {

  /*if (!texture.loadFromFile("textura3.png", sf::IntRect(0,0,80,80)));
    return EXIT_FAILURE;
  }*/
  
  int modo;
  system("clear");
  std::cout << "\n--------------------------------- ESTRATEGIAS DE BÚSQUEDA ---------------------------------\n\n";
  std::cout << "¿Desea introducir las características del entorno mediante fichero(0) o de forma manual(1)? ";
  std::cin >> modo;
  Coche coche;
  
  if (modo == 0) {
    std::string fichero;
    std::cout << "\nLos ficheros \".txt\" que se pueden leer son: \n";
    system("ls TestFiles/*.txt");
    std::cout << "\nIntroduzca el nombre del fichero de entrada:  ";
    std::cin >> fichero;
    std::cout << "\n";
    std::ifstream infile(fichero);
    int filas = 0, columnas = 0, inicialx, inicialy, finalx, finaly, nObst, c1, c2, h;
    int n = 0;

    infile >> filas;
    infile >> columnas;
    Tablero tablero(filas, columnas);
    
    infile >> inicialx;
    infile >> inicialy;
    tablero.set_inicial(inicialx, inicialy, false);

    infile >> finalx;
    infile >> finaly;
    tablero.set_final(finalx, finaly, false);

    infile >> h;

    infile >> nObst;
    while (n < nObst) {
      if (infile.eof()) {
        std::cout << "El fichero no ha podido ser leído.\n";
        break;
      }
      infile >> c1;
      infile >> c2;
      tablero.set_obstaculo(c1, c2, false);
      n++;
    }
    infile.close();
    bool solucion = coche.a_estrella(tablero, h);
    
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Entorno", sf::Style::Fullscreen);		//Se crea la ventana de la aplicacion en modo pantalla completa.
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
      }
      window.clear(sf::Color::Black);   //Limpia la ventana con el color negro.   ES OBLIGATORIO.

      window.draw(tablero);   //Para dibujar cualquier cosa.
        
      window.display(); //Muestra lo dibujado en la ventana.	ES OBLIGATORIO.
    }
    
    if (!solucion)
      std::cout << "\n\nNo se ha podido planificar una trayectoria desde el inicio al final.\n";
    
    //Controlar que las posiciones inicial y final están dentro del tablero y que el número de obstáculos es mayor o igual que cero y menor que el número total de celdas.
        
        
    //Controlar que las posiciones de los obstáculos están dentro del tablero y que no coinciden con la posición inicial ni con la final.
     
  } else {
    int filas, columnas, modo;
    std::cout << "\nIntroduzca las dimensiones del entorno:\n";
    std::cout << "Filas: ";
    std::cin >> filas;
    std::cout << "Columnas: ";
    std::cin >> columnas;

    //Hay que controlar si el usuario introduce números menores o iguales que cero.

    Tablero tablero(filas, columnas);
    
    std::cout << "\n¿Desea introducir los obstáculos de manera aleatoria(0) o manual(1)? ";
    std::cin >> modo;

    if (modo == 0) {
      float porcentaje;
      int num_obstaculos;
      std::cout << "Introduzca el porcentaje de obstáculos que habrán en el entorno: ";
      std::cin >> porcentaje;
      num_obstaculos = ((filas * columnas) * (porcentaje / 100));
      srand(time(NULL));
      tablero.modo_aleatorio(num_obstaculos);
    }
    
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Entorno", sf::Style::Fullscreen);		//Se crea la ventana de la aplicacion en modo pantalla completa.
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
          if ((event.type == sf::Event::KeyPressed) && (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)))
            tablero.set_final(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, true);
          if((event.type == sf::Event::MouseButtonPressed) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
            tablero.set_obstaculo(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, true);
          if ((event.type == sf::Event::KeyPressed) && (sf::Keyboard::isKeyPressed(sf::Keyboard::M))) {		//Distancia de Manhattan
            if(!coche.a_estrella(tablero, 0)) {
              std::cout << "\n\nNo se ha podido planificar una trayectoria desde el inicio al final.\n";
              window.close();
            }
          }
          if ((event.type == sf::Event::KeyPressed) && (sf::Keyboard::isKeyPressed(sf::Keyboard::E))) {		//Distancia euclídea
            if(!coche.a_estrella(tablero, 1)) {
              std::cout << "\n\nNo se ha podido planificar una trayectoria desde el inicio al final.\n";
              window.close();
            }
          }
      }
      window.clear(sf::Color::Black);   //Limpia la ventana con el color negro.   ES OBLIGATORIO.

      window.draw(tablero);   //Para dibujar cualquier cosa.
        
      window.display(); //Muestra lo dibujado en la ventana.	ES OBLIGATORIO.
  }
    
    //Controlar que las posiciones inicial y final están dentro del tablero y que el número de obstáculos es mayor o igual que cero y menor que el número total de celdas.
        
        
    //Controlar que las posiciones de los obstáculos están dentro del tablero y que no coinciden con la posición inicial ni con la final.
  }
  std::cout << "\n--------------------------- RESULTADOS DEL ALGORITMO DE BÚSQUEDA --------------------------\n\n";
  std::cout << "\tNúmero total de nodos expandidos: " << coche.nodos_expandidos() << "\n\n";
  std::cout << "\tLongitud del camino mínimo: " << coche.longitud_camino() << "\n\n";
  std::cout << "\tTiempo para obtener el resultado: " << float(coche.tiempo())/CLOCKS_PER_SEC << "\n\n"; 
  return 0;
}
