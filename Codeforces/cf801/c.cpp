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
#define pii pair<pi,int>
#define vi vector<int>
#define vvi vector<vi>
#define vpi vector<pi>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define sz(x) (int)(x).size()

void solve() {
    int n, m; cin >> n >> m;
    vector<vi> arr(n, vi(m));
    rep(i,0,n){
        rep(j,0,m) cin >> arr[i][j];
    }

    if((n+m-1)%2 == 1){
        cout << "NO\n";
        return;
    }

    vvi dp1(n, vi(m, n+m));
    vvi dp2(n, vi(m, -1*(n+m)));

    rep(i,n,0){
        rep(j,m,0){
            if(i == n-1 && j == m-1){
                dp1[i][j] = arr[i][j];
                dp2[i][j] = arr[i][j];
            }
            else{
                if(i+1<n){
                    dp1[i][j] = min(dp1[i+1][j], dp1[i][j]);
                    dp2[i][j] = max(dp2[i+1][j], dp2[i][j]);
                }
                if(j+1<m){
                    dp1[i][j] = min(dp1[i][j+1], dp1[i][j]);
                    dp2[i][j] = max(dp2[i][j+1], dp2[i][j]);
                }
                dp1[i][j]+=arr[i][j];
                dp2[i][j]+=arr[i][j];
            }
        }
    }



    if(dp1[0][0] <= 0 && dp2[0][0] >=0 ){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
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

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
