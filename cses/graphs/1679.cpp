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

bool dfs(int curr, vector<vector<int>>& adjL, vector<int>& color, vector<int>& ans){
    color[curr] = 1;

    for(int u: adjL[curr]){
        if(color[u] == 0){
            if(dfs(u, adjL, color, ans)){
                return true;
            }
        }
        else if(color[u] == 1){
            return true; //cycle
        }
    }

    color[curr] = 2;
    ans.push_back(curr);

    return false;
}

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> adjL(n);

    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b; a--, b--;

        adjL[a].push_back(b);
    }

    vector<int> ans;
    vector<int> color(n);

    for(int i=0;i<n;i++){
        if(color[i]==0 && dfs(i, adjL, color, ans)){
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    reverse(ans.begin(), ans.end());

    for(int i: ans){
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
