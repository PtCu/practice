#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, K, Ds;
//边结构体
struct Edge {
    int a, b, weight;
} e;
vector<Edge> adj[1011];//邻接表数组，存储邻接边

//获取房屋和加油站编号的方法
int getID() {
    char id[5];
    int num = 0;
    scanf("%s", id);
    for(int i = 0; i < strlen(id); i++)
    {
        if(id[i] == 'G')    continue;
        num = num * 10 + id[i] - 48;
    }
    if(id[0] != 'G')    num += M;//将房屋加油站编号用连续的整数表示，先排加油站，后排房屋
    return num;
}

int disto[1011];//disto[i]为起点到顶点i的最短距离
bool marked[1011];//标记顶点是否被添加为最短路径树顶点
void dijkstra(int s) {
    fill(disto, disto + 1011, 0x3fffffff);
    fill(marked, marked + 1011, false);
    disto[s] = 0;
    for(int i = 0; i < N + M; i++)
    {
        int u = -1, minDis = 0x3fffffff;
        for(int j = 1; j <= N + M; j++)//每次添加的都是离起点距离最小的非树顶点
        {
            if(marked[j] == false && disto[j] < minDis)
            {
                u = j;
                minDis = disto[j];
            }
        }
        if(u == -1)    break;//找不到了，说明没有和起点连通的顶点了
        marked[u] = true;//添加到最短路径树
        for(int i = 0; i < adj[u].size(); i++)
        {
            Edge adje = adj[u][i];//得到邻接边
            int next = adje.a;
            if(next == u)    next = adje.b;//得到邻接顶点
            if(disto[u] + adje.weight < disto[next])//松弛操作
                disto[next] = disto[u] + adje.weight;
        }
    }
}

int main() {
    scanf("%d %d %d %d", &N, &M, &K, &Ds);
    for(int i = 0; i < K; i++)
    {
        e.a = getID();
        e.b = getID();
        scanf("%d", &e.weight);
        adj[e.a].push_back(e);
        adj[e.b].push_back(e);
    }
    int ans = -1;//目标加油站的下标
    double ansMin = 0, ansAvg = 0;//目标加油站到任意房屋的最小距离和平均距离
    for(int i = 1; i <= M; i++)//从编号最小的加油站开始
    {
        double curMin = 0, curAvg = 0;//当前加油站到任意房屋的最小距离和平均距离
        dijkstra(i);//对每个加油站执行
        int sum = 0;
        int closest = 0x3fffffff;
        for(int j = M+1; j <= M+N; j++)
        {//对每个房屋，要跳过加油站
            if(disto[j] > Ds)//判断是否超出服务半径
            {
                curMin = -1;
                break;
            }
            sum += disto[j];
            closest = min(closest, disto[j]);
        }
        if(curMin != -1)
        {
            curMin = closest;
            curAvg = 1.0 * sum / N;
            if(curMin > ansMin)
            {
                ansMin = curMin;
                ansAvg = curAvg;
                ans = i;
            }
            else if(curMin == ansMin && curAvg < ansAvg)
            {
                ansAvg = curAvg;
                ans = i;
            }
        }
    }
    if(ans == -1)    printf("No Solution");
    else             printf("G%d\n%.1f %.1f", ans, ansMin, ansAvg);
    return 0;
}