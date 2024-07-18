#include <iostream>

using namespace std;

class Foo
{

public:
    virtual void buz1();
    virtual void buz2();
};

void Foo::buz1()
{
    cout << "Buz1 Virtual\n";
}
void Foo::buz2()
{
    cout << "Buz2 Virtual\n";
}

class Bar : public Foo
{
};

int main()
{
    Bar foo;
    foo.buz1();
}