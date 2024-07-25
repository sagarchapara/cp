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

class DSU{
    vector<int> parent, rank;
    int n;

public:
    DSU(int _n): n(_n){
        rank.assign(n, 0);
        parent.resize(n);

        for(int i=0;i<n;i++){
            parent[i] =i;
        }
    }

    int find_parent(int i){
        if(parent[i] == i){
            return i;
        }

        return parent[i] = find_parent(parent[i]);
    }

    void merge(int i, int j){
        i = find_parent(i);
        j = find_parent(j);

        if(i == j){
            return;
        }

        if(rank[i] < rank[j]){
            swap(i,j);
        }

        parent[j] = i;

        if(rank[i] == rank[j]){
            rank[i]++;
        }
    }

    bool check(int i, int j){
        return find_parent(i) == find_parent(j);
    }
};

struct Edge{
    int u;
    int v;
    int cost;

    Edge(int _u, int _v, int _cost): u(_u), v(_v), cost(_cost){}

    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

void solve() {
    int n, m; cin >> n >> m;

    vector<Edge> edges;

    for(int i=0;i<m;i++){
        int u,v,w; cin >> u >> v >> w; u--, v--;

        edges.emplace_back(u,v,w);
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);

    int cost = 0;

    for(Edge e: edges){
        if(!dsu.check(e.u, e.v)){
            cost += e.cost;
            dsu.merge(e.u, e.v);
        }
    }

    bool good = true;

    for(int i=0;i<(n-1);i++){
        if(!dsu.check(i, i+1)){
            good = false;
            break;
        }
    }

    if(good){
        cout << cost << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
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
