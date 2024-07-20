#include <iostream>

using namespace std;

class Foo
{

public:
    virtual void buz1();
    virtual void buz2();
    virtual ~Foo() = 0;
};

void Foo::buz1()
{
    cout << "Buz1 Virtual\n";
}
void Foo::buz2()
{
    cout << "Buz2 Solid\n";
}
Foo::~Foo()
{
}
class Bar : public Foo
{
public:
    Bar()
    {
        cout << "Bar Desctructor called";
    }
};

int main()
{
    Bar foo;
    foo.buz2();
}