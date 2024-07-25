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

void dfs(int curr, int par, int par_size, vector<vector<int>>& adjL, vector<int>& sz, vector<bool>& centroid){
    bool isCentroid = par_size <= sz.size()/2;

    int sub_array_size = sz[curr];

    for(int u: adjL[curr]){
        if(u == par) continue;

        isCentroid &= (sz[u] <= sz.size()/2);

        int val = par_size + sub_array_size - sz[u];

        dfs(u, curr, val, adjL, sz, centroid);
    }

    centroid[curr] = isCentroid;
}

int compute_size(int curr, int par, vector<vector<int>>& adjL, vector<int>& sz){
    int ans = 1;

    for(int u: adjL[curr]){
        if(u!=par){
            ans += compute_size(u, curr, adjL, sz);
        }
    }    

    return sz[curr] = ans;
}

void solve() {
    int n; cin >> n;

    vector<vector<int>> adjL(n);

    for(int i=1;i<n;i++){
        int u,v; cin >> u >> v; u--, v--;
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }

    vector<int> size(n);

    compute_size(0, -1, adjL, size);

    dbg(size);

    vector<bool> is_centroid(n, false);

    dfs(0, -1, 0, adjL, size, is_centroid);

    dbg(is_centroid);

    for(int i=0;i<n;i++){
        if(is_centroid[i]){
            cout << (i+1) << endl;
            return;
        }
    }

    cout << "IMPOSSIBLE" << endl;
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
