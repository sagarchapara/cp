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

class BinomialCoefficient{
    int n, p;
    vector<int> fact, invf;


    int power(int a, int b)
    {
        int res = 1;
        a %= p;
        while (b > 0) 
        {
            if (b & 1)
                res = (res * a) % p;
            a = (a * a) % p;
            b >>= 1;
        }
        return res;
    }

    int modinv(int k)
    {
        return power(k, p-2);
    }

    void compute(){
        fact[0] = 1;
        for(int i=1;i<n;i++) fact[i] = (i*fact[i-1])%p;

        invf[n-1] = modinv(fact[n-1]);
        for(int i=n-2;i>=0;i--){
            invf[i] = (i+1)*(invf[i+1]);
            invf[i]%=p;
        }   
    }

public:

    BinomialCoefficient(int _n, int _p): n(_n), p(_p){
        fact.resize(n), invf.resize(n);
        compute();
    }

    inline int ncr(int l, int r){

        if (l < r || r < 0 || l < 0) return 0;

        int ans = (((fact[l]*invf[r])%p)*invf[l-r])%p;
        return ans;
    } 
};

const int MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vi arr(n+1); rep(i,0,n+1) cin >> arr[i];

    BinomialCoefficient bc(5e5,MOD);

    int ans =0;

    for(int i =0;i<(n+1);i++){
        if(arr[i] == 0) break;
        int p = bc.ncr(arr[i]+i, i+1);
        ans = (ans + p)%MOD;
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
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
