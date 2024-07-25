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

void dfs(int curr, int par, int num_upper, vector<vector<int>>& adjL, vector<int>& num, vector<int>& dp){
    //first ans, can be max(num_upper and child_length + 1)

    vector<int> values, prefix_max, suffix_max;

    int max_until_now = -1;

    for(int u: adjL[curr]){
        if(u != par){
            int val = num[u];
            values.push_back(val);
            max_until_now = max(val, max_until_now);
            prefix_max.push_back(max_until_now);
        }
        else{
            prefix_max.push_back(max_until_now);
        }
    }

    int sz = adjL[curr].size();
    max_until_now = -1;

    for(int i=sz-1;i>=0;i--){
        if(adjL[curr][i] == par){
            suffix_max.push_back(max_until_now);
            continue;
        }

        int u = adjL[curr][i];

        max_until_now = max(max_until_now, num[u]);
        suffix_max.push_back(max_until_now);
    }

    reverse(suffix_max.begin(), suffix_max.end());

    assert(prefix_max.size() == adjL[curr].size());
    assert(suffix_max.size() == adjL[curr].size());

    dbg(curr, par, num_upper, max_until_now, dp[curr]);

    dp[curr] = max(num_upper, 1+max_until_now);

    for(int i=0;i<sz;i++){
        int u = adjL[curr][i];

        if(u != par){
            int val = num_upper+1;

            if(i >0){
                val = max(val, prefix_max[i-1]+2);
            }
            
            if(i<(sz-1)){
                val = max(val, suffix_max[i+1]+2);
            }

            dfs(u, curr, val, adjL, num, dp);
        }
    }
}

int get_height(int curr, int par, vector<vector<int>>& adjL, vector<int>& num){
    if(num[curr] != -1){
        return num[curr];
    }

    int ans = 0;

    for(int u: adjL[curr]){
        if(u != par){
            ans  = max(ans, 1+ get_height(u, curr, adjL, num));
        }
    }

    return num[curr] = ans;
}

void solve() {
    int n; cin >> n;

    vector<vector<int>> adjL(n);

    for(int i=0;i<(n-1);i++){
        int u,v; cin >> u >> v; u--, v--;

        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }

    vector<int> height(n, -1);

    get_height(0, -1, adjL, height);

    dbg(height);

    vector<int> dp(n,0);

    dfs(0, -1, 0, adjL, height, dp);

    for(int i=0;i<n;i++){
        cout << dp[i] << " ";
    }
    cout << endl;
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
