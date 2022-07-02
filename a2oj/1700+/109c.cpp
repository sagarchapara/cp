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
#define vii vector<vector<pi>>

#define all(x) (x).begin(), (x).end()
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define sz(x) (int)(x).size()

int getWeight(int num){
    while(num!=0){
        int rem = num%10;
        if( rem != 4 && rem !=7){
            return 0;
        }
        num/=10;
    }
    return 1;
}

void dfs(int curr, int par, vii& adj, vi& tsize, vi& tans){
    tsize[curr] = 1; tans[curr]=0;

    for(pi nxt: adj[curr]){
        if(nxt.F == par) continue;

        dfs(nxt.F, curr, adj, tsize, tans);

        if(nxt.S == 1) tans[curr]+= tsize[nxt.F];
        else tans[curr]+= tans[nxt.F];
        tsize[curr]+= tsize[nxt.F];
    }
}

void getAns(int curr, int par, int edge, int par_num, int n,vii& adj, vi& tsize, vi& tans, int& ans){
    int num;
    if(edge == 1){
        num = n - tsize[curr];
        num+= tans[curr]; 
    }
    else{
        num = par_num;
    }
    ans+= num*(num-1);

    for(pi nxt: adj[curr]){
        if(nxt.F == par) continue;
        getAns(nxt.F, curr, nxt.S, num, n, adj, tsize, tans, ans);
    }
}


void solve() {
    int n; cin >> n;
    vii adj(n);

    for(int i=0;i<n-1;i++){
        int l,r,w; cin >> l >> r >> w;
        w = getWeight(w); l--; r--;
        adj[l].push_back({r,w});
        adj[r].push_back({l,w});
    }

    dbg(adj);

    vi tsize(n,0); vi tans(n,0);

    dfs(0,-1,adj,tsize,tans);

    dbg(tsize); dbg(tans);

    int ans =0;

    getAns(0, -1, 0, tans[0], n,adj, tsize, tans, ans);

    cout << ans<< endl;
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
