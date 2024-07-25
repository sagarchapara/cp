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

void dfs(int curr, vector<vector<int>>& adjL, vector<bool>& visited, vector<int>& tpg){
    visited[curr] = true;

    for(int v: adjL[curr]){
        if(!visited[v]){
            dfs(v, adjL, visited, tpg);
        }
    }

    tpg.push_back(curr);
}


void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> adjL(n), radjL(n);

    for(int i=0;i<m;i++){
        int u, v ; cin >> u >> v; u--,v--;
        adjL[u].push_back(v);
        radjL[v].push_back(u);
    }

    vector<bool> visited(n, false);
    vector<int> tpg;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i, adjL, visited, tpg);
        }
    }

    reverse(tpg.begin(), tpg.end());
    
    visited.assign(n, false);

    vector<int> ans(n, -1);

    int num_c= 0;

    for(int i: tpg){
        if(visited[i]) continue;

        vector<int> component;
        dfs(i, radjL, visited, component);

        num_c++;

        for(int j: component){
            ans[j] = num_c;
        }
    }

    cout << num_c << endl;

    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
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
