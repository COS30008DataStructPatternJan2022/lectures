// forward declaration of classA, without body
class ClassA;

class ClassB {
  public:
    ClassB();
    // mutual-reference: use ClassA
    void methodB(const ClassA& a) const;
};