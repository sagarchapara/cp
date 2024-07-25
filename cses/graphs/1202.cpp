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

const int MOD = 1e9 +7;

struct Edge{
    int val;
    int num_ways;
    int min_roads;
    int max_roads;

    Edge(){
        val = -1, num_ways = -1, min_roads = -1, max_roads = -1;
    }

    Edge(int _val, int _num_ways, int _min_roads, int _max_roads): val(_val), num_ways(_num_ways), min_roads(_min_roads), max_roads(_max_roads){}

    friend ostream& operator<<(ostream& os, const Edge& e) {
        os << e.val << " " << e.num_ways << " " << e.min_roads << " " << e.max_roads;
        return os;
    }
};

Edge djistra(int n, int u, vector<vector<pair<int, int>>>& adjL){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<Edge> d(n);

    vector<bool> visited(n, false);

    d[0] = Edge(0, 1, 0, 0);

    pq.push({0, 0});

    while(!pq.empty()){
        auto p  = pq.top(); pq.pop();

        if(visited[p.second]){
            continue;
        }

        visited[p.second] = true;

        for(auto& np: adjL[p.second]){
            //update the dist and push
            int v = np.first;
            int w = np.second;

            int price = d[p.second].val + w;

            if(d[v].num_ways == -1 || d[v].val > price){
                d[v] = Edge(price, d[p.second].num_ways, d[p.second].min_roads+1, d[p.second].max_roads+1);

                pq.push({price, v});
            }
            else if(d[v].val == price){
                d[v] = Edge(price, (d[p.second].num_ways + d[v].num_ways)%MOD, min(d[p.second].min_roads+1, d[v].min_roads), max(d[p.second].max_roads+1, d[v].max_roads));
            }
        }
    }

    return d[n-1];
}

void solve() {
    int n,m; cin >> n >> m;

    vector<vector<pair<int,int>>> adjL(n);

    for(int i=0;i<m;i++){
        int u, v, w; cin >> u >> v >> w; u--, v--;

        adjL[u].push_back({v, w});
    }

    // dbg(adjL);

    vector<Edge> dp(n);

    vector<int> color(n, 0);

    dp[n-1] = Edge(0, 1, 0, 0);
    color[n-1] = 2;

    Edge ans = djistra(n, 0, adjL);

    // dbg(dp);

    cout << ans.val << " " << ans.num_ways << " " << ans.min_roads << " " << ans.max_roads << endl;
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
