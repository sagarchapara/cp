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


int pow(int a, int b, int k){
    int ans = 1;

    while (b != 0)
    {
        if(b&1){
            ans = (ans * a)%k;
        }
        a = (a * a)%k;
        b >>=1;
    }

    return (ans%k);
    
}

// vector<vector<int>> get_suffix_good(int n, int k, int m){
//     vector<vector<int>> dp(n, vector<int>(k, 0)); //number of prefixes with suffix divisible by k

//     for(int i =n-1;i>=0;i--){
//         for(int j =0;j<k;j++){
//             for(int d =0;d<10;d++){
//                 if(i == 0 && d == 0) continue;

//                 int rem = pow(10, n-1-i, k); 
//                 rem = (rem * d)%k;

//                 if(i == n-1){
//                     if(rem == j){
//                         dp[i][j] = (dp[i][j] + 1)%m;
//                     }
//                 }
//                 else{
//                     if(rem == j && dp[i+1][j] == 0){

//                     }
//                 }

//                 if(i < n-1){
//                     dp[i][j] =  (dp[i][j] + dp[i+1][(j-rem+k)%k])%m;
//                 }

//                 dbg(i, j, d, rem, dp[i][j]);
//             }
//         }
//     }

//     dbg(dp);

//     return dp;
// }

int dfs(int idx, int rem, bool change){
    if(rem == )
}

void solve() {
    int n, k, m; cin >> n >> k >> m;

    vector<vector<int>> dp(n, vector<int>(k, 0)); //number of suffix divisible by k
 
    //number of prefixes with suffix divisible by k
    auto pref_dp = get_suffix_good(n, k, m);

    // for(int i=0;i>=0;i--){
    //     for(int j=0;j<k;j++){
    //         for(int d=0;d<=9;d++){
    //             if(i == n-1){
    //                 if(d%k == j){
    //                     dp[i][j] = (dp[i][j] + 1)%m;
    //                 }
    //             }
    //             else{
    //                 int rem = pow(10, n-i); //10^n-1
    //                 rem = (rem * d)%k; //d * 
    //                 rem = ( j + k - rem) %k; 
    //                 dp[i][j] = (dp[i][j] + dp[i+1][rem])%m;
    //             }
    //         }
    //     }
    // }

    // int ans = 0;

    // int pref_multiple = 1;

    // //now what
    // for(int i=0;i<n;i++){
    //     //suffix including i is divisible by k
    //     int val = dp[i][0];

    //     if(i > 0){
    //         val = (val * ((pref_multiple - dp[i-1][0] + m)%m))%m;
    //     }

    //     ans = (ans + val)%m;

    //     //update pref_multiple
    //     if(i == 0){
    //         pref_multiple = (pref_multiple * 9)%m;
    //     }
    //     else{
    //         pref_multiple = (pref_multiple * 10)%m;
    //     }
    // }

    cout << pref_dp[0][0] << endl;
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
