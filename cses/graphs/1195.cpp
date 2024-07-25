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

vector<int> dijistra(int x, vector<vector<pair<int, int>>>& adjL){
    int n = adjL.size();

    vector<int> d(n, -1);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, x});

    while (!pq.empty())
    {
        auto p = pq.top(); pq.pop();

        if(d[p.second] != -1){
            continue;
        }

        d[p.second] = p.first;

        for(auto np: adjL[p.second]){
            if(d[np.first] == -1){
                pq.push({p.first + np.second, np.first});
            }
        }
    }

    return d;
}

struct Edge{
    int l;
    int r;
    int cost;

    Edge(int _l, int _r, int _cost): l(_l), r(_r), cost(_cost){}
};

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<pair<int,int>>> adjL(n), radjL(n);

    vector<Edge> edges;

    for(int i=0;i<m;i++){
        int a,b,c; cin >> a >> b >> c; a--, b--;

        adjL[a].push_back({b,c});

        radjL[b].push_back({a,c});

        edges.emplace_back(a,b,c);
    }

    vector<int> front = dijistra(0, adjL);
    vector<int> back = dijistra(n-1, radjL);

    //dbg(front);
    //dbg(back);

    int ans = front[n-1];

    for(Edge& e : edges){
        if(front[e.l] == -1 || back[e.r] == -1){
            continue;
        }

        int val = (long long)(e.cost/2) + front[e.l] + back[e.r];

        ans = min(ans, val);
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
