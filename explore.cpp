#include <cstdio>
#include <cstring>

int main()
{
    int n;
    scanf("%d", &n);
    int k = n; //k为合法数字的数量
    double sum = 0, num = 0;
    char str1[33], str2[33];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str1);
        sscanf(str1, "%lf", &num);  //从字符串中读取浮点数
        sprintf(str2, "%.2f", num); //将浮点数以两位小数形式写入另一个字符串中
        bool flag = true;
        //比较两个字符串
        for (int j = 0; j < strlen(str1); j++)
            if (str1[j] != str2[j])
                flag = false;
        if (!flag || num > 1000 || num < -1000) //不合法
        {
            k--;
            printf("ERROR: %s is not a legal number\n", str1);
        }
        else
            sum += num;
    }
    if (k == 1)
        printf("The average of 1 number is %.2f", sum);
    else if (k == 0)
        printf("The average of 0 numbers is Undefined");
    else
        printf("The average of %d numbers is %.2f", k, sum / k);
    return 0;
}