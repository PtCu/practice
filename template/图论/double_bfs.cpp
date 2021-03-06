//走迷宫
//https://blog.csdn.net/weixin_43501684/article/details/90147421
//bfs是单调递增的，第一个找到的一定是最短的路径
#include <iostream>
#include <queue>
#define P pair<int, int>
using namespace std;
//记录下当前状态, 从前往后搜索值为1，从后往前搜索值为2，如果某状态下，当前节点和准备扩展节点的状态相加为3，说明相遇
queue<P> q1, q2;
int r, c, ans, dis[45][45], vst[45][45];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char m[45][45];

void dbfs()
{
	bool flag;
	q1.push(P(1, 1)), dis[1][1] = 1, vst[1][1] = 1; //从前搜
	q2.push(P(r, c)), dis[r][c] = 1, vst[r][c] = 2; //从后搜
	while (!q1.empty() && !q2.empty())
	{
		int x0, y0;
		if (q1.size() > q2.size())
		{ //每次扩展搜索树小的队列 flag=1扩展前搜的队列，flag=0扩展后搜的队列
			x0 = q2.front().first, y0 = q2.front().second;
			q2.pop();
			flag = 0;
		}
		else
		{
			x0 = q1.front().first, y0 = q1.front().second;
			q1.pop();
			flag = 1;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = x0 + dx[i];
			int ny = y0 + dy[i];
			if (nx >= 1 && nx <= r && ny >= 1 && ny <= c && m[nx][ny] == '.')
			{
				if (!dis[nx][ny])
				{
					dis[nx][ny] = dis[x0][y0] + 1;
					vst[nx][ny] = vst[x0][y0];
					if (flag)
						q1.push(P(nx, ny));
					else
						q2.push(P(nx, ny));
				}
				else
				{
					if (vst[x0][y0] + vst[nx][ny] == 3)
					{ //相遇
						ans = dis[nx][ny] + dis[x0][y0];
						return;
					}
				}
			}
		}
	}
}

int main()
{
	cin >> r >> c;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			cin >> m[i][j];
	dbfs();
	cout << ans << "\n";
	return 0;
}

// void TBFS()
// {
//        if(s1.state==s2.state)//起点终点相同时要特判
//        {
//               //do something
//               found=true;
//               return;
//        }
//        bool found=false;
//        memset(visited,0,sizeof(visited));  // 判重数组
//        while(!Q1.empty())  Q1.pop();   // 正向队列
//        while(!Q2.empty())  Q2.pop();  // 反向队列
//        //======正向扩展的状态标记为1，反向扩展标记为2
//        visited[s1.state]=1;   // 初始状态标记为1
//        visited[s2.state]=2;   // 结束状态标记为2
//        Q1.push(s1);  // 初始状态入正向队列
//        Q2.push(s2);  // 结束状态入反向队列
//        while(!Q1.empty() || !Q2.empty())
//        {
//               if(!Q1.empty())
//                      BFS_expand(Q1,true);  // 在正向队列中搜索
//               if(found)  // 搜索结束
//                      return ;
//               if(!Q2.empty())
//                      BFS_expand(Q2,false);  // 在反向队列中搜索
//               if(found) // 搜索结束
//                      return ;
//        }
// }
// void BFS_expand(queue<Status> &Q,bool flag)
// {
//        s=Q.front();  // 从队列中得到头结点s
//       Q.pop()
//       for( 每个s 的子节点 t )
//      {
//              t.state=Gethash(t.temp)  // 获取子节点的状态
//              if(flag)   // 在正向队列中判断
//              {
//                       if (visited[t.state]!=1）// 没在正向队列出现过
//                     ｛
//                            if(visited[t.state]==2)  // 该状态在反向队列中出现过
//                           {
//                                  各种操作；
//                                  found=true；
//                                  return;
//                            }
//                             visited[t.state]=1;   // 标记为在在正向队列中
//                             Q.push(t);  // 入队
//                        ｝
//              ｝
//              else    // 在正向队列中判断
//              {
//                       if (visited[t.state]!=2） // 没在反向队列出现过
//                     ｛
//                            if(visited[t.state]==1)  // 该状态在正向向队列中出现过
//                            {
//                                   各种操作；
//                                   found=true；
//                                   return;
//                             }
//                              visited[t.state]=2;  // 标记为在反向队列中
//                              Q.push(t);  // 入队
//                        ｝
//              ｝
// }