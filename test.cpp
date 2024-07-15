#include <iostream>
class Foo
{
private:
    int a = 20;

public:
    int b;
    virtual int buz() = 0;

protected:
    int c = 40;
};

class Bar : public Foo
{
public:
    void printA()
    {
        std::cout << c << std::endl;
    }
    int buz();
};

int Bar::buz()
{
    return 0;
}

main()
{
    Bar bar;
    bar.printA();
}