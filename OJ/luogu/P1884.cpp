#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 10;
struct node1
{
	int l, r;
	int tag;
	int len;
} tree[maxn << 2];

struct node2
{
	int x, y1, y2;
	int flag;
	node2(){};
	node2(int _x, int _y1, int _y2, int _flag) : x(_x), y1(_y1), y2(_y2), flag(_flag) {}
} a[maxn]; // 坐标

//存放真实的y坐标的长度
long long qy[maxn];
unordered_map<int, int> H;

// 对 [l,r] 区间建立线段树,当前根的编号为 k。这里只是初始化了指针，没有赋值len
void build(int k, int l, int r)
{
	tree[k].l = l, tree[k].r = r, tree[k].len = tree[k].tag = 0;
	if (l != r)
	{
		int mid = l + r >> 1;
		build(k << 1, l, mid);
		build(k << 1 | 1, mid + 1, r);
	}
}
//更新k节点
void pushup(int k)
{
	if (tree[k].tag)
		tree[k].len = qy[tree[k].r + 1] - qy[tree[k].l];
	else
		tree[k].len = tree[k << 1].len + tree[k << 1 | 1].len;
}
//[y1,y2]内的节点+flag
void update(int k, int y1, int y2, int flag)
{
	if (y2 < tree[k].l || y1 > tree[k].r)
		return;
	//在区间内
	if (y1 <= tree[k].l && tree[k].r <= y2)
	{
		tree[k].tag += flag;
	}
	else
	{
		update(k << 1, y1, y2, flag);
		update(k << 1 | 1, y1, y2, flag);
	}
	pushup(k);
}
int main()
{
	int x1, x2, y1, y2, n;
	H.clear();
	memset(tree, 0, sizeof(tree));
	memset(qy, 0, sizeof(qy));
	memset(a, 0, sizeof(a));
	long long ans = 0;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> x1 >> y2 >> x2 >> y1;
		a[i] = node2{x1, y1, y2, 1};
		a[i + n] = node2{x2, y1, y2, -1};
		qy[++cnt] = y1;
		qy[++cnt] = y2;
	}
	//需要离散化才能用线段树。保证线段树区间[l,r]不爆炸
	sort(qy + 1, qy + cnt + 1);
	cnt = unique(qy + 1, qy + cnt + 1) - qy - 1;
	for (int i = 1; i <= cnt; ++i)
	{
		H[qy[i]] = i;
	}
	//l为1，r为2n
	build(1, 1, (n <<= 1));
	//按x轴排序
	sort(a + 1, a + 1 + n, [](const node2 &a, const node2 &b) { return a.x < b.x; });
	for (int i = 1; i <= n; ++i)
	{
		//给[y1, y2)内的区间+1
		update(1, H[a[i].y1], H[a[i].y2] - 1, a[i].flag);
		//利用线段树，每次对第一个节点查询，即可得到整个区间的长度
		ans += (long long)tree[1].len * (a[i + 1].x - a[i].x);
	}
	printf("%lld", ans);
}