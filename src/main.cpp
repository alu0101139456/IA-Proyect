/**
  * @author Alberto Mendoza Rodríguez, Ángel Julián Bolaño Campos, Iris Estefanía Pereira Domínguez
  * @file main.cpp
  * @brief Programa que muestra de manera gráfica la ruta óptima entre dos puntos especificados por el usuario.
  * @details Inteligencia Artificial. Práctica 1 Estrategias de Búsqueda.
  */
  
#include <iostream>
#include "tablero.hpp"
#include "coche.hpp"
#include <fstream>
#include <SFML/Graphics.hpp>

int main(void) {

  //El usuario decide si introducir las características del entorno mendiante fichero o establecer manualmente las filas y las columnas. 
  int modo;
  system("clear");
  std::cout << "\n\033[96m--------------------------------- ESTRATEGIAS DE BÚSQUEDA ---------------------------------\033[0m\n\n";
  std::cout << "¿Desea introducir las características del entorno mediante fichero(0) o establecer las filas y columnas de forma manual(1)? ";
  std::cin >> modo;
  while ((modo != 0) && (modo != 1)) {
    std::cout << "Opción incorrecta. ¿Desea introducir el entorno mediante fichero(0) o de forma manual(1)? ";
    std::cin >> modo;
  }
  Coche coche;
  
  if (modo == 0) {
    //Modo fichero.
    std::string fichero;
    std::cout << "\nLos ficheros \".txt\" que se pueden leer son: \n";
    system("ls TestFiles/*.txt");
    std::cout << "\nIntroduzca el nombre del fichero de entrada:  ";
    std::cin >> fichero;
    std::cout << "\n";
    std::ifstream infile(fichero);
    int filas = 0, columnas = 0, inicialx, inicialy, finalx, finaly, nObst, c1, c2, h;
    int n = 0;

    //Se establecen las filas y las columnas para crear el tablero.
    infile >> filas;
    infile >> columnas;
    Tablero tablero(filas, columnas);
    
    //Se establece la posición inicial.
    infile >> inicialx;
    infile >> inicialy;
    tablero.set_inicial(inicialx, inicialy, false);

    //Se establece la posición final
    infile >> finalx;
    infile >> finaly;
    tablero.set_final(finalx, finaly, false);

    //Se fija la heurística a utilizar.
    infile >> h;

    //Se colocan los obstáculos en las posiciones que indique el fichero.
    infile >> nObst;
    while (n < nObst) {
      if (infile.eof()) {
        std::cout << "Error al leer los obstáculos.\n";
        break;
      }
      infile >> c1;
      infile >> c2;
      tablero.set_obstaculo(c1, c2, false);
      n++;
    }
    infile.close();
    
    //Se llama al método a_estrella para buscar el camino óptimo.
    bool solucion = coche.a_estrella(tablero, h);
    
    //Se crea la ventana de la aplicacion en modo pantalla completa.
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Entorno", sf::Style::Fullscreen);
    tablero.redimensionar(window);
    window.setVerticalSyncEnabled(true);

    //Mientras la ventana se mantenga abierta se controlan las funcionalidades de la interfaz gráfica.
    while (window.isOpen()) {
      sf::Event event;
      while (window.pollEvent(event)){
        if (event.type == sf::Event::Closed)
          window.close();
        if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
          window.close();
      }
      window.clear(sf::Color::Black);   //Limpia la ventana con el color negro.

      window.draw(tablero);   	 //Para dibujar el tablero.
        
      window.display(); 		 //Muestra lo dibujado en la ventana.
    }
    
    if (!solucion)
      std::cout << "\n\n\033[91mNo se ha podido planificar una trayectoria desde el inicio al final.\033[0m\n";
     
  } else {
    //Modo manual.
    int filas, columnas, modo;
    std::cout << "\nIntroduzca las dimensiones del entorno:\n";
    std::cout << "Filas: ";
    std::cin >> filas;
    std::cout << "Columnas: ";
    std::cin >> columnas;

    Tablero tablero(filas, columnas);
     
    std::cout << "\n¿Desea introducir los obstáculos de manera aleatoria(0) o manual(1)? ";
    std::cin >> modo;
    while ((modo != 0) && (modo != 1)) {
    std::cout << "Opción incorrecta. ¿Desea introducir los obstáculos de manera aleatoria(0) o manual(1)? ";
    std::cin >> modo;
    }

    //Modo aleatorio donde el usuario indica el porcentaje de obstáculos y estos se crean en posiciones aleatorias.
    if (modo == 0) {
      float porcentaje;
      int num_obstaculos;
      std::cout << "Introduzca el porcentaje de obstáculos que habrán en el entorno: ";
      std::cin >> porcentaje;
      while ((porcentaje > 100) || (porcentaje < 0)) {
        std::cout << "El porcentaje de obstáculos no es válido. Introduzca un porcentaje correcto: ";
        std::cin >> porcentaje;
      }
      num_obstaculos = ((filas * columnas) * (porcentaje / 100));
      srand(time(NULL));
      tablero.modo_aleatorio(num_obstaculos);
    }
    
    //Se crea la ventana de la aplicacion en modo pantalla completa.
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Entorno", sf::Style::Fullscreen);
    tablero.redimensionar(window);
    window.setVerticalSyncEnabled(true);

    //Mientras la ventana se mantenga abierta se controlan las funcionalidades de la interfaz gráfica.
    while (window.isOpen()) {
      sf::Event event;
      while (window.pollEvent(event)){
        if (event.type == sf::Event::Closed)
          window.close();
        if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
          window.close();
        if ((event.type == sf::Event::KeyPressed) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))
          tablero.set_inicial(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, true);
        if ((event.type == sf::Event::KeyPressed) && (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)))
          tablero.set_final(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, true);
        if ((event.type == sf::Event::MouseButtonPressed) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
          tablero.set_obstaculo(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, true);
        if ((event.type == sf::Event::KeyPressed) && (sf::Keyboard::isKeyPressed(sf::Keyboard::M))) {		//Distancia de Manhattan
          if(!coche.a_estrella(tablero, 0)) {
            std::cout << "\n\n\033[91mNo se ha podido planificar una trayectoria desde el inicio al final.\033[0m\n";
            window.close();
          }
        }
        if ((event.type == sf::Event::KeyPressed) && (sf::Keyboard::isKeyPressed(sf::Keyboard::E))) {		//Distancia euclídea
          if(!coche.a_estrella(tablero, 1)) {
            std::cout << "\n\n\033[91mNo se ha podido planificar una trayectoria desde el inicio al final.\033[0m\n";
            window.close();
          }
        }
      }
      window.clear(sf::Color::Black);   //Limpia la ventana con el color negro.

      window.draw(tablero);   	 //Para dibujar el tablero.
        
      window.display(); 		 //Muestra lo dibujado en la ventana..
    }
  }
  
  std::cout << "\n\033[96m--------------------------- RESULTADOS DEL ALGORITMO DE BÚSQUEDA --------------------------\033[0m\n\n";
  std::cout << "\tNúmero total de nodos expandidos: " << coche.nodos_expandidos() << "\n\n";
  std::cout << "\tLongitud del camino mínimo: " << coche.longitud_camino() << "\n\n";
  std::cout << "\tTiempo para obtener el resultado: " << float(coche.tiempo())/CLOCKS_PER_SEC << "\n\n"; 
  return 0;
}
