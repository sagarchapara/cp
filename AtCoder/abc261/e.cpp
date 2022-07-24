// g++ -o out <filename>.cpp -D SAGAR
// .\out.exe

#include <bits/stdc++.h>
using namespace std;                                    

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x << " "; return os;}
void dbg_out() { cerr << "" << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << " "; dbg_out(T...); }
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

void solve() {
    int n, c; cin >> n >> c;

    vvi dp(30, vi(2));



    vi ans(n,0);

    rep(i,0,n){
        int t, a; cin >> t >> a;

        rep(b,0,30){
            int bit;
            if(i == 0) bit = ((c& (1<<b))>0) ? 1 : 0;
            else bit = (((1<<b)&ans[i-1])>0) ? 1 : 0; 
            
            int prev = (i == 0)? bit : dp[b][bit];
            
            int cb =  ((a & (1<<b)) > 0) ? 1 : 0;
            int curr;
            if(t == 1){
                curr = prev & cb;
                if(i == 0){
                    dp[b][1] = cb & 1;
                    dp[b][0] = cb & 0;
                }
                else {
                    dp[b][1] = dp[b][1] & cb;
                    dp[b][0] = dp[b][0] & cb;
                }
            }
            else if(t == 2){
                curr = prev | cb;
                if(i == 0){
                    dp[b][1] = cb | 1;
                    dp[b][0] = cb | 0;
                }
                else {
                    dp[b][1] = dp[b][1] | cb;
                    dp[b][0] = dp[b][0] | cb;
                }
            }
            else {
                curr = prev ^ cb;
                if(i == 0){
                    dp[b][1] = cb ^ 1;
                    dp[b][0] = cb ^ 0;
                }
                else {
                    dp[b][1] = dp[b][1] ^ cb;
                    dp[b][0] = dp[b][0] ^ cb;
                }
            }
            if(curr == 1){
                // dbg(b);
                ans[i]+= (1<<b);
            }
        }

        cout << ans[i] << endl;
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
