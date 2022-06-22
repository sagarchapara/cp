// g++ -o out <filename>.cpp
// .\out.exe

// #define SAGAR

#include <bits/stdc++.h>
using namespace std;                                    

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x; return os;}
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

const int inf = 1e12;
void solve() {
    int n , k; cin >> n >> k;
    string s; cin >> s;
    vector<vi> dp(n, vi(k));
    rep(i,0,n){
        int c = s[i]-'A';
        rep(j,0,k){
            int val = (c==j)? 0 : 1;
            if(i==0){
                dp[i][j] = val;
            }
            else{
                dp[i][j] = inf;
                rep(kk,0,k){
                    if(kk!=j){
                        dp[i][j] = min(dp[i][j], dp[i-1][kk]+val);
                    }
                }
            }
        }
    }

    int ans = inf; int prev;
    rep(i,0,k){
        if(ans > dp[n-1][i]){
            ans = dp[n-1][i];
            prev = i;
        }
    }

    cout << ans << endl;

    vector<char> ap; ap.push_back((prev+'A'));

    rep(i,n-1,0){
        int minp = inf;
        int curr_prev;
        rep(j,0,k){
            if(j!=prev){
                if(minp > dp[i][j]){
                    minp = dp[i][j];
                    curr_prev = j;
                }
            }
        }
        ap.push_back((curr_prev+'A'));
        prev = curr_prev;
    }
    // dbg(ap);
    reverse(all(ap));
    // dbg(ap);

    cout << ap << endl;
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
