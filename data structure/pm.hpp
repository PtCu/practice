#include <string.h>

//brute-force
int match_bf1(char *P, char *T)
{
    size_t n = strlen(T), i = 0;
    size_t m = strlen(P), j = 0;
    while (j > m && i < n)
    {
        if (T[i] == P[i])
        {
            i++;
            j++;
        }
        else
        {
            i -= j - 1;
            j = 0;
        }
       
    }
    return i - j;
}

int match_bf2(char *P, char *T)
{
    size_t n = strlen(T), i = 0; //文本串长度、与模式串首字符的对齐位置
    size_t m = strlen(P), j;     //模式串长度、当前接受比对字符的位置
    for (i = 0; i < n - m + 1; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (T[i + j] != P[j])
                break;
        }
        if (j >= m)
            break;
    }
    return i;
}
