#include <bits/stdc++.h>
using namespace std;
const int maxn = 310;
char A[maxn], B[maxn], tA[maxn], tB[maxn];
int n;
void f(char input[], char output[], int &num)
{
    int size = strlen(input);
    int dot = size;
    for (int i = 0; i < size; ++i)
    {
        if (input[i] == '.')
        {
            dot = i;
            break;
        }
    }
    int idx = 0; //第一个有效数字
    while (input[idx] == '0' || input[idx] == '.')
    {
        idx++;
    }

    num = dot - idx;
    if (dot < idx) //有效数字在小数点后面
        num++;
    if (idx == size) //0
        num = 0;
    for (int i = 0; i < n; ++i)
    {
        if (input[idx] == '.')
            idx++;
        if (idx < size)
            output[i] = input[idx++];
        else
            output[i] = '0';
    }
}
int main()
{

    scanf("%d", &n);
    scanf("%s %s", &tA, &tB);
    int a, b;
    f(tA, A, a);
    f(tB, B, b);
    if (strcmp(A, B) == 0 && a == b)
    {
        printf("YES 0.%s*10^%d", A, a);
    }
    else
    {
        printf("NO 0.%s*10^%d 0.%s*10^%d", A, a, B, b);
    }
}