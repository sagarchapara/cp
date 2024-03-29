// g++ -o out <filename>.cpp
// .\out.exe

// #define SAGAR

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
#define all(x) (x).begin(), (x).end()
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define sz(x) (int)(x).size()

void solve() {
    int n ; cin >> n;
    vector<vi> arr(n, vi(3));
    rep(j,0,3)
        rep(i,0,n) cin >> arr[i][j];
    int dp[n][2][2];

    rep(i,0,n){
        dp[i][0][0] = arr[i][0];
        dp[i][0][1] = arr[i][1];
        dp[i][1][0] = arr[i][1];
        dp[i][1][1] = arr[i][2];

        // cout << "( " << i <<" , " << i << " ) " << dp[i][i][0][0] << " " << dp[i][i][0][1] << " " << dp[i][i][1][0] << " " << dp[i][i][1][1]  << endl;
    }

    rep(i,0,n){
        int new_dp[n][2][2];
        for(int l = 1; i+l < n;l++){
            new_dp[i][1][1] = max(dp[i][1][0]+ arr[i+l][2],dp[i][1][1] + arr[i+l][1]);
            new_dp[i][1][0] = max(dp[i][1][0]+ arr[i+l][1], dp[i][1][1] + arr[i+l][0]);
            new_dp[i][0][1] = max(dp[i][0][1]+ arr[i+l][1], dp[i][0][0] + arr[i+l][2]);
            new_dp[i][0][0] = max(dp[i][0][0]+ arr[i+l][1], dp[i][0][1] + arr[i+l][0]);

            dp[i][0][0] = new_dp[i][0][0];
            dp[i][0][1] = new_dp[i][0][1];
            dp[i][1][0] = new_dp[i][1][0];
            dp[i][1][1] = new_dp[i][1][1];
            
            // cout << "( " << i <<" , " << (i+l) << " ) " << dp[i][i+l][0][0] << " " << dp[i][i+l][0][1] << " " << dp[i][i+l][1][0] << " " << dp[i][i+l][1][1] << endl;
        }
    }

    cout << dp[0][0][0] << endl;
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
