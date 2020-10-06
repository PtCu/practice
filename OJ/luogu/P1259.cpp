#include <bits/stdc++.h>
using namespace std;
int n;
vector<char> chess;
void printLeft(){
    for(int i=11;i<=chess.size();i++)
    {
        cout<<chess[i];
    }
    cout<<endl;
}
void alone()
{
    cout<<"ooo--***o*";printLeft();
    cout<<"ooo*o**--*";printLeft();
    cout<<"o--*o**oo*";printLeft();
    cout<<"o*o*o*--o*";printLeft();
    cout<<"--o*o*o*o*";printLeft();

}
void printState()
{
    for (int i = 1; i <= chess.size(); i++)
    {
        cout << chess[i];
    }
    cout << endl;
}
void recur(int remain)
{
    if (remain == 4)
    {
        alone();
        return;
    }
    chess[remain * 2 + 1] = chess[remain];
    chess[remain * 2 + 2] = chess[remain + 1];
    chess[remain] = chess[remain + 1] = '-';
    printState();
    chess[remain] = chess[remain + 1] = '*';
    chess[remain * 2] = chess[remain * 2 - 1] = '-';
    printState();
    recur(remain - 1);
}

int main()
{

    cin >> n;
    chess.resize(2 * n + 1);
    for (int i = 1; i <= n; i++)
    {
        chess[i] = 'o';
        chess[i + n] = '*';
    }
    chess.push_back('-');
    chess.push_back('-');
    printState();
    recur(n);
}