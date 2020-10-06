#include <bits/stdc++.h>
using namespace std;
#define XE 1e-3
double a, b, c, d;
double f(double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}
double df(double x)
{
    return 3 * a * x * x + 2 * b * x + c;
}
void binary()
{
    cin >> a >> b >> c >> d;
    for (int i = -100; i < 100; i++)
    {
        double l = i;
        double r = i + 1;
        double fx1 = f(l);
        double fx2 = f(r);
        if (fx1 == 0)
        {
            cout << fixed << setprecision(2) << l << " ";
        }
        // if (fx2 == 0)
        // {
        //     cout << r << " ";
        // }
        if (fx1 * fx2 < 0)
        {
            while (r - l > XE)
            {
                double m = (l + r) / 2;
                double fm = f(m);
                if (fx1 * fm < 0)
                {
                    r = m;
                }
                else if (fm * fx2 < 0)
                {
                    l = m;
                }
            }
            cout << fixed << setprecision(2) << r << " ";
        }
    }
}
double iter(double l, double r)
{
    double x0 = (l + r) / 2;
    double x=l;
    while (abs(x0 - x) > XE)
    {
        x = x0 - f(x0) / df(x0);
        swap(x,x0);
    }
    return x;
}
void Newton()
{
    cin >> a >> b >> c >> d;
    double x1 = (-b - sqrt(b * b - 3 * a * c)) / (3 * a);
    double x2 = (-b + sqrt(b * b - 3 * a * c)) / (3 * a);
    cout<< fixed << setprecision(2)<<iter(-100,x1)<<" ";
    cout<< fixed << setprecision(2)<<iter(x1,x2)<<" ";
    cout<< fixed << setprecision(2)<<iter(x2,100);
}
int main()
{
    Newton();
}