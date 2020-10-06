#include <iostream>
#include <list>
#include <string>
using namespace std;

// struct Toy
// {
//     string name;
//     bool isOutward;
// };
// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     list<Toy> toys;
//     for (int i = 0; i < n; i++)
//     {
//         Toy toy;
//         cin >> toy.isOutward >> toy.name;
//         toys.push_back(toy);
//     }
//     list<Toy>::iterator iter = toys.begin();
//     for (int i = 0; i < m; i++)
//     {
//         bool isRightward;
//         int stepLength;
//         cin >> isRightward >> stepLength;
//         if (iter->isOutward)
//         {
//             if (isRightward)
//             {
//                 while (stepLength)
//                 {
//                     if (iter == toys.begin())
//                     {
//                         stepLength++;
//                     }
//                     iter--;
//                     stepLength--;
//                 }
//             }
//             else
//             {
//                 while (stepLength)
//                 {
//                     if (iter == toys.end())
//                     {
//                         stepLength++;
//                     }
//                     iter++;
//                     stepLength--;
//                 }
//             }
//         }
//         else
//         {
//             if (isRightward)
//             {
//                 while (stepLength)
//                 {
//                     if (iter == toys.end())
//                     {
//                         stepLength++;
//                     }
//                     iter++;
//                     stepLength--;
//                 }
//             }
//             else
//             {
//                 while (stepLength)
//                 {
//                     if (iter == toys.begin())
//                     {
//                         stepLength++;
//                     }
//                     iter--;
//                     stepLength--;
//                 }
//             }
//         }
//     }
//     cout << iter->name;
//     // for(auto i=toys.begin();i!=toys.end();i++){
//     //     cout<<i->name<<" ";
//     // }
// }
using namespace std;
struct node 
{
    bool isOutward;
    string name;
}a[100000];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].isOutward>>a[i].name;
    }
    int cur=0;
    for(int i=0;i<m;i++)
    {
        int step;
        bool isRight;
        cin>>isRight>>step;
        if(a[cur].isOutward&&isRight)cur=(cur+n-step)%n;
        else if(a[cur].isOutward&&!isRight)cur=(cur+step)%n;
        else if(!a[cur].isOutward&&isRight)cur=(cur+step)%n;
        else if(!a[cur].isOutward&&!isRight)cur=(cur+n-step)%n;
    }
    cout<<a[cur].name<<endl;
    return 0;
}