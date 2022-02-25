#include <iostream>

using namespace std;

// move n disks from target to target, using middle to buffer
void move(int n, string start, string target, string middle) {
  if (n > 0) {
    cout << "move("<< n <<"," << start << "," << target <<"," << middle<< ")" << endl;
    move(n-1, start, middle, target);
    cout << "   Moved disk " << n << " from " << start << " to " << target << "." << endl;
    move(n-1, middle, target, start);
  }
}

int main() {
  int arr[] = {1,2,3,4};

  for (const auto& i : arr) {
    cout << endl << "*** n = " << i << endl;
    move(i, "Start", "Target", "Middle");
  }

  return 0;
}
