#include <bits/stdc++.h>
using namespace std;
#define N 13
int arr[3][2*N];
int total=0;

int ans[N];
void print(int n)
{
    if(total>3)
    return;
   
        for (int j = 0; j < n; j++)
                cout << ans[j] << " ";
        
    
    cout << endl;
}
void findQueen(int row, int n)
{
    if (row == n)
    {
        //打印
        total+=1;
        print(n);
        return;
    }
    for (int col = 1; col <= n; col++)
    {
        if (!(arr[0][col] ||arr[1][col+row]||arr[2][n+row-col]))//点、两个对角线
        {
            ans[row]=col;
            arr[0][col] = 1; arr[1][col+row]=1;arr[2][n+row-col]=1; //标记为已占用
            findQueen(row + 1, n);
            arr[0][col] = 0; arr[1][col+row]=0;arr[2][n+row-col]=0;//准备移到下一列，标记为未占用
        }
        
    }
}
// bool isValid(int k, int j)
// {
    // for(int i=0;i<8;i++){//检查行列冲突
    //      if(arr[i][j]==1){
    //             return false;
    //      }
    // }
    // for(int i=k-1,m=j-1; i>=0 && m>=0; i--,m--){//检查左对角线
    //     if(arr[i][m]==1){
    //             return false;
    //     }
    // }
    // for(int i=k-1,m=j+1; i>=0 && m<=7; i--,m++){//检查右对角线
    //     if(arr[i][m]==1){
    //             return false;
    //     }
    // }
    // return true;
// }
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    findQueen(0, n);
    cout<<total;
    return 0;
}
