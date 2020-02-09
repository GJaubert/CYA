/**
  * @file DFAWriter.h
  * @version 1.0
  * @date 29/10/2019
  * @author alu0101240374
  * @brief Usamos esta clase para escribir el DFA resutlante en formato DOT.
  */

#include "DFA.h"

 class DFAWriter {
   public:
     /** Fichero de salida ofstream*/
     std::ofstream ficherout;
     /** Nombre del fichero de salida*/
     std::string out;
     /** Constructor predeterminado*/
     DFAWriter();
     /** Constructor con string de parametro*/
     DFAWriter(std::string str);
     /**
      *@brief Comienza el proceso de escritura
      *@param objeto DFA
      *@return ninguno
     */
     void MainWrite(DFA dfa_);
     /**
     *@brief Escribe siempre los mismo para los codigos: tamaño y formato
     *@param objeto DFA
     *@return ninguno
     */
     void WriteStandard(DFA dfa_);
     /**
      *@brief Escribe el apartado "Shapes"
      *@param objeto DFA
      *@return ninguno
     */
     void WriteShapes(DFA dfa_); 
     /**
      *@brief Imprime el apartado de los transiciones
      *@param objeto DFA
      *@return ninguno
     */
     void WriteDelta(DFA dfa_);
 };
