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

template<typename T=int>
class SegmentTree{
    int n;
    vector<T> tree;
    
    T merge(T a, T b){
        return a + b;
    }

    void build(int tv, int tl, int tr, vector<T>& arr){
        if(tl == tr){
            tree[tv] = arr[tl];
            return;
        }

        int mid = (tl+tr)/2;

        build(2*tv, tl, mid, arr);
        build(2*tv+1, mid+1, tr, arr);

        tree[tv] = merge(tree[2*tv], tree[2*tv+1]);
    }

    void update(int tv, int tl, int tr, int idx, T val){
        if(tl == tr){
            tree[tv] = val;
            return;
        }

        int mid = (tl+tr)/2;

        if(idx <= mid){
            update(2*tv, tl, mid, idx, val);
        }
        else{
            update(2*tv+1, mid+1, tr, idx, val);
        }

        tree[tv] = merge(tree[2*tv], tree[2*tv+1]);
    }

    T get(int tv, int tl, int tr, int l, int r){
        //dbg(tl, tr, l, r);

        if(l > r){
            return T();
        }

        if(l == tl && r == tr){
            return tree[tv];
        }

        int mid = (tl+tr)/2;

        T val = merge(get(2*tv, tl, mid, l, min(r, mid)), get(2*tv+1, mid+1, tr, max(mid+1, l), r));

        return val;
    }

public:

    SegmentTree(){}

    SegmentTree(int _n): n(_n){
        tree.resize(4*n);
    }

    SegmentTree(int _n, vector<int>& _arr) : n(_n){
        tree.resize(4*n, 0);
        build(1, 0, n-1, _arr);

        dbg(tree);
    }

    void update(int idx, T val){
        update(1, 0, n-1, idx, val);
    }

    T get(int l, int r){
        return get(1, 0, n-1, l, r);
    }
};

class EulerTour{
    int n;
    vector<int> tin, tout, arr, values;
    vector<vector<int>> adjL;
    int timer = 0;
    SegmentTree<int> tree;

    void dfs(int curr, int par){
        tin[curr] = timer++;
        arr.push_back(values[curr]);

        for(int u: adjL[curr]){
            if(u != par){
                dfs(u, curr);
            }
        }

        tout[curr] = timer++;
        arr.push_back(values[curr]);
    }

public:

    EulerTour(int _n, vector<vector<int>>& _adjL, vector<int>& _values): n(_n), adjL(_adjL), values(_values){
        tin.resize(n);
        tout.resize(n);
        timer =0;
        dfs(0, -1);

        dbg(tin, tout);

        dbg(arr);

        tree = SegmentTree<int>(arr.size(), arr);
    }

    void update(int x, int val){

        dbg(x, val, tin[x], tout[x]);

        tree.update(tin[x], val);
        tree.update(tout[x], val);
    }

    int get(int x){
        dbg(x, tin[x], tout[x]);

        int val = tree.get(tin[x], tout[x]);

        return (val)/2;
    }
};

void solve() {
    int n, q; cin >> n >> q;

    vector<vector<int>> adjL(n);
    vector<int> values(n);

    for(int i=0;i<n;i++){
        cin >> values[i];
    }

    for(int i=1;i<n;i++){
        int u, v; cin >> u >> v; u--, v--;

        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }

    EulerTour euler_tour(n, adjL, values);

    while(q--){
        int t; cin >> t;

        if(t == 1){
            int idx, val; cin >> idx >> val; idx--;

            euler_tour.update(idx, val);
        }
        else{
            int idx; cin >> idx; idx--;

            int val = euler_tour.get(idx);

            cout << val << endl;
        }
    }
}

int32_t main() {
    #ifdef SAGAR
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
    #endif

    auto start = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }

    auto stop = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();

    #ifdef SAGAR
		cerr << "Took " << stop - start << "ms" << endl;
	#endif
}
