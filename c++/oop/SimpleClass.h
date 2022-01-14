#include "string"
using namespace std;

class SimpleClass {
private: 
  const string Def_Name = "Unnamed";
  string name = Def_Name;

public: 
  // default constructor 
  // SimpleClass() : name("Unnamed") {}

  void setName(string aName) {
    name = aName;
  }

  string getName() {
    return name;
  }
};