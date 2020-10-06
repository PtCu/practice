#include "BST.hpp"
#define IsBlack(p) (!(p) || (RB_BLACK == (p)->color)) //外部节点也视作黑节点（注意转入的是指针）
#define IsRed(p) (!IsBlack(p))                        //非黑即红
#define BlackHeightUpdated(x)( \ 
    (stature((x).lc) == stature((x).rc) && \
    ((x).height == (IsRed(&x) ? stature((x).lc) : stature((x).lc) + 1))\
)//红黑树高度更新条件   如果x是黑色，判断x的高度是否等于x的左右子树高度+1，否则判断x的高度是否等于x的左右子树高度。如果不等于则需要更新

template <typename T>
class RedBlack : public BST<T>
{
protected:
    void solveDoubleRed(BinNodePosi(T) x);   //双红修正
    void solveDoubleBlack(BinNodePosi(T) x); //双黑修正
    int updateHeight(BinNodePosi(T) x);      //更新节点x的高度
public:
    BinNodePosi(T) insert(const T &e); //插入（重写）
    bool remove(const T &e);           //删除（重写）
};

template <typename T>
int RedBlack<T>::updateHeight(BinNodePosi(T) x)
{
    x->height = max(stature(x->lc), stature(x->rc)); //孩子一般黑高度相等，除非出现双黑
    return IsBlack(x) ? x->height++ : x->height;     //若当前节点为黑，则计入黑深度
}

template <typename T>
BinNodePosi(T) RedBlack<T>::insert(const T &e)
{ //将关键码e插入红黑树
    BinNodePosi(T) &x = search(e);
    if (x)
        return x;                                //确认目标节点不存在
    x = new BinNode<T>(e, _hot, NULL, NULL, -1); //创建红节点x，以_hot为父，黑高度为-1
    _size++;
    solveDoubleRed(x); //插入的时候就检查是否存在双红现象。经双红修正后，即可返回
    return x;
} //无论e是否存在于原树中，返回时总有x->data==e

template <typename T>
void RedBlack<T>::solveDoubleRed(BinNodePosi(T) x)
{

    //若已（递归）转至树根，则将其转黑，整树黑高度也随之递增
    if (IsRoot(*x))
    {
        _root->color = RB_BLACK;
        _root->height++;
        return;
    }
    //否则，x的父亲p必然存在
    BinNodePosi(T) p = x->parent;
    if (IsBlack(p)) //若p为黑，则可终止调整
        return;
    BinNodePosi(T) g = p->parent; //若p为红，说明祖父g一定存在
    BinNodePosi(T) u = uncle(x);

    //RR-1：做3+4重构.2次颜色翻转，2次黑高度更新，1~2次旋转，不再递归
    if (IsBlack(u))
    {
        if (IsLChild(*x) == IsLChild(*p)) //x与p同侧(zig-zig,zag-zag)
            p->color = RB_BLACK;
        else
            x->color == RB_BLACK; //x与p异侧(zig-zag,zag-zig)
        g->color = RB_RED;
        //以上虽保证总共两次染色，但因增加了判断而得不偿失
        //在旋转后将根置黑、孩子置红，虽需三次染色但效率更高
        BinNodePosi(T) gg = g->parent;                     //曾祖父
        BinNodePosi(T) r = FromParentTo(*g) = rotateAt(x); //调整后的子树根节点 FromParentTo是来自父亲的引用，相当于将gg与新的g (r)连接
        r->parent = gg;                                    //与原曾祖父联接
    }

    //RR-2:
    else
    {
        p->color = RB_BLACK; //p由红转黑
        p->height++;
        u->color = RB_BLACK; //u由红转黑
        u->height++;
        if (!IsRoot(*g)) //g若非根，则转红
            g->color = RB_RED;
        solveDoubleRed(g); //继续调整g。类似尾递归，可优化为迭代形式
    }
}

//x作为实际被删除者，故w必为黑色的外部节点NULL
template <typename T>
bool RedBlack<T>::remove(const T &e)
{
    BinNodePosi(T) &x = search(e);
    if (!x) //确认目标节点存在
        return false;
    BinNodePosi(T) r = removeAt(x, _hot); //removeAt()返回实际被删除节点的替代者
    if (--_size <= 0)                     //没节点了
        return true;                      //实施删除

    //assert:_hot某一孩子刚被删除，且被r所指节点（可能是NULL）接替。以下检查是否失衡，并作必要调整
    if (!_hot) //若刚被删除的是根节点，则将其置黑，并更新黑高度
    {
        _root->color = RB_BLACK;
        updateHeight(_root);
        return true;
    }
    //assert:以下，原x(现r)必非根，_hot必非空
    if (BlackHeightUpdated(*(_hot))) //如果没必要调整
        return true;
    if (IsRed(r)) //否则，若r为红，则只需令其转黑
    {
        r->color = RB_BLACK;
        r->height++;
        return true;
    }

    //assert：以下，原x（现r）均为黑色
    solveDoubleBlack(r); //解决双黑缺陷
    return true;
}

template <typename T>
void RedBlack<T>::solveDoubleBlack(BinNodePosi(T) r)
{
    BinNodePosi(T) p = r ? r->parent : _hot;
    if (!p)
        return;                                      //r的父亲
    //考虑r的兄弟s的儿子情况
    BinNodePosi(T) s = (r == p->lc) ? p->rc : p->lc; //r的兄弟
    if (IsBlack(s))                                  //兄弟s为黑
    {
        BinNodePosi(T) t = NULL; //s的红孩子（若左右孩子皆红，左者优先；皆黑时为NULL）
        if (HasLChild(*s) && IsRed(s->lc))
            t = s->lc;
        else if (HasRChild(*s) && IsRed(s->rc))
            t = s->rc;
        if (t) //黑s有红孩子：BB-1 只要有一个红孩子就行，另一个孩子是什么颜色无所谓
        {
            RBColor oldColor = p->color;                       //备份原子树根节点p颜色，并对t及其父亲、祖父
            BinNodePosi(T) b = FromParentTo(*p) = rotateAt(t); //重平衡，并将新子树的左右孩子染黑
            if (HasLChild(*b))  //将左右孩子染成黑色
                b->lc->color = RB_BLACK;
            updateHeight(b->lc);
            if(HasRChild(*b))   
                b->rc->color = RB_BLACK;
            updateHeight(b->rc);
            b->color = oldColor;    //新上位的集成原来的颜色
            updateHeight(b);
        }
        else    //黑s无红孩子
        {
            s->color = RB_RED;  //s要变成红色
            s->height--;
            if(IsRed(p))    //p红色 BB-2-R
            {
                p->color = RB_BLACK;
            }
            else    //p黑色 BB-2-B
            {
                p->height--;
                solveDoubleBlack(p);
            }
        }
    }
    else    //兄弟s为红：BB-3
    {
        s->color = RB_BLACK;
        p->color = RB_RED;
        BinNodePosi(T) t = IsLChild(*s) ? s->lc : s->rc;    //确定zig zag
        _hot = p;
        FromParentTo(*p) = rotateAt(t); //t为p的孙子。将s上位
        solveDoubleBlack(r);    //继续修正r处双黑——此时的p已转红，故后续只能是BB-1或BB-2R
    }
}
