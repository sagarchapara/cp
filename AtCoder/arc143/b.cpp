// g++ -o out <filename>.cpp
// .\out.exe

#define SAGAR

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

const int MAXN = 250000+5;
int MOD = 998244353;
int fact[MAXN];
int inv[MAXN];

int ncr(int n, int r){
    int ans = (inv[r]*inv[n-r])%MOD;
    ans = (ans*fact[n])%MOD;
    return ans;
}

void compute(){
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
        // dbg(fact[i]);
    }
        
}

void solve() {
    int n; cin >> n;
    int ans = 1;

    memset(fact, 1, MAXN);
    compute();

    ans = (fact[n*n])%MOD;
    int temp = (2*fact[n*(n-1)])%MOD;
    temp = (temp*fact[n])%MOD;
    temp =(temp*n)%MOD;

    ans = (ans - temp + MOD)%MOD;
    ans = ans%MOD;

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
