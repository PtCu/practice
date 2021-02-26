#include <bits/stdc++.h>
using namespace std;
struct Node
{
    string name;
    string ID;
    int grade;
    Node(const string &_n, const string &_i, int _grade) : name(_n), ID(_i), grade(_grade) {}
    // //大顶堆
    // bool operator<(const Node &e)
    // {
    //     return grade < e.grade;
    // }
};
struct cmp1
{
    //大顶堆
    bool operator()(const Node &a, const Node &b)
    {
        return a.grade < b.grade;
    }
};

struct cmp2
{
    //小顶堆
    bool operator()(const Node &a, const Node &b)
    {
        return a.grade > b.grade;
    }
};

priority_queue<Node, vector<Node>, cmp1> Fq;
priority_queue<Node, vector<Node>, cmp2> Mq;
int main()
{
    int n;
    cin >> n;
    string name, ID;
    int grade;
    bool isM;
    char c;
    for (int i = 0; i < n; ++i)
    {
        cin >> name >> c >> ID >> grade;
        c == 'M' ? Mq.push(Node{name, ID, grade}) : Fq.push(Node{name, ID, grade});
    }
    bool flag = true;
    if (!Fq.empty())
    {

        cout << Fq.top().name << " " << Fq.top().ID << endl;
    }
    else
    {
        flag = false;
        cout << "Absent" << endl;
    }
    if (!Mq.empty())
    {

        cout << Mq.top().name << " " << Mq.top().ID << endl;
    }
    else
    {
        flag = false;
        cout << "Absent" << endl;
    }
    if (flag)
    {
        cout << Fq.top().grade - Mq.top().grade << endl;
    }
    else
    {
        cout << "NA" << endl;
    }
}