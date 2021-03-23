#include <cstdio>
#include <cstring>

class Foo
{
protected:
    int a;
};
class Bar : public Foo
{
    int get() { return a; }
};
int main()
{
}