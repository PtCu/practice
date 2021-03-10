#include <bits/stdc++.h>
using namespace std;
char str1[35];
char str2[35];
int main()
{
    int n;
    cin >> n;
    double a;
    double sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", &str1);
        sscanf(str1, "%lf", &a);
        sprintf(str2, "%.2f", a);
        bool flag = true;
        for (int j = 0; j < strlen(str1); ++j)
        {
            if (str1[j] != str2[j])
            {
                flag = false;
                break;
            }
        }
        if (a > 1000 || a < -1000)
            flag = false;
        if (flag)
        {
            sum += a;
            cnt++;
        }
        else
        {
            printf("ERROR: %s is not a legal number\n", str1);
        }
    }
    if (cnt > 1)
        cout << "The average of " << cnt << " numbers is " << setiosflags(ios::fixed) << setprecision(2) << sum/cnt << endl;
    else if (cnt == 1)
        cout << "The average of " << cnt << " number is " << setiosflags(ios::fixed) << setprecision(2) << sum << endl;
    else
        cout << "The average of 0 numbers is Undefined";
}