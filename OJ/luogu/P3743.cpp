#include <bits/stdc++.h>
using namespace std;
int n;
double p;
struct Device
{
    double a, b;
    Device() {}
    Device(int _a, int _b) : a(_a), b(_b) {}
};
vector<Device> sources;

bool isMore(double x) //由于能量可任意分配，所以考虑x时间内的总量即可
{
    double q = p * x; //充电器最多提供的能量
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sources[i].a * x <= sources[i].b)
            continue;
        sum += (sources[i].a * x - sources[i].b);   //所需要的能量
    }
    return q > sum;
}
int main()
{
    cin >> n >> p;
    double a, b;
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        sum += a;
        sources.push_back(Device(a, b));
    }
    if (p > sum)
    {
        cout << -1.000000 << endl;
        return 0;
    }
    
        double low = 0, high = 1e10+100;
        while (high - low > 1e-6)
        {
            double mid = (low + high) / 2;
            if (isMore(mid))
                low = mid;
            else
                high = mid;
        }
        cout << low<<endl;
        return 0;
}