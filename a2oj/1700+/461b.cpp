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
#define vii vector<vi>
#define all(x) (x).begin(), (x).end()
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define sz(x) (int)(x).size()

const int MOD = 1e9+7;

bool dfs(int curr,int par,vii& adj,vi& color,vii& dp){
    vi seen;
    if(color[curr] == 1){
        dp[curr][0] =0; dp[curr][1] = 1; int prod = 1;
        for(int nxt: adj[curr]){
            if(nxt!=par){
                bool t = dfs(nxt, curr, adj, color, dp);
                if(t){
                    int temp = ((dp[nxt][1]+dp[nxt][0]))%MOD;
                    prod = (prod*temp)%MOD;
                }
            }
        }
        dp[curr][1] = prod;

        return true;
    }
    else{
        dp[curr][0] = 1; dp[curr][1] = 0; int count =0;
        for(int nxt: adj[curr]){
            if(nxt!=par){
                bool t = dfs(nxt, curr, adj, color, dp);
                if(t){
                    int temp = (dp[nxt][0] + dp[nxt][1])%MOD;
                    dp[curr][0] = (dp[curr][0]*temp)%MOD;
                    count++;
                    seen.push_back(nxt);
                }
            }
        }
        // dbg(count);
        int prod = dp[curr][0]; dp[curr][1] =0;
        for(int nxt: seen){
            int temp = (dp[nxt][0] + dp[nxt][1])%MOD;
            temp = (prod/temp)%MOD;
            temp = (temp*dp[nxt][1])%MOD;
            dp[curr][1]+=temp;
        }
        return count >0 ;
    }
}

void solve() {
    int n; cin >> n;
    vii adj(n); vii dp(n,vi(2,0));
    rep(i,1,n){
        int x; cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    vi color(n); for(int& x:color) cin >> x;

    int ans = 0;
    rep(i,0,n){
        if(color[i]== 1){
            dfs(i,-1,adj,color,dp);
            ans = dp[i][1];
            break;
        }
    }
    dbg(dp);

    cout << ans;
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
