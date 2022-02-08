// Reference: https://docs.microsoft.com/en-us/cpp/cpp/enumerations-cpp?view=msvc-160

#include "iostream"
using namespace std;

// define a class using the "struct" keyword
struct Point {
  int x;
  int y;
};
 
// define a class using the "class" keyword
class NewPoint {
  // (default) these have private access !!!
  int x; 
  int y;

public:
  int x1; // public: not recommended!
  int y1;

  NewPoint(int aX, int aY) {
    x1 = aX; 
    y1 = aY;
  } 
};

// Define an unscopped enum
enum Color {
  Red = 1,  // set explicit value
  Blue,
  Green
};

int main() {
  Point p{1,2};
  cout << "Point (" << p.x << "," << p.y << ")" << endl;
  
  Color c = Red;
  cout << "Color: " << c << endl;

  NewPoint p1(1,2);
  cout << "NewPoint (" << p1.x1 << "," << p1.y1 << ")" << endl;

}