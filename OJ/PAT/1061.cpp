#include <bits/stdc++.h>
using namespace std;
string s1, s2, s3, s4;

string days[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
    cin >> s1 >> s2 >> s3 >> s4;
    int Fir;
    int for_sec;
    for (int i = 0; i < min(s1.size(), s2.size()); ++i)
    {
        if (s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G')
        {
            for_sec = i;
            cout << days[s1[i] - 'A'] << " ";
            break;
        }
    }

    for (int i = for_sec + 1; i < min(s1.size(), s2.size()); ++i)
    {
        if (s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'N')
        {
            printf("%d:", s1[i] - 'A' + 10);
            break;
        }
        else if (s1[i] == s2[i] && s1[i] >= '0' && s1[i] <= '9')
        {
            printf("%02d:", s1[i] - '0');
            break;
        }
    }

    for (int i = 0; i < min(s3.size(), s4.size()); ++i)
    {
        if (s3[i] == s4[i] && ((s3[i] >= 'a' && s4[i] <= 'z') || (s3[i] >= 'A' && s4[i] <= 'Z')))
        {
            printf("%02d", i);
            break;
        }
    }
}