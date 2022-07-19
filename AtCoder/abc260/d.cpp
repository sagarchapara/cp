// g++ -o out <filename>.cpp -D SAGAR
// .\out.exe

#include <bits/stdc++.h>
using namespace std;                                    

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x << endl; return os;}
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
    int n, k; cin >> n >> k;
    vi arr(n); vi idx(n);
    for(int i=0;i<n;i++){
        int x; cin >> x; x--;
        arr[i] = x;
        idx[x] = i;
    }
    set<int> s; vi ans(n,-1); vi dp(n,1); vi prev(n,-1);
    rep(i,0,n){
        dbg(s);
        auto it = s.upper_bound(arr[i]);
        dbg(i, arr[i]);
        if( it == s.end()){
            dp[i] = 1;
        } 
        else{
            int next = *it;
            dp[i] = dp[idx[next]]+1;
            prev[i] = idx[next];
            dbg(next);
            s.erase(next);
        }
        s.insert(arr[i]);
        if(dp[i] == k){
            //remove all
            int t = i;
            s.erase(arr[t]);
            while(t >= 0){
                ans[arr[t]] = (i+1);
                t = prev[t];
            }
        }
    }
    cout  << ans << endl;
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
