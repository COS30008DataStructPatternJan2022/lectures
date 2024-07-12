#include <utility>

using namespace std;

/* Defines a LinkedList, whose data of the type DataType */
struct SinglyLinkedList {
  // DataType: a generic data type, to be specified by the client
  DataType fData;
  SinglyLinkedList* fNext;

  // constructor: l-value aData
  SinglyLinkedList(const DataType& aData, SinglyLinkedList* aNext = nullptr): 
    fData(aData), 
    fNext(aNext) {}
  
  // constructor: r-value aData
  SinglyLinkedList(const DataType&& aData, SinglyLinkedList* aNext = nullptr): 
    fData(std::move(aData)), 
    fNext(aNext) {}
};