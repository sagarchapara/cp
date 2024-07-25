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

void dfs(int u, vector<vector<int>>& adjL, vector<bool>& visited, vector<int>& component){
    visited[u] = true;

    for(int v: adjL[u]){
        if(!visited[v]){
            dfs(v, adjL, visited, component);
        }
    }

    component.push_back(u);
}

int dfs2(int curr, vector<vector<int>>& adjL, vector<int>& dp, vector<int>& arr){
    if(dp[curr] != -1){
        return dp[curr];
    }

    int ans = 0;

    for(int u: adjL[curr]){
        ans = max(ans, dfs2(u, adjL, dp, arr));
    }

    return dp[curr] = ans + arr[curr];
}

void solve() {
    int n, m; cin >> n >> m;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    vector<vector<int>> adjL(n), radjL(n);

    for(int i=0;i<m;i++){
        int u, v; cin >> u >> v; u--, v--;
        adjL[u].push_back(v);
        radjL[v].push_back(u);
    }

    dbg(adjL, radjL);

    vector<int> tpg;
    vector<bool> visited(n, false);

    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i, adjL, visited, tpg);
        }
    }

    reverse(tpg.begin(), tpg.end());

    visited.assign(n, false);

    int num =0;
    vector<int> values, cmap(n);

    for(int i: tpg){
        if(!visited[i]){
            vector<int> component;
            int val = 0;

            dfs(i, radjL, visited, component);

            for(int j: component){
                cmap[j] = num;
                val += arr[j];
            }

            dbg(component);

            values.push_back(val);
            num++;
        }
    }

    assert(num == values.size());

    //create new adj list
    int new_n = values.size();

    vector<vector<int>> nadjL(new_n);

    dbg(cmap);

    for(int i=0;i<n;i++){
        for(int j: adjL[i]){
            if(cmap[i] != cmap[j]){
                nadjL[cmap[i]].push_back(cmap[j]);
            }
        }
    }

    dbg(nadjL);
    dbg(values);

    int ans =0;
    vector<int> dp(new_n, -1);

    for(int i=0;i<new_n;i++){
        if(dp[i] == -1){
            dfs2(i,nadjL,dp,values);
        }
        ans = max(ans, dp[i]);
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
