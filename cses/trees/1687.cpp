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
    int n, MAXL;
    vector<vector<int>> adjL;
    vector<vector<int>> parent;
    vector<int> lvl, tin, tout;

    int time =0;

    void dfs(int curr, int par, int level){
        tin[curr] = time++;
        lvl[curr] = level;
        parent[curr][0] = par;

        for(int i: adjL[curr]){
            if(i != par){
                dfs(i, curr, level+1);
            }
        }

        tout[curr] = time++;
    }

    void precompute(){
        for(int j=1;j<MAXL;j++){
            for(int i=0;i<n;i++){
                if(parent[i][j-1] == -1){
                    parent[i][j] = -1;
                }
                else{
                    parent[i][j] = parent[parent[i][j-1]][j-1];
                }
            }
        }
    }

    bool is_ancestor(int u, int v){
        return (tin[u] < tin[v]) && (tout[u] > tout[v]); 
    }

public:
    int find_k(int curr, int k){
        for(int i=MAXL-1;i>=0;i--){
            if(k&(1<<i)){
                if(curr == -1){
                    return -1;
                }
                curr = parent[curr][i];
            }
        }

        return curr;
    }

    int lca(int u, int v){
        if(lvl[u] < lvl[v]){
            swap(u,v);
        }

        if(is_ancestor(v, u)) return v;

        //now match the diff
        int diff = lvl[u] - lvl[v];

        u = find_k(u, diff);

        //now both are at same level
        for(int i=MAXL-1;i>=0;i--){
            if(parent[u][i] != parent[v][i]){
                u = parent[u][i];
                v = parent[v][i];
            }
        }

        return parent[u][0];
    }

    LCA(int _n, vector<vector<int>>& _adjL): n(_n), adjL(_adjL){
        MAXL = log2(n)+1;
        parent.resize(n, vector<int>(MAXL, -1));
        tin.resize(n);
        tout.resize(n);
        lvl.resize(n, -1);
        time = 0;

        for(int i=0;i<n;i++){
            if(lvl[i] == -1){
                dfs(i, -1, 0);
            }
        }

        dbg(parent, tin, tout, lvl);

        precompute();
    }
};

void solve() {
    int n,q; cin >> n >> q;

    vector<vector<int>> adjL(n);

    for(int i=1;i<n;i++){
        int a; cin >> a ; a--;
        adjL[i].push_back(a);
        adjL[a].push_back(i);
    }

    LCA lca(n, adjL);

    dbg(q);

    while (q--)
    {
        int e, k; cin >> e >> k; e--;

        int val = lca.find_k(e, k);

        val = (val == -1) ? -1 : (val+1);

        cout << val << endl;
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
