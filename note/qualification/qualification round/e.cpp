#include <bits/stdc++.h>

template <class T>
bool Enlarge(T &a, T const &b)
{
    return a < b ? a = b, 1 : 0;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int cnt;
    std::cin >> cnt;
    std::cin.get();
    std::map<std::string, std::map<char, int>> no;
    std::map<std::string, int> pen;
    std::map<std::string, std::set<char>> solved;
    for (std::string ins; std::getline(std::cin, ins), ins != "GAME OVER!";)
    {
        std::istringstream ss(ins);
        std::string t;
        ss >> t;
        int minu = std::stoi(t.substr(0, 2)) * 60 + std::stoi(t.substr(3, 2));
        char prob;
        ss >> prob;
        std::string status;
        static std::set<std::string> results{"Accepted", "Wrong Answer", "Time Limit Exceeded", "Compile Error", "Memory Limit Exceeded", "Output Limit Exceeded", "Runtime Error", "Presentation Error"};
        while (!results.count(status))
        {
            ss >> t;
            if (status != "")
                status += ' ';
            status += t;
        }
        std::string name;
        while (ss >> t)
        {
            if (name != "")
                name += ' ';
            name += t;
        }
        if (status != "Compile Error")
        {
            if (solved[name].count(prob))
                continue;
            if (status == "Accepted")
            {
                pen[name] += minu + no[name][prob] * 20;
                solved[name].insert(prob);
            }
            else
                no[name][prob]++;
        }
    }
    std::vector<std::string> rank;
    for (auto &p : no)
        rank.push_back(p.first);
    std::sort(rank.begin(), rank.end(), [&](auto const &a, auto const &b) -> bool {
        if (solved[a].size() == solved[b].size())
        {
            return pen[a] == pen[b] ? a < b : pen[a] < pen[b];
        }
        else
            return solved[a].size() > solved[b].size();
    });
    int mxlen = 0;
    for (auto &name : rank)
        Enlarge(mxlen, (int)name.length());
    std::string prev;
    int place = 0, lnum = 0;
    std::cout << "Rank"
              << "  " << std::left << std::setw(mxlen) << "Who"
              << "  "
              << "Solved"
              << "  "
              << "Penalty";
    for (int c = 0; c < cnt; ++c)
        std::cout << "  " << std::right << std::setw(3) << (char)('A' + c);
    std::cout << '\n';
    for (auto const &name : rank)
    {
        ++lnum;
        if (prev == "" || !(solved[name].size() == solved[prev].size() && pen[name] == pen[prev]))
            place = lnum;
        prev = name;
        std::cout << std::setw(4) << place
                  << "  " << std::setw(mxlen) << name
                  << "  " << std::setw(6) << solved[name].size()
                  << "  " << std::setw(7) << pen[name];
        for (int c = 0; c < cnt; ++c)
        {
            std::string code;
            if (solved[name].count(c + 'A') || no[name].count(c + 'A'))
                code = (solved[name].count(c + 'A') ? '+' : '-') + (no[name][c + 'A'] ? std::to_string(no[name][c + 'A']) : "");
            std::cout << "  " << std::setw(3) << code;
        }
        std::cout << '\n';
    }
    return 0;
}
