#include "BST.hpp"
template <typename T>
class Splay : public BST<T>
{
protected:
    BinNodePosi(T) splay(BinNodePosi(T) v); //将节点v伸展至根
public:
    BinNodePosi(T) & search(const T &e); //查找（重写）
    BinNodePosi(T) insert(const T &e);   //插入（重写）
    bool remove(const T &e);             //删除（重写）
};

//在节点p与lc（可能为空）之间建立父（左）子关系
template <typename NodePosi>
inline void attachAsLChild(NodePosi p, NodePosi lc)
{
    p->lc = lc;
    if (lc)
        lc->parent = p;
}

//在节点p与lc（可能为空）之间建立父（左）子关系
template <typename NodePosi>
inline void attachAsRChild(NodePosi p, NodePosi rc)
{
    p->rc = rc;
    if (rc)
        rc->parent = p;
}

//splay树伸展算法，从节点v出发逐层伸展
template <typename T>
BinNodePosi(T) Splay<T>::splay(BinNodePosi(T) v)
{
    if (!v)
        return NULL;
    BinNodePosi(T) p;
    BinNodePosi(T) g; //v的父亲与祖父
    while ((p = v->parent) && (g = p->parent))
    {
        BinNodePosi(T) gg = g->parent;
        if (IsLChild(*v))
            if (IsLChild(*p)) //zig-zig      先转祖父再转父亲
            {

                attachAsLChild(g, p->rc);
                attachAsRChild(p, g);
                attachAsLChild(p, v->rc);
                attachAsRChild(v, p);
            }
            else if (IsRChild(*p)) //zig-zag   和单层的一样,可直接3+4
            {
                attachAsLChild(p, v->rc);
                attachAsRChild(g, v->lc);
                attachAsLChild(v, g);
                attachAsRChild(v, p);
            }
            else if (IsRChild(*v))
            {
                if (IsLChild(*p)) //zag-zig
                {
                    attachAsRChild(p, v->lc);
                    attachAsLChild(g, v->rc);
                    attachAsLChild(v, p);
                    attachAsRChild(v, g);
                }
                else if (IsRChild(*p)) //zag-zag
                {
                    attachAsRChild(g, p->rc);
                    attachAsRChild(p, v->lc);
                    attachAsLChild(p, g);
                    attachAsLChild(v, p);
                }
            }
        if (!gg)
            v->parent = NULL; //v原先的曾祖父gg不存在，则v现在应为树根
        else
            (g == gg->lc) ? attachAsLChild(gg, v) : attachAsRChild(gg, v);
        updateHeight(g);
        updateHeight(p);
        updateHeight(v);
    }
    if (p = v->parent) //p果真非空，则额外再做一次单旋(注意是赋值，不是判等)
    {
        if (IsLChild(*v))
        {
            attachAsLChild(p, v->rc);
            attachAsRChild(v, p);
        }
        else
        {
            attachAsRChild(p, v->lc);
            attachAsLChild(v, p);
        }
        updateHeight(p);
        updateHeight(v);
    }
    v->parent = NULL;
    return v;
} //调整之后新树根应为被伸展的节点

template <typename T>
    BinNodePosi(T) & Splay<T>::search(const T &e)
{
    BinNodePosi(T) p = searchIn(_root, e, _hot = NULL);
    _root = splay((p ? p : _hot)); //将最后一个被访问的节点伸展至根.若没找到p则将p的父亲送到树根
    return _root;
} //与其他BST不同，无论查找成功与否，_root都指向最后被访问的节点(树根处)

template <typename T>
BinNodePosi(T) Splay<T>::insert(const T &e)
{
    if (!_root) //原树为空
    {
        _size++;
        return _root = new BinNode<T>(e);
    }
    if (e == search(e)->data) //确认目标节点不存在
        return _root;
    _size++;
    BinNodePosi(T) t = _root;
    if (_root->data < e) //插入新根，以t和t->rchild为左右孩子
    {
        t->parent = _root = new BinNode<T>(e, NULL, t, t->rc);
        if (HasRChild(*t))
        {
            t->rc->parent = _root;
            t->rc = NULL;
        }
    }
    else 
    {
        t->parent = _root = new BinNode<T>(e, NULL, t->lc, t);
        if (HasLChild(*t))
        {
            t->lc->parent = _root;
            t->lc = NULL;
        }
    }
    updateHeightAbove(t); //更新t及其祖先（实际上只有一个_root）的高度
    return _root;         //新节点必然置于树根，返回之
} //无论e是否存在于原书中，返回时总有_root->data==e

//删除算法：先查找，之后待删除节点自然在根节点。如果只有一个子树，就直接删除根节点。否则就在右子树中查找待删除节点，
//查找后将右子树的根节点作为新的根节点
template <typename T>
bool Splay<T>::remove(const T&e){
    if(!_root||(e!=search(e)->data))    //若树空或目标关键码不存在，则无法删除
        return false;
    BinNodePosi(T) w = _root;   //经search()后节点e已被伸展至树根
    if(!HasLChild(*_root))  //无左子树，直接删除
    {
        _root = _root->rc;
        if(_root)
            _root->parent = NULL;
    }
    else if(!HasRChild(*_root)) //无右子树也直接删除
    {
        _root = _root->lc;
        if(_root)
            _root->parent = NULL;
    }
    else    //左右子树同时存在
    {
        BinNodePosi(T) lTree = _root->lc;
        lTree->parent = NULL;
        _root->lc = NULL; //暂时将左子树切除
        _root = _root->rc;
        _root->parent = NULL;   //只保留右子树
        search(w->data);
        //assert:至此，右子树中最小节点必伸展至根，且左子树必空
        _root->lc = lTree;
        lTree->parent = _root;
    }
    release(w->data);
    release(w);
    _size--;
    if(_root)
        updateHeight(_root);
    return true;
}

