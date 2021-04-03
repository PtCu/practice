#include <string.h>
#include <stdlib.h>
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
        (0 > t || P[j] == P[t]) ? N[++j] = ++t : t = N[t]; //匹配：next[j+1]=next[j]+1、失配：找next[[next[j]]]
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

int *buildBC(char *P)
{
    int *bc = new int[256]; //BC表，与字符表等长
    for (size_t j = 0; j < 256; j++)
        bc[j] = -1;                               //初始化：首先假设所有字符均未在P中出现
    for (size_t m = strlen(P), j = 0; j < m; j++) //自左向右扫描模式串P
        bc[P[j]] = j;                             //将字符P[j]的BC项更新为j（单调递增）——画家算法
    return bc;
}

int match_bc(char *P, char *T)
{
    int *bc = buildBC(P);        //预处理
    size_t n = strlen(T), i = 0; //文本串长度、与模式串首字符的对齐位置
    size_t m = strlen(P);        //模式串长度
    while (n >= i + m)
    {                            //在到达最右端前，不断右移模式串（可能不止一个字符）
        int j = m - 1;           //从模式串最末尾的字符开始
        while (P[j] == T[i + j]) //自右向左比对
            if (0 > --j)
                break;
        if (j < 0)                           //若极大匹配后缀 == 整个模式串，则说明已经完全匹配，故
            break;                           //返回匹配位置
        else                                 //否则，根据BC表
            i += __max(1, j - bc[T[i + j]]); //相应地移动模式串，使得T[i+j]与P[bc[T[i+j]]]对齐
    }
    delete[] bc; //销毁BC表
    return i;
}

int *buildGS(char *P)
{                         //构造好后缀位移量表：O(m)
    int *ss = buildSS(P); //Suffix Size table
    size_t m = strlen(P);
    int *gs = new int[m]; //Good Suffix shift table
    for (size_t j = 0; j < m; j++)
        gs[j] = m;                                   //初始化
    for (size_t i = 0, j = m - 1; j < UINT_MAX; j--) //逆向逐一扫描各字符P[j]
        if (j + 1 == ss[j])                          //若P[0, j] = P[m - j - 1, m)，则
            while (i < m - j - 1)                    //对于P[m - j - 1]左侧的每个字符P[i]而言（二重循环？）
                gs[i++] = m - j - 1;                 //m - j - 1都是gs[i]的一种选择
    for (size_t j = 0; j < m - 1; j++)               //画家算法：正向扫描P[]各字符，gs[j]不断递减，直至最小
        gs[m - ss[j] - 1] = m - j - 1;               //m - j - 1必是其gs[m - ss[j] - 1]值的一种选择

    delete[] ss;
    return gs;
}

int match_bc_gs(char *P, char *T)
{
    int *bc = buildBC(P);
    int *gs = buildGS(P); //构造BC表和GS表
    size_t i = 0;         //模式串相对于文本串的起始位置（初始时与文本串左对齐）
    while (strlen(T) >= i + strlen(P))
    {                            //不断右移（距离可能不止一个字符）模式串
        int j = strlen(P) - 1;   //从模式串最末尾的字符开始
        while (P[j] == T[i + j]) //自右向左比对
            if (0 > --j)
                break;                           /*DSA*/
        if (0 > j)                               //若极大匹配后缀 == 整个模式串（说明已经完全匹配）
            break;                               //返回匹配位置
        else                                     //否则，适当地移动模式串
            i += __max(gs[j], j - bc[T[i + j]]); //位移量根据BC表和GS表选择大者
    }
    delete[] gs;
    delete[] bc; //销毁GS表和BC表
    return i;
}
