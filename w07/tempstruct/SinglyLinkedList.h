#pragma(once)

/* DataType is a type parameter, representing data */
template <typename DataType>
struct SinglyLinkedList {
  DataType fData;
  SinglyLinkedList* fNext;

  SinglyLinkedList(const DataType& aData, SinglyLinkedList* aNext = nullptr): 
    fData(aData), 
    fNext(aNext) {}
  
  SinglyLinkedList(const DataType&& aData, SinglyLinkedList* aNext = nullptr): 
    fData(std::move(aData)), 
    fNext(aNext) {}
};