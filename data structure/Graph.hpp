#include "Queue.hpp"
#include "Stack.hpp"
//顶点状态
typedef enum
{
   UNDISCOVERED,
   DISCOVERED,
   VISITED
} VStatus; //不加typedef的话Vstatus是变量名。
//不加typedef但把Vstatus放前面的话需要以enum Vstatus的方法声明

typedef enum
{
   UNDETERMINED,
   TREE,
   CROSS,
   FORWARD,
   BACKWARD
} EType; //边在遍历树中所属的类型

template <typename Tv, typename Te> //顶点类型、边类型
class Graph
{ //图Graph模板类
private:
   void reset()
   { //所有顶点、边的辅助信息复位
      for (int i = 0; i < n; i++)
      { //所有顶点的
         status(i) = UNDISCOVERED;
         dTime(i) = fTime(i) = -1; //状态，时间标签
         parent(i) = -1;
         priority(i) = INT_MAX;      //（在遍历树中的）父节点，优先级数
         for (int j = 0; j < n; j++) //所有边的
            if (exists(i, j))
               type(i, j) = UNDETERMINED; //类型
      }
   }
   void BFS(int, int &);                //（连通域）广度优先搜索算法
   void DFS(int, int &);                //（连通域）深度优先搜索算法
   void DFS_I(int, int &);              //迭代
   void BCC(int, int &, Stack<int> &);  //（连通域）基于DFS的双连通分量分解算法
   bool TSort(int, int &, Stack<Tv> *); //（连通域）基于DFS的拓扑排序算法
   template <typename PU>
   void PFS(int, PU); //（连通域）优先级搜索框架
public:               //virtual =0 纯虚函数
   // 顶点
   int n;                                              //顶点总数
   virtual int insert(Tv const &) = 0;                 //插入顶点，返回编号
   virtual Tv remove(int) = 0;                         //删除顶点及其关联边，返回该顶点信息
   virtual Tv &vertex(int) = 0;                        //顶点v的数据（该顶点的确存在）
   virtual int inDegree(int) = 0;                      //顶点v的入度（该顶点的确存在）
   virtual int outDegree(int) = 0;                     //顶点v的出度（该顶点的确存在）
   virtual int firstNbr(int) = 0;                      //顶点v的首个邻接顶点
   virtual int nextNbr(int, int) = 0;                  //顶点v的（相对于顶点j的）下一邻接顶点
   virtual VStatus &status(int) = 0;                   //顶点v的状态
   virtual int &dTime(int) = 0;                        //顶点v的时间标签dTime
   virtual int &fTime(int) = 0;                        //顶点v的时间标签fTime
   virtual int &parent(int) = 0;                       //顶点v在遍历树中的父亲
   virtual int &priority(int) = 0;                     //顶点v在遍历树中的优先级数
                                                       // 边：这里约定，无向边均统一转化为方向互逆的一对有向边，从而将无向图视作有向图的特例
   int e;                                              //边总数
   virtual bool exists(int, int) = 0;                  //边(v, u)是否存在
   virtual void insert(Te const &, int, int, int) = 0; //在顶点v和u之间插入权重为w的边e
   virtual Te remove(int, int) = 0;                    //删除顶点v和u之间的边e，返回该边信息
   virtual EType &status(int, int) = 0;                //边(v, u)的类型
   virtual Te &edge(int, int) = 0;                     //边(v, u)的数据（该边的确存在）
   virtual int &weight(int, int) = 0;                  //边(v, u)的权重
                                                       // 算法
   void bfs(int);                                      //广度优先搜索算法
   void dfs(int);                                      //深度优先搜索算法
   void bcc(int);                                      //基于DFS的双连通分量分解算法
   Stack<Tv> *tSort(int);                              //基于DFS的拓扑排序算法
   void prim(int);                                     //最小支撑树Prim算法
   void dijkstra(int);                                 //最短路径Dijkstra算法
   template <typename PU>
   void pfs(int, PU); //优先级搜索框架
};

template <typename Tv, typename Te>
void Graph<Tv, Te>::bfs(int s)
{
   reset();
   int clock = 0;
   int v = s;
   do
      if (UNDISCOVERED == status(v))
         BFS(v, clock);
   while (s != (v = (++v % n)));
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::BFS(int v, int &clock)
{
   Queue<int> Q;
   status(v) = DISCOVERED;
   Q.enqueue(v);
   while (!Q.empty())
   {
      int v = Q.dequeue();
      dTime(v) = ++clock;
      for (int u = firstNbr(v); - 1 < u; u = nextNbr(v, u))
      {
         if (UNDISCOVERED == status(u))
         {
            status(u) = DISCOVERED;
            Q.enqueue(u);
            status(u, v) = TREE;
            parent(u) = v;
         }
         else
         {
            status(v, u) = CROSS;
         }
      }
      status(u, v) = VISITED;
   }
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::dfs(int s)
{
   reset();
   int clock = 0;
   int v = s;
   do
   {
      if (UNDISCOVERED == status(v))
         DFS(v, clock);
   } while (s != (v = (++v) % n));
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::DFS(int v, int &clock)
{
   dTime(v) = ++clock;
   status(v) = DISCOVERED;
   for (int u = firstNbr(v); - 1 < u; u = nextNbr(v, u))
      switch (status(u))
      {
      case UNDISCOVERED: //u尚未发现，意味着支撑树可在此拓展
         status(v, u) = TREE;
         parent(u) = v;
         DFS(u, clock); //无需加一。进入下一层时会自动加
         break;
      case DISCOVERED:
         status(v, u) = BACKWARD; //u已被发现但尚未访问完毕，应属被后代指向的祖先
         break;
      default: //u已访问完毕，则视承袭关系分为前向边或跨边
         status(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;
         break;
      }
   status(v) = VISITED; //对v的所有节点处理完后标记为visited
   fTime(v) = ++clock;
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::DFS_I(int v, int &clock)
{
   Stack<int> S;
   S.push(v);
   Stack<int> S_; //辅助栈,保证顺序
   while (!S.empty())
   {
      int a = S.pop();
      status(a) = DISCOVERED;
      dTime(a) = ++clock;
      for (int u = firstNbr(a); - 1 < u; u = nextNbr(a, u))
      {
         switch (status(u))
         {
         case UNDISCOVERED:
            status(a, u) = TREE;
            parent(u) = a;
            status(u) = DISCOVERED;
            S_.push(u);
            break;
         case DISCOVERED:
            status(a, u) = BACKWARD;
         default:
            status(a, u) = (dTime(a) < dTime(u)) ? FORWARD : CROSS;
            break;
         }
      }
      while (!S_.empty())
      {
         S.push(S_.pop());
      }

      status(a) = VISITED;
      fTime(a) = ++clock;
   }
}

//基于dfs的拓扑排序
//非DAG无法拓扑排序 DAG:有向无环图
template <typename Tv, typename Te>
Stack<Tv> *Graph<Tv, Te>::tSort(int s)
{
   reset();
   int clock = 0;
   int v = s;
   Stack<Tv> *S = new Stack<Tv>; //用栈记录排序顶点
   do
   {
      if (UNDISCOVERED == status(v))
         if (!TSort(v, clock, S)) //clock并非必需
         {
            while (!S->empty()) //任一连通域非DAG
               S->pop();
            break; //则不必继续计算，故直接返回
         }
   } while (s != (v = (++v % n)));
   return S;
}

//基于DFS的拓扑排序算法（单趟）
template <typename Tv, typename Te>
bool Graph<Tv, Te>::TSort(int v, int &clock, Stack<Tv> *S)
{
   dTime(v) = ++clock;
   status(v) = DISCOVERED; //发现顶点v
   for (int u = firstNbr(v); - 1 < u; u = nextNbr(v, u))
   {
      switch (status(u))
      {
      case UNDISCOVERED:
         parent(u) = v;
         status(v, u) = TREE;
         if (!TSort(v, clock, S)) //从顶点u处出发深入搜索
            return false;         //若u及其后代不能拓扑排序，故返回并报告
         break;
      case DISCOVERED:
         status(v, u) = BACKWARD; //一旦发现后向边（非DAG），则
         return false;            //不必深入，故返回并报告
      default:                    //digraphs only
         status(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;
         break;
      }
   }
   status(v) = VISITED;
   S->push(vertex(v));
   return true;
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::bcc(int s)
{
   reset();
   int clock = 0;
   int v = s;
   Stack<int> S; //栈S用以记录已访问的顶点
   do
   {
      if (UNDISCOVERED == status(v))
      {                    //一旦发现未发现的顶点（新联通分量）
         BCC(v, clock, S); //即从该顶点出发启动一次BCC
         S.pop();          //遍历返回后，弹出栈中最后一个顶点——当前连通域的起点
      }
   } while (s != (v = (++v % n)));
}

//highest connected ancestor HCA最高联通祖先。返回的是最高祖先的标号
//此处利用闲置的ftime。dtime也当作dan'q标号
#define hca(x) (fTime(x))
template <typename Tv, typename Te>
void Graph<Tv, Te>::BCC(int v, int &clock, Stack<int> &S)
{
   hca(v) = dTime(v);
   ++clock;
   status(v) = DISCOVERED;
   S.push(v);
   for (int u = firstNbr(v); - 1 < u; u = nextNbr(v, u))
   {
      switch (status(u))
      {
      case UNDISCOVERED:
         parent(u) = v;
         status(v, u) = TREE;
         BCC(u, clock, S);
         if (hca(u) < dTime(v))             //遍历返回后，若发现u(通过后向边)可指向v的真祖先
            hca(v) = __min(hca(v), hca(u)); //则v亦必如此
         else                               //否则，以v为关节点（u以下即是一个BCC,且其中顶点此时正集中于栈S的顶部）
         {
            printf("BCC rooted at %c:", vertex(v));
            Stack<int> temp;
            do
            {
               temp.push(S.pop());
               print(vertex(temp.top()));
            } while (u != temp.top());
            print(vertex(parent(u)));
            while (!temp.empty())
               S.push(temp.pop());
            while (u != S.pop())
               ; //弹出当前BCC中（除v外）的所有节点，可视需要做进一步处理
            printf("\n");
         }
         break;
      case DISCOVERED:
         status(v, u) = BACKWARD;
         if (u != parent(v))
            hca(v) = __min(hca(v), dTime(u)); //更新hca[v]——越小越好
         break;
      default: //visited
         status(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;
         break;
      }
   }
   status(v) = VISITED;
}

template <typename Tv, typename Te>
template <typename PU>
void Graph<Tv, Te>::pfs(int s, PU prioUpdater)
{
   reset();
   int v = s;
   do
   {
      if (UNDISCOVERED == status(v))
         PFS(v, prioUpdater);
   } while (s != (v = (++v % n)));
}

//PFS搜索：每次引入当前优先级最高的顶点s，然后按照不同的策略更新其邻接顶点的优先级数
template <typename Tv, typename Te>
template <typename PU>
void Graph<Tv, Te>::PFS(int s, PU prioUpdater)
{
   priority(s) = 0;
   status(s) = VISITED;
   parent(s) = -1;
   while (1) //将下一顶点和边加至PFS树中
   {
      for (int w = firstNbr(s); - 1 < w; w = nextNbr(s, w)) //枚举s的所有邻居
      {
         prioUpdater(this, s, w); //更新顶点w的优先级及其父结点
      }
      for (int shortest = INT_MAX, w = 0; w < n; w++) //数越大，优先级越小
      {
         if (status(w) == UNDISCOVERED) //从尚未加入遍历树的顶点中
            if (shortest > priority(w)) //选出下一个
            {
               shortest = priority(w); //优先级最高的顶点s
               s = w;
            }
      }
      if (VISITED == status(s))
         break;
      status(s) = VISITED;
      status(parent(s), s) = TREE; //将s及其与父顶点的联边加入遍历树
   }
}

//针对Prim算法的顶点优先级更新器
template <typename Tv, typename Te>
struct PtrimPU
{
   virtual void operator()(Graph<Tv, Te> *g, int uk, int v)
   {
      if (g->status(v) == UNDISCOVERED)         //对于uk每一尚未被发现的邻接顶点v
         if (g->priority(v) > g->weight(uk, v)) //按prim策略做松弛
         {
            g->priority(v) = g->weight(uk, v); //更新优先级
            g->parent(v) = uk;                 //更新父结点
         }
   }
};

template <typename Tv, typename Te>
struct DijkstraPU
{
   virtual void operator()(Graph<Tv, Te> *g, int uk, int v)
   {
      if (g->status(v) == UNDISCOVERED)
         if (g->priority(v) > g->priority(uk) + g->weight(uk, v)) //按Dijkstra策略做松弛
         {
            g->priority(v) = g->priority(uk) + g->weight(uk, v);
            g->parent(v) = uk;
         }
   }
};
