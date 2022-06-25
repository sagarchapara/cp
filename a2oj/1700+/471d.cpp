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
    int n, w; cin >> n >> w;
    if(n< w){
        cout << -1;
        return ;
    }
    vi arr(n+w+1); arr[w] = 0;
    rep(i,0,n) cin >> arr[i+w+1];
    rep(i,0,w) cin >> arr[i];

    // dbg(arr);

    int len = n+w+1;
    vi z(len,0);

    for(int i=1, l= 0, r =0; i< len ;i++){
        if(i<=r){
            z[i] = min(z[i-l], r-i+1);
        }
        while(i+z[i]< len && z[i]<=w && (arr[i+z[i]]-arr[z[i]])==(arr[i]-arr[0])){
            ++z[i];
        }
        if (i + z[i] - 1 > r){
            l = i, r = i + z[i] - 1;
        }
    }
    // dbg(z);
    int ans =0;
    for(int i =w+1;i<len ;i++){
        if(z[i]==w){
            ++ans;
        }
    }    

    cout << ans <<'\n';
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
