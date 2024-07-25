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

void dfs(int curr, int par, int sum, int num, vector<vector<int>>& adjL, vector<pair<int,int>>& sz, vector<int>& dp){
    int subtree_sum = 0;

    dp[curr] = (sum + num) + sz[curr].first;

    for(int u: adjL[curr]){
        if(u == par) continue;

        int new_num = num + sz[curr].second - sz[u].second;
        int new_sum = dp[curr] - (sz[u].first + sz[u].second);

        dfs(u, curr, new_sum, new_num, adjL, sz, dp);
    }
}


pair<int, int> get_size(int curr, int par, vector<vector<int>>& adjL, vector<pair<int,int>>& sz){
    pair<int,int> ans = {0, 1};

    for(int u: adjL[curr]){
        if(u != par){
            auto val = get_size(u, curr, adjL, sz);
            ans = {ans.first + val.first+val.second, ans.second + val.second};
        }
    }

    return sz[curr] = ans;
}


void solve() {
    int n; cin >> n;

    vector<vector<int>> adjL(n);

    for(int i=0;i<(n-1);i++){
        int a,b; cin >> a >> b; a--, b--;

        adjL[a].push_back(b);
        adjL[b].push_back(a);
    }

    vector<pair<int,int>> sz(n);

    get_size(0, -1, adjL, sz);

    vector<int> dp(n);

    dfs(0, -1, 0, 0, adjL, sz, dp);

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
