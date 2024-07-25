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

void print_cycle(int start, int end, vector<int> par){
    vector<int> ans;

    ans.push_back(end);

    while(start != end){
        dbg(start, par[start], end);

        ans.push_back(start);
        start = par[start];    
    }

    ans.push_back(end);

    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;

    for(int u: ans){
        cout << u+1 << " ";
    }

    cout << endl;
}

bool dfs(int u, int par, vector<vector<int>>& adjL, vector<int>& color, vector<int>& parent){
    color[u] = 1;
    parent[u] = par;

    for(int v: adjL[u]){
        if(color[v] == 0){
            if(dfs(v,u,adjL,color,parent)){
                return true;
            }
        }
        else if(color[v] == 1){
            //has a cycle
            print_cycle(u, v, parent);
            return true;
        }
    }

    color[u] = 2;

    return false;
}

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> adjL(n);

    for(int i=0;i<m;i++){
        int u,v; cin >> u >>v; u--,v--;

        adjL[u].push_back(v);
    }

    vector<int> color(n, 0);

    vector<int> parent(n, -1);

    for(int i=0;i<n;i++){
        if(color[i] == 0 && dfs(i,-1,adjL, color, parent)){
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
