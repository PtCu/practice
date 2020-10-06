#include "Vector.hpp"
template <typename T>
class Stack : public Vector<T>
{
public: //size(),empty()以及其他开放接口，均可直接沿用
    void push(T const &e) { this->insert(this->size(), e); }
    T pop() { return this->remove(this->size() - 1); }
    T &top() { return (*this)[this->size() - 1]; }
};

//十进制数n到base进制的转换
void convert(Stack<char> &S, int n, int base)
{
    static char digit[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    while (n)
    {
        int remainder = n % base;
        n /= base;
        S.push(digit[remainder]);
    }
}

//表达式括号匹配检查
bool paren(const char exp[], int lo, int hi)
{
    Stack<char> S;
    for (int i = 0; exp[i]; i++)
    {
        switch (exp[i])
        {
        case '(':
        case '[':
        case '{':
            S.push(exp[i]);
            break;
        case ')':
            if ((S.empty()) || ('(' != S.pop()))
                return false;
            break;
        case ']':
            if ((S.empty()) || ('[' != S.pop()))
                return false;
            break;
        case '}':
            if ((S.empty()) || ('}' != S.pop()))
                return false;
            break;

        default:
            break;
        }
    }
    return S.empty();
}
