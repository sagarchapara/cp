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

const int MAXN = 5e6+5;

int lpf[MAXN];
int prime[MAXN];

void compute(){
    fill(prime, prime+MAXN, 0);
    vector<bool> isPrime(MAXN+2, true);
    for(int i=2;i<MAXN;i++){
        if(isPrime[i]){
            lpf[i] = i;
            for(int j = i*i ;j<MAXN ; j+=i){
                if(isPrime[j]){
                    isPrime[j] = false;
                    lpf[j] =i;
                } 
            }
        }
    }

    int val =0;
    for(int i=2;i<MAXN;i++){
        int cnt =0; int curr =i;
        while(curr!=1){
            cnt++;
            curr/=lpf[curr];
        }
        prime[i] = cnt + val;
        val = prime[i];
    }

    // rep(i,1,11) dbg(prime[i]);
}

void solve() {
    int tc; cin >> tc;
    rep(i,0,tc){
        int a, b; cin >> a >> b;
        int ans = prime[a]-prime[b];
        printf("%d\n", ans);
    }
}

int32_t main() {
    #ifdef SAGAR
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    compute();

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
