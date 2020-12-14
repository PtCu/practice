#include <bits/stdc++.h>
using namespace std;
unordered_map<string, set<string>> M = {
    {"123", {"123","234","543","5464","1231"}}};
int main()
{
   cout<< M["123"].count("123");
}