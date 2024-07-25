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

void dfs(int curr, vector<vector<int>>& adjL, vector<int>& path){
    while(!adjL[curr].empty()){
        auto next = adjL[curr].back();
        adjL[curr].pop_back();

        dfs(next, adjL, path);
    }

    path.push_back(curr);
}

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> adjL(n);

    vector<int> out(n,0), in(n,0);

    for(int i=0;i<m;i++){
        int a, b; cin >> a >> b; a--, b--;
        out[a]++;
        in[b]++;
        adjL[a].push_back(b);
    }

    bool flag = true;

    for(int i=1;i<(n-1);i++){
        if(out[i] != in[i]){
            flag = false;
            break;
        }
    }

    if(out[0] != (in[0]+1) || (out[n-1] != (in[n-1]-1)) || !flag){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vector<int> path;

    dfs(0, adjL, path);

    dbg(path);

    reverse(path.begin(), path.end());

    if(path.size() != (m+1) || path.back() != n-1){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for(int i: path){
        cout << (i+1) << " ";
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
