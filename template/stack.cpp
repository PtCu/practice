//栈混洗
#include <bits/stdc++.h>
using namespace std;
bool isValid(stack<int> &A, stack<int> &B)
{
    stack<int> S,temp;
    while (!B.empty())
    {
        temp.push(B.top());
        B.pop();
    }
    while (!A.empty())
    {
        S.push(A.top());
        A.pop();
        if (temp.top() == S.top()) {
			temp.pop();
			S.pop();
			while (!S.empty()) {
				if (temp.top() == S.top()) {
					temp.pop();
					S.pop();
				}
				else return false;
			}
		}
    }
    return S.empty();
    

}
int main()
{
    int n, q,x;
    cin >> q;
    while (q--)
    {
        stack<int> A, B;
        cin >> n;
        for (size_t i = 0; i < n;++i){
            cin>>x;
            A.push(x);
        }
        for (size_t i = 0; i < n;++i){
            cin >> x;
            B.push(x);
        }
        isValid(A, B) ? cout << "Yes" << endl : cout << "No" << endl;
        
    }
}