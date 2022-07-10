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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define sz(x) (int)(x).size()

bool dfs(int curr, int par, vvi&adj, vi& dist, set<int>& special, vector<bool>& hasDest, int dest){
    dist[curr] =0; bool hasSpecial = false;
    // dbg(curr);
    for(int i: adj[curr]){
        if(i!=par){
            bool k = dfs(i, curr, adj,dist, special, hasDest, dest);
            // dbg(i,k);

            if(hasDest[i]){
                dist[curr]+= (dist[i]+1);
            }
            else if(k){
                dist[curr] += (dist[i] + 2);
            }

            // dbg(dist[curr]);
          
            hasSpecial = hasSpecial | k;
            hasDest[curr] = hasDest[curr] | hasDest[i];
        }
    }
    if(curr == dest) {
        hasDest[curr] = true;
    }
    // dbg(curr);
    if(special.count(curr)>0 || hasSpecial) return true; 

    return false;
}

void solve() {
    int n, k, x, y; cin >> n >> k >> x >> y;x--, y--;
    set<int> special; rep(i,0,k) {int x; cin >> x; x--; special.insert(x);}
    vvi adj(n); vi dist(n,0);
    rep(i,0,n-1){
        int u,v; cin >>u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> hasDest(n, false);

    dfs(x,-1,adj,dist,special,hasDest, y);

    // dbg(special);
    // dbg(dist); dbg(hasDest);

    cout << dist[x] << endl;
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
