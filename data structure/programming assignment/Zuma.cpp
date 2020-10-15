#include <cstdio>
#include <cstring>
#include <iostream>
const int MAX = 20005;
char s[MAX];
char temp[MAX];
int size = 0;
int pos;

const int SZ = 1 << 20; //快速io
struct fastio
{
    char inbuf[SZ];
    char outbuf[SZ];
    fastio()
    {
        setvbuf(stdin, inbuf, _IOFBF, SZ);
        setvbuf(stdout, outbuf, _IOFBF, SZ);
    }
} io;
bool isFinished(int p)
{
    int head = p;
    int tail = p;
    char e = s[p];
    while (e == s[head] && head)
    {
        head--;
    }
    if (head || s[head] != e)
    {
        head++;
    }
    while (e == s[tail] && tail < size)
    {
        tail++;
    } //tail最后多移动了一位，正好减去
    if (tail - head > 2)
    {
        strcpy(temp, s + tail);
        strcpy(s + head, temp);
        size = size + head - tail;
        pos = head;
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    std::cin.getline(s, MAX);
    while (s[size] >= 'A' && s[size] <= 'Z')
        size++;
    int n;
    char e;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d %c", &pos, &e);
        strcpy(temp, s + pos);
        strcpy(s + pos + 1, temp);
        s[pos] = e;
        size++;
        bool done = false;
        while (!done && size)
        {
            done = isFinished(pos);
        };
        if (size)
            puts(s);
        else
            puts("-");
    }
    return 0;
}