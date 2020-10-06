#include <bits/stdc++.h>
using namespace std;
double origin;
double months;
double m_m;
bool getS(double x)
{
    return (pow(1.0 / (1.0 + x), months) >= 1 - origin / m_m * x);
}
int main()
{

    cin >> origin >> m_m >> months;
    double low = 0, high = 10;
    while (high - low >= 1e-5)
    {
        double mid = (low + high) / 2;
        if (getS(mid))
            high = mid;
        else
            low = mid;
    }
    cout << fixed << setprecision(1) << low * 100;
}