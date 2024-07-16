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

const int MOD = 1e9 + 7;

void generate_masks(int n, int curr, int curr_mask, int next_mask, vector<int>& masks){

    // dbg(curr, curr_mask, next_mask);

    if(curr == n){
        if(curr_mask == ((1<<n)-1)){
            masks.push_back(next_mask);
        }
        return;
    }

    if((curr_mask & (1<<curr)) != 0){
        generate_masks(n, curr+1, curr_mask, next_mask, masks);
        return;
    }
    
    if((curr + 1 < n) && (((curr_mask & (1<<(curr+1))) == 0))){
        generate_masks(n, curr+2, curr_mask + (1<<curr) + (1<<(curr+1)), next_mask, masks);
    }

    generate_masks(n, curr+1, (curr_mask + (1<<curr)),(next_mask + (1<<(curr))), masks);
}


int dfs(int n, int m, int curr, int mask, vector<vector<int>>& dp){

    // dbg(curr, mask);

    if(curr > m){
        return 0;
    }

    if(dp[curr][mask] != -1){
        return dp[curr][mask];
    }

    //base case
    if(curr == m){
        if(mask == 0){
            return dp[curr][mask] = 1;
        }
        else{
            return dp[curr][mask] = 0;
        }   
    }

    if(mask == ((1<<n)-1)){
        return dp[curr][mask] = dfs(n, m, curr+1, 0, dp);
    }

    int ans = 0;

    vector<int> next_masks;

    generate_masks(n, 0, mask, 0, next_masks);

    // dbg(next_masks);

    for(int next_mask: next_masks){
        ans = (ans + dfs(n, m, curr+1, next_mask, dp))%MOD;
    }

    // //go and find first element in curr with not zero
    // int last_unset = (~mask1) & (mask1 + 1);
    // int prev_unset = (last_unset << 1);
    
    // //check if we can lay vertically
    // if((prev_unset < (1<<n)) && (mask1 & prev_unset) == 0){
    //     int nmask1 =  mask1 | last_unset;
    //     nmask1 |= prev_unset;
    //     ans= (ans + dfs(n, m, curr, nmask1, mask2, dp))%MOD;
    // }

    // //check if we can lay horizontally
    // if((mask2 & last_unset) == 0){
    //     int nmask1 = (mask1 | last_unset);
    //     int nmask2 = (mask2 | last_unset);
    //     ans= (ans + dfs(n, m, curr, nmask1, nmask2, dp))%MOD;
    // }
    

    // dbg("here");

    return dp[curr][mask] = ans;
}

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> dp(m+1, vector<int>((1<<n), -1));

    int ans = dfs(n, m, 0, 0, dp);

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
