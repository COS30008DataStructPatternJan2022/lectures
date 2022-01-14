#include "iostream"
#include "stdio.h"
using namespace std;

class A { 
private: 
  int attrib1; 
  float attrib2; 

  friend float myFriend1(A& a) {
    cout << "(private) myFriend1()" << endl;
    printf("attrib1, attrib2 = %d, %.2f \n", 
              a.attrib1, a.attrib2);

    a.attrib1 = 100, a.attrib2 = 100.5;
    float result = a.attrib1 + a.attrib2;
    printf("(after initialisation) attrib1 + attrib2 = %.2f \n", result);

    return 1;
  }

protected: 
  friend void myFriend2(A& a) {
    cout << "(protected) myFriend2()" << endl;
  }

public: 
  A() {}
  void method1( int argument ); 
  int method2() const; 
  float method3() const; 
  friend float myFriend3(const A& a1, const A& a2 ) {
    cout << "(public) myFriend3()" << endl;
    return 1;
  }  
};

int main() {
  A a = A();
  // friend functions must be defined with at least one parameter of the owner's type
  myFriend1(a);
  myFriend2(a);

  A a1 = A(), a2 = A();
  myFriend3(a1, a2);
}

