// g++ -o out <filename>.cpp -D SAGAR
// .\out.exe

#include <bits/stdc++.h>
using namespace std;                                    

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x << " "; return os;}
void dbg_out() { cerr << "" << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << " " ; dbg_out(T...); }
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

const int MOD = 1e9+7;

map<int, int> get_prime_factors(int n){
    int maxn = n;

    vector<bool> isPrime(n+1, true);

    isPrime[0] = isPrime[1] = false;
    for(int i=4;i<=n;i+=2){
        isPrime[i] = false;
    }

    for(int i =3;i<n;i++){
        if(isPrime[i]){
            for(int j = i*i;j<=n;j+=i){
                isPrime[j] = false;
            }
        }
    }

    int num = 0;

    map<int, int> primes;

    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            primes[num] = i;
            num++;
        }
    }

    dbg(primes);

    return primes;
}

int get_mask(int i, map<int, int>& primes){
    int val = 0;
    for(auto& [k, v]: primes){
        int cnt = 0;

        while(i%v == 0){
            cnt++;
            i/=v;
        }

        val += (cnt%2)*(1<<k);
    }

    return val;
}

int twopower(int n){

    if(n <= 0){
        return 0;
    }

    int ans =1;

    int val = 2;
    while(n!=0){
        if(n & 1){
            ans  = (ans * val)%MOD; 
        }
        val = (val * val)%MOD;
        n>>=1;
    }

    return ans;
}

void solve() {
    int n; cin >> n;

    vector<int> arr(70, 0);

    for(int i=0;i<n;i++){
        int val; cin >> val;
        arr[val-1]++;
    }

    auto primes = get_prime_factors(70);

    n = primes.size();

    vector<vector<int>> dp(70, vector<int>(1<<n, 0));

    dbg(n);

    for(int i=0;i<70;i++){
        int prime_mask = get_mask(i+1, primes);
        for(int mask =0;mask<(1<<n);mask++){
            if(i == 0){
                if(arr[i]){
                    if(mask == 0){
                        dp[i][mask] = (dp[i][mask] + twopower(arr[i])-1)%MOD;
                    }
                }
            }
            else{
                if(arr[i]){
                    if(mask == 0){
                        
                    }
                    else{
                        dp[i][mask] = (dp[i-1][mask] + dp[i-1][mask ^ prime_mask])%MOD;

                        dp[i][mask] = (dp[i][mask] * twopower(arr[i]-1))%MOD;
                    }
                }
                else{
                    dp[i][mask] = dp[i-1][mask];
                }
            }
        }
    }

    cout << dp[69][0] << endl;
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
