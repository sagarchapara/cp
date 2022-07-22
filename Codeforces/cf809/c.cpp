// g++ -o out <filename>.cpp -D SAGAR
// .\out.exe

#include <bits/stdc++.h>
using namespace std;                                    

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x << " "; return os;}
void dbg_out() { cerr << "" << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H ; dbg_out(T...); }
#ifdef SAGAR
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define pi pair<int,int>
#define vi vector<int>
#define vpi vector<pi>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vi arr(n); for(int &x: arr) cin >> x;
    int k =0; int ans;
    for(int i=1;i<n-1;i+=2){
        int t = max(arr[i-1], arr[i+1]);
        if(t < arr[i]){
                continue;
        }
        k+= (t-arr[i]+1);
    }
    ans =k; 
    // dbg(ans);
    if(n%2 == 0){
        int dp[n][2]  = {};
        for(int i=n-2;i>=0;i--){
            int t = max(arr[i-1], arr[i+1]);
            if(t < arr[i]){
                k =0;
            }
            else {
                k = t - arr[i]+1;
            }

            dp[i][0] = dp[i][1] =k;
            if(i+2 < (n-1)){
                dp[i][0] = k + dp[i+2][0];
                dp[i][1] = k + dp[i+2][1];
            }
            if(i+3 < (n-1)){
                dp[i][1] = min(dp[i][1], k + dp[i+3][0]);
            }

        }
        // dbg(dp);
        ans = min(dp[1][1], ans);
        ans = min(dp[2][0], ans);
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
