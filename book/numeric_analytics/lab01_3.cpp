#include <bits/stdc++.h>
using namespace std;
constexpr double pi = 3.1415926;
#define CASE2
#ifdef CASE1
constexpr double gamma = 3.14159265358979 / 2;
constexpr double x1 = 4, x2 = 0, y2 = 4;
const double L1 = 2, L2 = sqrt(2), L3 = sqrt(2);
const double p1 = sqrt(5), p2 = sqrt(5), p3 = sqrt(5);

#else
constexpr double gamma = 3.14159265358979 / 4;
constexpr double x1 = 5, x2 = 0, y2 = 6;
const double L1 = 3 * sqrt(2), L2 = sqrt(2), L3 = sqrt(2);
const double p1 = 5, p2 = 5, p3 = 3;
#endif

double f(double theta)
{
    double A2 = L3 * cos(theta) - x1;
    double B2 = L3 * sin(theta);
    double A3 = L2 * cos(gamma + theta) - x2;
    double B3 = L2 * sin(gamma + theta) - y2;

    double D = 2 * (A2 * B3 - B2 * A3);

    double N1 = B3 * (p2 * p2 - p1 * p1 - A2 * A2 - B2 * B2) - B2 * (p3 * p3 - p1 * p1 - A3 * A3 - B3 * B3);
    double N2 = -A3 * (p2 * p2 - p1 * p1 - A2 * A2 - B2 * B2) + A2 * (p3 * p3 - p1 * p1 - A3 * A3 - B3 * B3);

    return N1 * N1 + N2 * N2 - p1 * p1 * D * D;
}

int main()
{

    double x0 = -pi, f0 = f(x0);
    double x1 = pi, f1 = f(x1);
    double x2;
    int i;
    for ( i = 0;; i++)
    {
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        if (abs(f(x1)) < 1e-5)
            break;
        x0 = x1;
        x1 = x2;
        
    }
        
    cout << x2<<endl<<i<<endl;
}
