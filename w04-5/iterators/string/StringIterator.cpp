#include <string>
#include <iostream>

using namespace std;

/* Ref: Lippman et al, Section 3.4 */

/* @modifies: s */
void convertFirstChar(string & s) {
  if (s.begin() != s.end()) { // make sure s is not empty
    auto it = s.begin(); // it denotes the first character in s
    *it = toupper(*it);  // make that character uppercase
  }
}

/* @modifies: s */
void convertFirstWord(string & s) {
  for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it) {
    *it = toupper(*it);  // make current character uppercase
  }
}

int main() {
  string s("some string");
  cout << "String: \"" << s << "\"" << endl;
  cout << "First, last letters: " << s[0] << ", " << s[s.length()-1] << endl;

  // converts s's first to upper case
  convertFirstChar(s);

  cout << "AFTER convertFirstChar: \"" << s << "\"" << endl;
  cout << "First letter: " << s[0] << endl;

  // converts string
  convertFirstWord(s);
  cout << "AFTER convertFirstWord: \"" << s << "\"" << endl;

}