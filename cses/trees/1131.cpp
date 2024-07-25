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

int dfs(int curr, int par, vector<vector<int>>& adjL, vector<int>& dp, int& ans){
    if(dp[curr] != -1){
        return dp[curr];
    }
    
    int first_max = -1;
    int second_max = -1;


    for(int u: adjL[curr]){
        if(u!=par){
            int next = dfs(u, curr, adjL, dp, ans);

            if(next >= first_max){
                second_max = first_max;
                first_max = next;
            }
            else if(next > second_max){
                second_max = next;
            }
        }
    }

    ans  = max(ans, 1 + first_max + 1 + second_max);

    dbg(curr, par, ans, first_max, second_max);

    return dp[curr] = 1 + first_max;
}

void solve() {
    int n; cin >> n;

    vector<vector<int>> adjL(n);

    for(int i=0;i<(n-1);i++){
        int u,v; cin >> u >> v; u--, v--;

        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }

    int ans = 0;

    vector<int> dp(n, -1);

    dfs(0, -1, adjL, dp, ans);

    dbg(dp);

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
