#include <iostream>

/* Adapted from JLBorges's code.
    URL: http://www.cplusplus.com/forum/general/90675/
 */
int main() {
  std::cout << "C++ version: " << __cplusplus << std::endl;
  if ( __cplusplus >= 201400L ) std::cout << "--> C++14\n" ;
  else if( __cplusplus == 201103L ) std::cout << "--> C++11\n" ;
  else if( __cplusplus == 19971L ) std::cout << "--> C++98\n" ;
  else std::cout << "--> pre-standard C++\n" ;
}