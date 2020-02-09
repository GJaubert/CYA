/**
   * @file transicion.h
   * @version 1.0
   * @date 20/11/2019
   * @author alu0101240374
   * @brief Leemos y creamos el NFA, aparte de las funciones Move y eClausura.
   */

#include "transicion.h"
#include "estado.h"
#include "alfabeto.h"

class NFA {
  public:
   /** Numero de simbolos*/
    std::string nsimbolos;
   /** Vector de los simbolos del NFA*/ 
    std::vector<alfabeto> simbolos;
   /** Numero de estados*/ 
    std::string nestados;
   /** Vector de estados de NFA*/
    std::vector<estado> estados;
   /** Numero de transiciones*/ 
    std::string ntransiciones;
   /** Vector de transiciones del NFA*/ 
    std::vector<transicion> transiciones;
   /** Numero de estados de aceptacion*/ 
    std::string naceptacion;
   /** Vector de estados de aceptacion del NFA*/ 
    std::vector<estado> aceptacion;
   /** Estado de inicio*/ 
    std::string inicio;
   /** Constructor predeterminado*/ 
    NFA();
   /**
   *@brief Lee el fichero y crea el NFA 
   *@param filein: Nombre del fichero de entrada
   *@return ninguno
   */
    void Read(std::string filein);
   /**
   *@brief Escribe el NFA en un fichero determinado
   *@param fileout: Nombre del fichero de salida
   *@return niguno
   */
    void Write(std::string fileout);
   /**
   *@brief Especifica el NFA en un fichero determinado
   *@param fileout: Nombre del fichero de salida
   *@return niguno
   */
    void Specify(std::string fileout);
   /**
   *@brief Calcula el conjunto de estados transitables sin consumir simbolos
   *@param T: Vector de estados
   *@return Vector de estados
   */
    std::vector<estado> eClausura(std::vector<estado> T);
   /**
   *@brief Calcula el conjunto de estados transitables consumiendo a
   *@param T: vector de estados, a: un simbolo del NFA
   *@return Vector de estados
   */
    std::vector<estado> Move(std::vector<estado> T, char a);
   // void ConstruccionSub();
};
