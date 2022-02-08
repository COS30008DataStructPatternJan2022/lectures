#include <string>

using namespace std;

class IntArrayIndexer {
  private: 
    const int* fArrayElements;
    const int fLength;

  public:
    /*
     * constructor
     * pre:
     *  aArray.length = aLength
     * post:
     *  initialise this as an index for aArray with length aLength
     */
    IntArrayIndexer(const int aArray[], const int aLength): 
      fArrayElements(aArray), fLength(aLength) {};

    /*
     * operator: this[aKey] 
     * post
     *  result = e in fArrayElements that is mapped to aKey
     */
    const int& operator[] (const string& aKey) const;

};