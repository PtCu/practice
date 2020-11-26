//[Hdu1754 I Hate It](http://acm.hdu.edu.cn/showproblem.php?pid=1754 "Hdu1754 I Hate It")
#include <bits/stdc++.h>
#define For(a, b) for (ll a = 0; a < b; a++)
#define mem(a, b) memset(a, b, sizeof(a))
#define _mem(a, b) memset(a, 0, (b + 1) << 2)
#define lowbit(a) ((a) & -(a))

using namespace std;
typedef long long ll;
const ll maxn = 2 * 1e5 + 5;
const ll INF = 0x3f3f3f3f;
struct node
{
    ll l, r, w, flag;
} a[maxn << 2]; //4倍空间
ll c[maxn];
ll cnt;
void build(ll k, ll l, ll r)
{
    a[k].l = l, a[k].r = r;
    if (a[k].l == a[k].r)
    {
        cin >> a[k].w;
        return;
    }
    build(k * 2, l, (l + r) / 2);
    build(k * 2 + 1, (l + r) / 2 + 1, r);
    a[k].w = max(a[k * 2].w, a[k * 2 + 1].w);
}

void changellerval(ll k, ll x, ll z)
{
    if (a[k].l == x && a[k].r == x)
    {
        a[k].w = z;
        return;
    }
    ll buf = (a[k].l + a[k].r) / 2;
    if (x <= buf)
        changellerval(k * 2, x, z);
    if (x > buf)
        changellerval(k * 2 + 1, x, z);
    a[k].w = max(a[k * 2].w, a[k * 2 + 1].w);
}
ll ans;
void askllerval(ll k, ll x, ll y)
{
    if (a[k].l >= x && a[k].r <= y)
    {
        ans = max(a[k].w, ans);
        return;
    }
    ll buf = (a[k].l + a[k].r) / 2;
    if (x <= buf)
        askllerval(k * 2, x, y);
    if (y > buf)
        askllerval(k * 2 + 1, x, y);
}

int main()
{
    //IO;
    do
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    } while (0);
    char buf;
    ll n, m;
    ll x, y, z;
    while (cin >> n >> m)
    {
        build(1, 1, n);
        For(i, m)
        {
            getchar();
            scanf("%c", &buf);
            //cin >> buf;
            if (buf == 'Q')
            {
                scanf("%lld%lld", &x, &y);
                //cin >> x >> y;
                ans = 0;
                askllerval(1, x, y);
                printf("%lldn", ans);
                //cout << ans << endl;
            }
            else
            {
                scanf("%lld%lld", &x, &z);
                //cin >> x >> y >> z;
                changellerval(1, x, z);
            }
        }
    }
    return 0;
}