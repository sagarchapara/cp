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
#define pii pair<int,pi>
#define vi vector<int>
#define vii vector<vector<pi>>
#define vpii vector<pii>
#define all(x) (x).begin(), (x).end()
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define sz(x) (int)(x).size()

# define INF 0x3f3f3f3f

void solve() {
    int n,m,s; cin >> n >> m >> s; s--;
    vii adj(n); 
    vpii edges(m);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vi d(n, INF); 
    rep(i,0,m){
        int u,v,w; cin >> u >> v >> w; u--, v--;
        edges[i] = {w, {u,v}};
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int l; cin >> l;

    dbg(adj); dbg(l);

    vi num(n, 0); 
    // vector<bool> visited(n, false);

    d[s] =0; 
    // visited[s] = true;

    pq.push({0,s});
    int ans =0;

    while(!pq.empty()){
        auto [dist, curr] = pq.top();
        pq.pop();
        for(pi nxt: adj[curr]){
            int nxtDist = d[curr] + nxt.S;
            if(nxtDist < d[nxt.F]){
                d[nxt.F] = nxtDist;
                // if(!visited[nxt.F]){
                pq.push({nxtDist, nxt.F});
                // visited[nxt.F] = true;
                // }
            }
        }
    }

    // dbg(d);



    vector<bool> hasTaken(n, false);
    for(auto edge: edges){
        int w = edge.F;
        int u = edge.S.F, v = edge.S.S;
        // dbg(edge);
        if(d[u]< l && d[u]+w > l){
            int k = l-d[u];
            if(d[v]+w-k >= l){
                ans++;
            }
        }
        if(d[v]< l && d[v]+w > l){
            int k = l - d[v];
            if(d[u]+w-k > l){
                ans++;
            }
        }

    }
    rep(i,0,n){
        if(d[i]==l){
            ans++;
        }
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
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
