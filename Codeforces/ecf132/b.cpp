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
    int n, m; cin >> n >> m;
    vi arr(n); for(int &x: arr) cin >> x;

    vi pref(n,0), suff(n,0);
    rep(i,1,n){
        if(arr[i]<arr[i-1]){
            pref[i] = arr[i-1]-arr[i];
        }
        pref[i]+=pref[i-1];
    }
    rep(i,n-1,0){
        if(arr[i+1] > arr[i]){
            suff[i] = arr[i+1]-arr[i];
        }
        suff[i]+=suff[i+1];
    }

    // dbg(pref); dbg(suff);

    rep(i,0,m){
        int l,r; cin >> l >> r; l--, r--;
        int ans;
        if(l<=r){
            ans = pref[r] - pref[l];
        }
        else{
            ans = suff[r] - suff[l];
        }
        cout << ans << endl;
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
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
