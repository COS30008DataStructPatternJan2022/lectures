// forward declaration of classB, without body
class ClassB;

class ClassA {
  public:
    ClassA();
    // mutual-reference: use ClassB
    void methodA(const ClassB& b) const;
    void toString() const;
};