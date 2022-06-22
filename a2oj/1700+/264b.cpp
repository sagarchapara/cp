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
#define rall(x) (x).rbegin(), (x).rend()
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define sz(x) (int)(x).size()

const int MAXN = 1e5+5;

int primes[MAXN];

void getPrimes(){
    vector<char> is_prime(MAXN, true);
    is_prime[2] = true;
    primes[2] = 2;
    for(int i=4;i<MAXN;i+=2){
        is_prime[i] = false;
        primes[i] = 2;
    }
    for (int i = 3; i< MAXN; i+=2) {
        if (is_prime[i]) {
            primes[i] =i;
            for (int j = i * i; j <= MAXN; j += i){
                if(is_prime[j]){
                    is_prime[j] = false;
                    primes[j] =i;
                }  
            }
        }
    }
}


void solve() {
    int n; cin >> n;
    vi arr(n); for(int &x: arr) cin >> x;
    getPrimes();

    vi max_len(MAXN,0);
    int ans =1;
    
    rep(i,n,0){
        int num = 1;

        if(arr[i]==1){
            continue;
        }
        int curr = arr[i];
        set<int> curr_primes;
        while(curr != 1){
            curr_primes.insert(primes[curr]);
            num = max(num, 1+max_len[primes[curr]]);
            curr/= primes[curr];
        
            // dbg(curr); dbg(primes[curr]);
            // dbg(num); dbg(max_len[primes[curr]]);
        }

        for(int p: curr_primes){
            // dbg(p);
            max_len[p] = max(max_len[p], num);
            ans = max(ans ,max_len[p]);
            // dbg(max_len[p]);
        }   
    }

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
