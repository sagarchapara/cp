// g++ -o out <filename>.cpp
// .\out.exe

#define SAGAR

#include <bits/stdc++.h>
using namespace std;                                    

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x << " " <<endl; return os;}
void dbg_out() { cerr << "" ; }
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
#define vvpi vector<vector<pi>>
#define all(x) (x).begin(), (x).end()
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define sz(x) (int)(x).size()


void solve() {
    int n ; cin >> n;
    vi arr(n); map<int,set<int>> pos; 

    rep(i,0,n){
        cin >> arr[i];
        pos[arr[i]].insert(i);
    }

    int dp[n][n] = {};

    int ans = 1;

    rep(i,n,0){
        for(int l=2;i+l-1<n;l++){
            //find arr[i] after i+l-1;
            int j = i+l-1;
            auto it = pos[arr[i]].upper_bound(j);
            if(it != pos[arr[i]].end()){
                dp[i][j] = 1 + dp[j][*it];
            }
            else{
                dp[i][j] = 2;
            }
            ans = max( ans, dp[i][j]);
        }
    }

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
