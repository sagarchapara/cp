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

void compute(int n, vector<bool>& isPrime, vector<int>& lpf, vector<int>& primes){
    fill(isPrime.begin(), isPrime.end(), true);
    iota(lpf.begin(), lpf.end(), 0);

    isPrime[0] = isPrime[1] = false;

    primes.push_back(2);

    for(int i=4;i<n;i+=2) {
        isPrime[i] = false;
        lpf[i] = 2;
    }

    
    for(int i=3;i<n;i+=2){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j= i*i;j<n;j+=i){
                if(isPrime[j]){
                    isPrime[j] = false;
                    lpf[j] = i;
                }
            }
        }
    }
}

const int MAXN = 2e6+5;


bool isValid(int k, vi& used, vi& lpf){
    set<int> primes;
    while(k!=1){
        if(used[lpf[k]]) return false;
        primes.insert(lpf[k]);
        k/=lpf[k];
    }

    for(int p:primes){
        used[p] = true;
    }

    return true;
}

void solve() {
    int n; cin >> n;
    vi arr(n); rep(i,0,n) cin >> arr[i];

    vi lpf(MAXN), primes; vector<bool> isPrime(MAXN);
    compute(MAXN, isPrime, lpf, primes); 

    assert(primes.size() >= 1e5);

    dbg(primes.size());

    vi used(MAXN); vi b(n);

    bool first = false;

    rep(i,0,n){
        bool ok = isValid(arr[i], used, lpf);
        if(ok){
            b[i] = arr[i];
        }
        else{
            for(int j = arr[i]+1;j<MAXN;j++){
                bool vld = isValid(j, used, lpf);
                if(vld){
                    dbg(j);
                    b[i++] = j;
                    for(int k: primes){
                        if(i == n) goto good;
                        if(!used[k]){
                            b[i++] = k;
                        }
                    }
                }
            }
        }
    }

    good:
        cout << b << endl;

    return;
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
