#include <stdexcept>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <set>
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <ctype.h>
#include <algorithm>

#define MAX_SPE 50
#define MAX_OP 10
#define MAX_SIG 9

 class Token {
   public:
     std::string token;
        
     Token(std::string intoken);
     Token();

     void fRead(char in[50], char out[50], std::set<std::string> set_,
                std::set<std::string>set2_,
		std::set<std::string>set3_);
     void fWrite(char out[50], char const tipo[15]);
   //  void CreateSet(std::string conjunto[], std::set<std::string> set_, 
   //		     int MAX);
     int CheckType();
     bool CheckNoSpecial();
     void Minus();  	
     void Mayus();
 };
