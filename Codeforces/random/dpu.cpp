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

vector<int> precompute_cost(int n, vector<vector<int>>& arr){
    vector<int> cost((1<<n));

    cost[0] = 0;

    for(int mask = 1; mask<(1<<n);mask++){
        int last_bit = mask & (-mask);

        int num = __builtin_ffs(last_bit) -1 ;

        int ans = 0;

        int sub_mask = (mask & (mask-1));

        for(int i=0;i<n;i++){
            if(sub_mask & (1<<i)){
                ans += arr[i][num];
            }
        }

        cost[mask] = cost[mask ^ last_bit] + ans;
    }

    return cost;
}

int dfs(int n, int curr_mask, vector<int>& dp, vector<int>& cost){

    // dbg(n, curr_mask);

    //go through all submasks of curr_maks
    if(curr_mask >= (1<<n)){
        return 0;
    }

    if(dp[curr_mask] != -1){
        return dp[curr_mask];
    }

    if(curr_mask == 0){
        return dp[curr_mask] = 0;
    }

    int ans = cost[curr_mask];

    //go through all submasks of curr_mask
    for(int s=curr_mask; s!=0; s= curr_mask&(s-1)){

        if( s == curr_mask) continue;

        int val = dfs(n,s,dp,cost) + dfs(n, curr_mask^s, dp, cost);

        ans = max(ans, val);
    }

    return dp[curr_mask] = ans;
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }

    vector<int> dp(1<<n, -1), cost(1<<n, 0);

    cost = precompute_cost(n, arr);

    // dbg(cost);

    int ans = dfs(n, (1<<n)-1, dp, cost);

    // dbg(dp);

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
