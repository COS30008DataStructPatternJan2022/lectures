#include <iostream>

class Foo
{
    public:
        Foo()
        {
            this->value = 0;
        }

        Foo get_copy()
        {
            return *this;
        }

        bool get_copy2()
        {
            Foo foo2 = *this;
            increment();
            // return true (1): so foo2 is a copy of this
            return foo2.value != value; 
        }

        Foo& get_copy_as_reference()
        {
            return *this;
        }

        Foo* get_pointer()
        {
            return this;
        }

        void increment()
        {
            this->value++;
        }

        void print_value()
        {
            std::cout << this->value << std::endl;
        }

    private:
        int value;
};

int main()
{
    std::cout << "Foo object" << std::endl;
    Foo foo;
    foo.increment();
    foo.print_value();

    std::cout << "Foo object: cloned (accessed by '*this')" << std::endl;
    Foo foo2 = foo.get_copy();
    foo2.increment();
    std::cout << "...foo:" << std::endl;
    foo.print_value();
    std::cout << "...foo2:" << std::endl;
    foo2.print_value();

    std::cout << "Foo object: accessed by reference to '*this'" << std::endl;
    foo.get_copy_as_reference().increment();
    std::cout << "...foo:" << std::endl;
    foo.print_value();
    std::cout << "...foo2:" << std::endl;
    foo2.print_value();

    std::cout << "Foo object: accessed by pointer 'this'" << std::endl;
    foo.get_pointer()->increment();
    std::cout << "...foo:" << std::endl;
    foo.print_value();
    std::cout << "...foo2:" << std::endl;
    foo2.print_value();
    
    bool copied = foo.get_copy2();
    std::cout << "...copied: " << copied << std::endl;


    return 0;
}