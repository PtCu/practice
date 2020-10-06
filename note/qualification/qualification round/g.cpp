#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::string s;
    std::cin >> s;
    std::map<char, int> ord;
    for (int i = 0; i < 26; ++i)
    {
        char c;
        std::cin >> c;
        ord[c] = i;
    }
    std::sort(s.begin(), s.end(), [&](char a, char b) -> bool {
        return ord[a] < ord[b];
    });
    std::cout << s << '\n';
    return 0;
}
