#ifndef TABLERO
#define TABLERO

#include <iostream>
#include <SFML/Graphics.hpp>
#include "celda.hpp"

class Tablero : public sf::Drawable {

 private:
  int filas_;
  int columnas_;
  Celda* inicial_;
  Celda* final_;
  Celda** malla_;
  float celdas_size_;
  void position_cursor(int &i, int &j);
  int position(int i, int j) const;

 public:
 /**
  * @brief Constructor por defecto de Tablero
  * 
  */
  Tablero(void);
  /**
   * @brief Constructor con numero de filas y columnas
   * 
   * @param filas Número de filas que tendrá el tablero
   * @param columnas Número de columnas que tendrá el tablero 
   */
  Tablero(int filas, int columnas);
  /**
   * @brief Destructor por defecto
   * 
   */
  ~Tablero(void);
  /**
   * @brief Getter de número de filas
   * 
   * @return int Devuelve entero
   */
  int get_filas(void);
  /**
   * @brief Getter de número de columnas
   * 
   * @return int Devuelve entero
   */
  int get_columnas(void);
  /**
   * @brief Getter de un puntero a una celda pasada por parametros
   * 
   * @param i Coordenada i de la celda a retornar
   * @param j Coordenada j de la celda a retornar
   * @return Celda* Puntero de la celda
   */
  Celda* get_celda(int i, int j);
  /**
   * @brief Getter del punto de inicio del coche
   * 
   * @return Celda* Devuelve un puntero de la celda donde se comienza 
   */
  Celda* get_inicial(void);
  /**
   * @brief Getter del punto donde deberá llegar el coche
   * 
   * @return Celda* Devuelve puntero de la celda donde se debe llegar
   */
  Celda* get_final(void);
  /**
   * @brief Setter de posición inicial de coche
   * 
   * @param i Coordenada i de donde se iniciará el coche
   * @param j Coordenada j de donde se iniciará el coche
   * @param graphic Verifica si se esta en modo gráfico o de terminal
   */
  void set_inicial(int i, int j, bool graphic);
  /**
   * @brief Setter de posición final donde debe llegar el coche
   * 
   * @param i Coordenada i de donde se terminará el coche
   * @param j Coordenada j de donde se terminará el coche
   * @param graphic Verifica si se esta en modo gráfico o de terminal
   */
  void set_final(int i, int j, bool graphic);
  /**
   * @brief Set the obstaculo object
   * 
   * @param i Coordenada i de un obstaculo a settear
   * @param j Coordenada i de un obstaculo a settear
   * @param graphic Verifica si se esta en modo gráfico o de terminal
   */
  void set_obstaculo(int i, int j, bool graphic);
  /**
   * @brief Recibe un número de obstaculos para settear en el tablero
   * 
   * @param num_obstaculos Número de obstaculos
   */
  void modo_aleatorio(int num_obstaculos);
  /**
   * @brief Redimensionar cuadrádos de intergaz gráfica
   * 
   * @param window Recibe el objeto que opera con la ventana
   */
  void redimensionar(sf::RenderWindow& window);
  /**
   * @brief Dibuja por pantalla 
   * 
   * @param target 
   * @param states 
   */
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  

};

#endif
