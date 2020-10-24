#include "DSA/Stack.hpp"
struct Queen
{
    int x, y; //皇后在棋盘上的位置坐标
    Queen(int xx = 0, int yy = 0) : x(xx), y(yy){};
    bool operator==(const Queen &q) const
    {
        return (x == q.x) || (y == q.y) || (x + y == q.x + q.y) || (x - y == q.x - q.y);
    }
    bool operator!=(const Queen &q) const { return !(*this == q); }
};
int nCheck=0;
int nSolu=0;

void placeQueens(int N)
{                      //N皇后算法（迭代版）
    Stack<Queen> solu; //存放（部分）解的栈
    Queen q(0, 0);     //从原点位置出发
    do
    { //反复试探、回溯
        if (N <= solu.size() || N <= q.y)   //找到一个解或y越界
        { //若已出界，则
            q = solu.pop();//回溯一行，
            q.y++; //并继续试探下一列
        }
        else
        {                                            //否则，试探下一行
            while ((q.y < N) && (0 <= solu.find(q))) //通过与已有皇后的比对。(find()里面包含判等，及判段是否在同一条线上.find成功说明有在同一条线的，不满足要求，要继续查找)
            /*DSA*/                                  //while ((q.y < N) && (solu.find(q))) //（若基于List实现Stack，则find()返回值的语义有所不同）
            {
                q.y++;
                nCheck++;
            } //尝试找到可摆放下一皇后的列
            if (N > q.y)
            {                 //若存在可摆放的列，则
                solu.push(q); //摆上当前皇后，并   push进去的是拷贝
                if (N <= solu.size())
                    nSolu++; //若部分解已成为全局解，则通过全局变量nSolu计数
                q.x++;//转入下一行,
                q.y = 0; //从第0列开始，试探下一皇后
            }
        } /*DSA*/
        
    } while ((0 < q.x) || (q.y < N)); //所有分支均已或穷举或剪枝之后，算法结束
}

int main(){
    placeQueens(8);
}