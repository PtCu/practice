#include <bits/stdc++.h>
std::map<int, int> vec;
int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, a, b;
    std::cin >> n >> a >> b;
    for (int i = 0; i < a; i++)
    {
        int index, val;
        std::cin >> index >> val;
        vec.insert(std::pair<int, int>(index, val));
    }
    long long ans = 0;
    for (int i = 0; i < b; i++)
    {
        int index, val;
        std::cin >> index >> val;
        if (vec.count(index))
            ans += vec[index] * val;
    }
    std::cout << ans << std::endl;
}