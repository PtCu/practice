#include <cstdio>
#include <algorithm>
using namespace std;

//树的结点
struct Node
{
    int data;    //数据域
    int height;  //以该结点为根的子树的高度
    Node *left;  //左子结点地址
    Node *right; //右子结点地址
};
//创建一个新结点并返回新结点地址
Node *newNode(int k)
{
    Node *r = new Node; //创建
    r->data = k;        //给结点赋值
    r->height = 1;      //新结点（叶子结点）高度为1
    r->left = NULL;
    r->right = NULL;
    return r; //返回新结点指针
}
//返回以指定结点为根的子树的高度
int getHeight(Node *root)
{
    if (root != NULL)
        return root->height;
    return 0; //空结点树高为0
}
//返回以指定结点为根的子树的平衡因子
int getBalanceFactor(Node *root)
{
    return getHeight(root->left) - getHeight(root->right); //左右两子树的高度差
}
//更新树高
void updateHeight(Node *root)
{
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1; //最大子树高加一
}
//左旋
Node *rotateLeft(Node *root)
{
    Node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    //更新旋转后的树高
    updateHeight(root);
    updateHeight(temp);
    return temp; //左旋后新的根结点
}
//右旋
Node *rotateRight(Node *root)
{
    Node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    //更新旋转后的树高
    updateHeight(root);
    updateHeight(temp);
    return temp; //右旋后新的根结点
}
//插入新结点
Node *insert(Node *root, int k)
{
    //从上往下查找插入的位置
    if (root == NULL) //空结点为插入的位置
        return newNode(k);
    //k比当前结点小
    if (k < root->data)
    {
        root->left = insert(root->left, k); //向下往左子树插入
        updateHeight(root);                 //插入后更新树高
        if (getBalanceFactor(root) > 1)     //旋转以恢复平衡
        {
            if (getBalanceFactor(root->left) > 0)
                root = rotateRight(root);
            else if (getBalanceFactor(root->left) < 0)
            {
                root->left = rotateLeft(root->left);
                root = rotateRight(root);
            }
        }
    }
    //k比当前根结点大
    else if (k > root->data)
    {
        root->right = insert(root->right, k); //向下往右子树插入
        updateHeight(root);                   //插入后更新树高
        if (getBalanceFactor(root) < -1)      //旋转以恢复平衡
        {
            if (getBalanceFactor(root->right) < 0)
                root = rotateLeft(root);
            else if (getBalanceFactor(root->right) > 0)
            {
                root->right = rotateRight(root->right);
                root = rotateLeft(root);
            }
        }
    }
    return root; //向上返回当前结点作为新的子结点
}

int main()
{
    int n;
    scanf("%d", &n);
    Node *root = NULL; //新建一棵空树
    for (int i = 0; i < n; i++)
    {
        int key;
        scanf("%d", &key);
        root = insert(root, key); //逐个结点插入
    }
    printf("%d", root->data);
    return 0;
}