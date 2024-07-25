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
    int n;
    vector<int> parent, size;

public:
    int n_components, max_component_size;

    DSU(int _n): n(_n){
        size.resize(n, 1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        n_components = n;
        max_component_size = 1;
    }

    int find_parent(int u){
        if(u == parent[u]) return u;

        return parent[u] = find_parent(parent[u]);
    }

    void merge(int u, int v){
        u = find_parent(u);
        v = find_parent(v);

        if(u != v){
            if(size[u] < size[v]){
                swap(u,v);
            }

            parent[v] = u;
            size[u]+=size[v];
            max_component_size = max(max_component_size, size[u]);
            n_components--;
        }
    }
};

void solve() {
    int n, m; cin >> n >> m;

    DSU dsu(n);

    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v; u--, v--;

        dsu.merge(u, v);

        cout << dsu.n_components << " " << dsu.max_component_size << endl;
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
