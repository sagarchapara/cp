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

const int MAXN = 60;
int lp[MAXN];
vi primes;

void getPrimes(){
    vector<char> isPrime(MAXN, true);
    for(int i=2;i<MAXN;i++){
        if(isPrime[i]){
            lp[i] =i;
            primes.push_back(i);
            for(int j=i*i ; j<MAXN; j+=i){
                if(isPrime[j]){
                    isPrime[j] = false;
                    lp[j] =i;
                }
            }
        }
    }
}


void solve() {
    int n; cin >> n;
    vi arr(n); for(int &x: arr) cin >> x;
    // dbg(arr);
    getPrimes();

    // dbg(primes);

    int nbits = primes.size()-1;
    map<int,int> pPos;
    rep(i,0,nbits){
        pPos[primes[i]] = i;
    }

    vector<vi> dp(n, vi((1<<nbits),100));

    rep(i,0,n){
        for(int j =0;j<(1<<nbits);j++){
            for(int k = 1;k<59;k++){
                //find mask of k
                if(k==1){
                    int sum = abs(arr[i]-1);
                    if(i>0){
                        sum+=dp[i-1][j];
                    }
                    dp[i][j] = min(dp[i][j], sum);
                }
                else{
                    int mask =0; int curr =k;
                    while(curr!=1){
                        mask|= (1<<(pPos[lp[curr]]));
                        curr/=lp[curr];
                    }
                    if((j & mask) == mask){
                        if(i==0){
                            if(j==mask){
                                dp[i][j] = min(abs(arr[i]-k), dp[i][j]);
                            }
                        }
                        else{
                            int sum =0;
                            sum += abs(arr[i]- k);
                            sum+= dp[i-1][j^mask];
                            dp[i][j] = min(sum, dp[i][j]);
                        }
                    }
                }
            }
        }
    }

    // dbg("HI");

    vi ans;

    int minVal = dp[n-1][0], idx = 0;
    for(int j=0;j<(1<<nbits);j++){
        if(dp[n-1][j] < minVal){
            minVal = dp[n-1][j];
            idx = j;
        }
    }

    rep(i,n,0){
        for(int k=1;k<59;k++){
            int val = abs(arr[i]-k);
            int mask =0; int curr = k;
            while(curr!=1){
                mask|= (1<<pPos[lp[curr]]);
                curr/=lp[curr];
            }
            if((idx & mask) != mask){
                continue;
            }
            if(i>0){
                val+= dp[i-1][idx^mask];
            }
            if(val == minVal){
                ans.push_back(k);
                // dbg(k);
                if(i>0){
                    minVal = dp[i-1][idx^mask];
                    idx = idx^mask;
                }
                break;
            }
        }
    }

    reverse(all(ans));

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
