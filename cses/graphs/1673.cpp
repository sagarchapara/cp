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

struct  Edge
{
    int u;
    int v;
    int cost;

    Edge(int _u, int _v, int _cost): u(_u), v(_v), cost(_cost){}
};

bool dfs(int curr, vector<bool>& hasChanged, vector<vector<int>>& adjL, vector<bool>& visited){
    visited[curr] = true;
    
    if(hasChanged[curr]){
        return true;
    }

    bool ans = false;

    for(int u: adjL[curr]){
        if(!visited[u]){
            ans |= dfs(u, hasChanged, adjL, visited);
        }
    }

    return ans;
}

bool checkIfCycleExists(int n, vector<bool>& hasChanged, vector<Edge>& edges){
    //reverse adjL
    vector<vector<int>> adjL(n);

    for(Edge& e: edges){
        adjL[e.v].push_back(e.u);
    }

    vector<bool> visited(n, false);

    bool canReach = dfs(n-1, hasChanged, adjL, visited);

    return canReach;
}


void solve() {
    int n, m; cin >> n >> m;

    vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(n, {0,-1}));

    for(int i=0;i<n;i++){
        dp[i][i] = {0,0};
    }

    vector<Edge> edges;

    for(int i=0;i<m;i++){
        int u, v, w; cin >> u >> v >> w; u--, v--;

        if(dp[u][v].second != -1){
            dp[u][v] = {max(w, dp[u][v].first), 0};
        }
        else{
            dp[u][v] = {w, 0};
        }

        edges.emplace_back(u,v,w);
    }

    vector<bool> hasChanged(n, false);

    int x;

    for(int i =0;i<n;i++){
        hasChanged.assign(n, false);
        x = -1;
        for(Edge e: edges){
            if(dp[0][e.u].second  != -1){
                if(dp[0][e.v].second == -1){
                    dp[0][e.v] = {dp[0][e.u].first + e.cost, 0};

                    hasChanged[e.v] = true;
                    x =0;
                }
                else{
                    int val = dp[0][e.u].first + e.cost;

                    if(val > dp[0][e.v].first){
                        dp[0][e.v] = {val, 0};
                        hasChanged[e.v] = true;
                        x= 0;
                    }
                }
            }
        }
    }

    bool canReach = checkIfCycleExists(n, hasChanged, edges);

    dbg(x, canReach);

    if((x==0) && canReach){
        cout << -1 << endl;
    }
    else{
        cout << dp[0][n-1].first << endl;
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
