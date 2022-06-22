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

const int inf = 1e7;

void solve() {
    int n , m, x,y ; cin >> n >> m >> x >> y;
    vector<vi> arr(n,  vi(m)); vi pref(m);
    rep(i,0,n){
        string s; cin >> s;
        rep(j,0,m){
            arr[i][j] = (s[j]=='.')? 1 : 0;
            pref[j]+= arr[i][j];
        }
    }
    rep(j,1,m) pref[j]+=pref[j-1];

    // dbg(pref);
    // dbg(n); dbg(m);

    vector<vector<vi>> dp(m, vector<vi>(m, vi(2,inf)));

    vector<vi> prev_min(m, vi(2,inf));

    rep(i,m,0){
        rep(len,1, m-i+1){
            int j = i+len-1;
            if(len < x || len > y){
                dp[i][j][0] = dp[i][j][1] = inf;
            }
            else{
                int zeros = pref[j] - ((i>=1)? (pref[i-1]): 0);
                int ones = n*len - zeros;
                dp[i][j][0] = ones; 
                dp[i][j][1] = zeros;
                if(j+1<m){
                    dp[i][j][0] += prev_min[j+1][1];
                    dp[i][j][1] += prev_min[j+1][0];   
                }
                // dbg(i); dbg(j); dbg(dp[i][j][0]); dbg(dp[i][j][1]);
            }
            prev_min[i][0] = min(dp[i][j][0], prev_min[i][0]);
            prev_min[i][1] = min(dp[i][j][1], prev_min[i][1]);

            // dbg(prev_min[i][0]); dbg(prev_min[i][1]); 
        }
    }

    // rep(i,0,m){
    //     dbg(i);
    //     for(int j = x-1; j<y && (i+j< n) ;j++){
    //         cerr << (i+j)<< " " << dp[i][i+j][0]<< " " << dp[i][i+j][1];
    //     }
    //     cerr << endl;
    // }

    int ans =inf;

    rep(i,x,y+1){
        int j = min(i,m);
        ans = min(ans, dp[0][j-1][0]);
        ans = min(ans, dp[0][j-1][1]);
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
