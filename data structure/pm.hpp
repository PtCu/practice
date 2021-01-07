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

int *buildNext(char *P)
{
    size_t m = strlen(P), j = 0; //“主”串指针
    int *N = new int[m];
    int t = N[0] = -1; //模式串指针
    while (j < m - 1)
    {
        (0 > t || P[j] == P[t]) ? N[++j] = ++t : t = N[t]; //匹配、失配
    }
    return N;
}
int *buildNext_improved(char *P)
{
    size_t m = strlen(P), j = 0;
    int *N = new int[m];
    int t = N[0] = -1;
    while (j < m - 1)
    {
        if (0 > t || P[j] == P[t])
        { //匹配
            N[j] = (P[++j] != P[++t] ? t : N[t]);
        }
        t = N[t];
        /* code */
    }
    return N;
}
int match_kmp(char *P, char *T)
{                                  //KMP算法
    int *next = buildNext(P);      //构造next表
    int n = (int)strlen(T), i = 0; //文本串指针
    int m = (int)strlen(P), j = 0; //模式串指针
    while (j < m && i < n)         //自左向右逐个比对字符
        if (0 > j || T[i] == P[j]) //若匹配，或P已移出最左侧（两个判断的次序不可交换）
        {
            i++;
            j++;
        }                //则转到下一字符
        else             //否则
            j = next[j]; //模式串右移（注意：文本串不用回退）

    delete[] next; //释放next表
    return i - j;
}

int* buildBC(char* P){
    int *bc = new int[256];
    for (size_t j = 0; i < 256;++j)
        bc[j] = -1;
    for (size_t m = strlen(P), j = 0; j < m;j++)
        bc[P[j]] = j;
    return bc;
}

int match_bc(char*P,char* T){
    int *bc = buildBC(P);
}