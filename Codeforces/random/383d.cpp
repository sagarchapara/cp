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

class SegmentTree{
    int n;
    vector<int> t;

    void update(int v, int tl, int tr, int idx, int val){
        if(tl == tr){
            t[idx]+=val;
            return;
        }
        int mid = (tl+tr)/2;

        if(mid <= idx){
            update(2*v, tl, mid, idx, val);
        }
        else{
            update(2*v+1, mid+1, tr, idx, val);
        }

        t[v] = t[2*v] + t[2*v+1];
    }

    int get(int v, int tl, int tr, int l, int r){
        if(l > r){
            return 0;
        }

        if(l == tl && r == tr){
            return t[v];
        }

        int mid = (tl+tr)/2;

        return get(2*v, l, mid, l, min(r, mid)) + get(2*v+1, mid+1, r, max(l, mid+1), r);
    }

public:

    SegmentTree(int _n): n(_n){
        t.resize(4*n, 0);
    }

    void update(int idx, int val){
        update(1, 0, n-1, idx, val);
    }

    int get(int l, int r){
        return get(1,0,n-1,l, r);
    }
};

// void solve() {
//     const int MOD = 1e9+7;

//     int n; cin >> n;
//     vector<int> arr(n);

//     int max_sum = 0;

//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//         arr[i] = abs(arr[i]);
//         max_sum += arr[i];
//     }

//     vector<int> prefix_cnt(2*max_sum+1, 0);

//     vector<int> possible_sum(2*max_sum+1, 0);

//     possible_sum[max_sum] = 1;

//     int ans =0;

//     for(int i=0;i<n;i++){
//         vector<int> temp(2*max_sum+1, 0);

//         //now go through sum vector and mark temp
//         for(int j=0;j<=2*max_sum;j++){
//             if(possible_sum[j]){
//                 temp[j-arr[i]]+=1;
//                 temp[j+arr[i]]+=1;
//             }
//         }

//         dbg(i, temp);

//         possible_sum = temp;

//         //now go throgh each sum and check the count
//         for(int j =0; j<=2*max_sum;j++){
//             if(possible_sum[j] > 0){
//                 int val = (prefix_cnt[j] * possible_sum[j])%MOD;
//                 ans = (ans + val)%MOD;
//             }

//             prefix_cnt[j] += possible_sum[j];
//         }

//         dbg(i, prefix_cnt);
//     }

//     cout << ans << endl;
// }

void solve(){
    const int MOD = 1e9+7;

    int n; cin >> n;

    vector<int> arr(n);

    int max_sum =0;

    for(int i=0;i<n;i++){
        cin >> arr[i];
        arr[i] = abs(arr[i]);

        max_sum+=arr[i];
    }

    //let's say dp[i][sum] -> num ending at i with sum
    vector<vector<int>> dp(n, vector<int>(2*max_sum+1, 0));

    dp[0][max_sum-arr[0]] = 1;
    dp[0][max_sum+arr[0]] = 1;

    int ans= dp[0][max_sum];

    for(int i=1;i<n;i++){
        for(int sum=0;sum<=2*max_sum;sum++){ 
            dp[i][sum] = 0;

            if(sum-arr[i]>=0){
                dp[i][sum] = (dp[i][sum] + dp[i-1][sum-arr[i]])%MOD;
            }

            if(sum+arr[i] <= 2*max_sum){
                dp[i][sum] = (dp[i][sum] + dp[i-1][sum+arr[i]])%MOD;
            }

            if(sum == max_sum - arr[i]){
                dp[i][sum] = (dp[i][sum] + 1)%MOD;
            }

            if(sum == max_sum + arr[i]){
                dp[i][sum] = (dp[i][sum] + 1)%MOD;
            }
        }

        ans = (ans + dp[i][max_sum])%MOD;
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
