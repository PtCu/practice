#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;
struct Node
{
    Node *left, *right;
    char V;
};
char in[maxn], pre[maxn];
void build(Node *&t, size_t pre_start, size_t pre_end, size_t in_start, size_t in_end)
{
    if(pre_start>pre_end){
        t = NULL;
        return;
    }
    t = new Node;
    t->V = pre[pre_start];

    size_t l_len = 0;
    while (in[in_start + l_len] != t->V)
        l_len++;

    //l_len为左子树的序列长度
    size_t l_pre_start = pre_start + 1;
    size_t l_pre_end = pre_start + l_len;

    size_t l_in_start = in_start;
    size_t l_in_end = in_start + l_len - 1;

    //r_len为右子树的序列长度
    size_t r_len = in_end - (in_start + l_len);

    size_t r_pre_start = l_pre_end + 1;
    size_t r_pre_end = l_pre_end + r_len;

    size_t r_in_start = in_start + l_len + 1;
    size_t r_in_end = r_in_start + r_len - 1;

    build(t->left, l_pre_start, l_pre_end, l_in_start, l_in_end);
    build(t->right, r_pre_start, r_pre_end, r_in_start, r_in_end);
}
void post(Node *p)
{
    if (p == NULL)
        return;
    post(p->left);
    post(p->right);
    printf("%c", p->V);
}
int main()
{
    Node *root = NULL;
    scanf("%s", in);
    scanf("%s", pre);
    build(root, 0, strlen(in) - 1, 0, strlen(pre) - 1);
    post(root);

}