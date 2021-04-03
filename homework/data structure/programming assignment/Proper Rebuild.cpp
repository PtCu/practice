#include <cstdio>
using namespace std;
typedef struct Node
{
    int val;
    Node *l;
    Node *r;
} * treeNode;
const int MAX = 4e6;
int pre_seq[MAX];
int post_seq[MAX];
const int SZ = 1 << 20; //快速io
struct fastio
{
    char inbuf[SZ];
    char outbuf[SZ];
    fastio()
    {
        setvbuf(stdin, inbuf, _IOFBF, SZ);
        setvbuf(stdout, outbuf, _IOFBF, SZ);
    }
} io;
void build(treeNode &t, int pre_start, int pre_end, int post_start, int post_end)
{
    int pre_l_start, pre_l_end, pre_r_start, pre_r_end; //先序序列的指针
    int pos_l_start, pos_l_end, pos_r_start, pos_r_end; //后序序列的指针
    t = new Node;
    t->val = pre_seq[pre_start]; //根节点

    if (pre_start == pre_end)
    {
        t->l = NULL;
        t->r = NULL;
        return;
    }

    //确定左子树位置
    pre_l_start = pre_start + 1;
    int count = 0;
    while (pre_seq[pre_l_start] != post_seq[post_start + count])
        count++;
    pre_l_end = pre_l_start + count;
    pos_l_start = post_start;
    pos_l_end = post_start + count;

    //确定右子树位置
    pre_r_start = pre_l_end + 1;
    pos_r_start = pos_l_end + 1;

    count = 0;
    while (t->val != post_seq[pos_r_start + count])
        count++;
    pre_r_end = pre_r_start + count - 1;
    pos_r_end = pos_r_start + count - 1;
    build(t->l, pre_l_start, pre_l_end, pos_l_start, pos_l_end);
    build(t->r, pre_r_start, pre_r_end, pos_r_start, pos_r_end);
}
void in_trav(treeNode t)
{
    if (t == NULL)
        return;
    in_trav(t->l);
    printf("%d ", t->val);
    in_trav(t->r);
}
int n;
treeNode root = NULL;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &pre_seq[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &post_seq[i]);
    build(root, 0, n - 1, 0, n - 1);
    in_trav(root);
}
