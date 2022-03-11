#include <iostream>

using namespace std;

// global non-static variable
int gCounter = 1;

// global static variable
static int gLocalCounter = 0;

class A {
private: 
  // non-static data member
  unsigned long id;

  // private static class variable (data member)
  static int LocalClassACounter;

  // private constant-static class variable: must be initialised when declared
  const static int LocalConstClassACounter = 1000;

public:
  A() : id(LocalClassACounter++) {}

  // public static class variable
  static int PublicClassACounter;
  
  void printStates() {
    // local static variable: value persists across function calls
    static int counter = 0;
    counter++;

    cout << endl << "printStates(): " <<  "called " << counter << " (times)" << endl
         << "object id: " << id << endl
         << "gCounter: " << gCounter << endl
         << "gLocalCounter: " << gLocalCounter << endl
         << "LocalClassACounter: " << LocalClassACounter << endl     
         << "LocalConstClassACounter: " << LocalConstClassACounter << endl     
         << "PublicClassACounter: " << PublicClassACounter << endl
        ;
  }

  static void printStaticState() {
    cout << endl << "printStaticState()" << endl
         << "gLocalCounter: " << gLocalCounter << endl
         << "LocalClassACounter: " << LocalClassACounter << endl     
         << "LocalConstClassACounter: " << LocalConstClassACounter << endl     
         << "PublicClassACounter: " << PublicClassACounter << endl
        ;
  }

  void update() {
    cout << endl << "update()" <<endl;
    // processing
    gCounter++;
    gLocalCounter++;
    LocalClassACounter++;

    printStates();
  }

  // static function
  static void staticFunc() {
    // error: id = 100;
    LocalClassACounter *= 2;
  }
};

// Static class variables must be initialized outside the class.
int A::LocalClassACounter = 1;
// error -> int A::LocalConstClassACounter = 1000;
int A::PublicClassACounter = 100;