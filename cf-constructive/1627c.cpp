// g++ -o out <filename>.cpp
// .\out.exe

#define SAGAR

#include <bits/stdc++.h>
using namespace std;                                    

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x << " "; return os;}
void dbg_out() { cerr << ""; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << endl; dbg_out(T...); }
#ifdef SAGAR
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define F first
#define S second
#define pi pair<int,int>
#define vi vector<int>
#define vvi vector<vector<pi>>
#define all(x) (x).begin(), (x).end()
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define sz(x) (int)(x).size()

void dfs(int curr, int par, int col, vvi& adj, vi& color){
    for(auto p: adj[curr]){
        if(p.first != par){
            color[p.second] = col;
            // dbg(curr); dbg(par); dbg(col); dbg(p);
            dfs(p.first, curr, 5-col, adj, color);
        }
    }
}

void solve() {
    int n; cin >>n ;
    vvi adj(n);
    for(int i=0;i<n-1;i++){
        int u,v; cin >> u >> v; u--, v--;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }
    rep(i,0,n){
        if(adj[i].size()>2){
            cout << -1 << endl;
            return;
        }
    }
    int num = 2; vi ans(n-1);
    for(auto p: adj[0]){
        dfs(p.first, 0, 5-num, adj, ans);
        ans[p.second] = num;
        num++;
    }

    cout << ans << endl;
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
