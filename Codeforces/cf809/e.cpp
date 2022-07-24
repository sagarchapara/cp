// g++ -o out <filename>.cpp -D SAGAR
// .\out.exe

#include <bits/stdc++.h>
using namespace std;                                    

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x << " "; return os;}
void dbg_out() { cerr << "" << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << " " ; dbg_out(T...); }
#ifdef SAGAR
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define pi pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vpi vector<pi>
#define vvpi vector<vpi>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define sz(x) (int)(x).size()

class LCA{
    int n, l, timer, root;
    vvpi adj;

    vector<int> tin, tout;
    vvi up, mw;

    void dfs(int v, int p, int w)
    {   
        // dbg(v, p, w);

        tin[v] = ++timer;
        up[v][0] = p; mw[v][0] = w;

        for (int i = 1; i <= l; ++i){
            up[v][i] = up[up[v][i-1]][i-1];
            mw[v][i] = max(mw[v][i-1], mw[up[v][i-1]][i-1]);
        }
            

        for (auto [u,nw] : adj[v]) {
            if (u != p)
                dfs(u, v, nw);
        }

        tout[v] = ++timer;
    }

    bool is_ancestor(int u, int v)
    {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int getWeight(int u, int lc){
        if( u == lc) return 0;
        int ans = 0;
        for(int i = l;i >=0; --i){
            if(!is_ancestor(up[u][i], lc)){
                ans = max( ans, mw[u][i]);
                u = up[u][i];
            }
        }

        ans = max( ans, mw[u][0]);
        u = up[u][0];

        assert(u == lc);

        return ans;
    }

    public:

        int lca(int u, int v)
        {
            if (is_ancestor(u, v))
                return u;
            if (is_ancestor(v, u))
                return v;
            for (int i = l; i >= 0; --i) {
                if (!is_ancestor(up[u][i], v))
                    u = up[u][i];
            }
            return up[u][0];
        }

        int getMaxWeight(int u, int v){
            int lc = lca(u,v);

            int a = getWeight(u, lc);
            int b = getWeight(v, lc);

            return max(a,b);
        }

        LCA (int _n, vvpi& _adj, int _root = 0): n(_n), adj(_adj), root(_root){
            tin.resize(n), tout.resize(n);
            timer = 0, l = ceil(log2(n));
            up.assign(n, vi(l + 1));
            mw.assign(n, vi(l + 1));
            dfs(root, root, 0);
        }   
};


class DSU {
    vi parent;
    int n;

    public:
        DSU (int _n): n(_n){
            parent.resize(n);
            iota(all(parent), 0ll);
        }

        int find_set(int v) {
            if (v == parent[v])
                return v;
            return parent[v] = find_set(parent[v]);
        }

        bool check(int u, int v){
            return find_set(u) != find_set(v);
        }

        void union_sets(int a, int b) {
            a = find_set(a);
            b = find_set(b);
            if (a != b)
                parent[b] = a;
        }
};

class SegmentTree{
    int n;
    vector<int> t;

    void build(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = max(t[v*2] , t[v*2+1]);
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return max(query(v*2, tl, tm, l, min(r, tm))
            ,query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }

    public:

        SegmentTree(int _n, vector<int>& arr): n(_n){
            t.resize(4*n,0);
            build(arr,1,0,n-1);
        }

        int getQuery(int l, int r){
            return query(1,0,n-1,l,r);
        } 
};


void solve() {
    int n, m, q; cin >> n >> m >> q;
    vvpi adj(n); 
    
    DSU g(n);

    rep(i,0,m){
        int l, r; cin >> l >> r ;l--, r--;
        if(g.check(l,r)){
            g.union_sets(l,r);
            adj[l].push_back({r, i+1});
            adj[r].push_back({l, i+1});
        }
    }

    // dbg(adj);

    LCA lca (n, adj);

    vi ans(n); ans[0] =0;
    rep(i,1,n){
        ans[i] = lca.getMaxWeight(i,i-1);
    }

    dbg(ans);

    SegmentTree segTree(n, ans);

    rep(i,0,q){
        int l, r; cin >> l >> r; l--, r--;
        if(l>r) swap(l,r);

        int k = segTree.getQuery(l+1, r);

        printf("%d ", k);
    }
    printf("\n");
}

int32_t main() {
    #ifdef SAGAR
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
    #endif

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
