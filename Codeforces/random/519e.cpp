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

// #define int long long
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


class TreeSolver {
private:
    vector<vector<int>> adj;
    vector<int> parent;
    vector<map<int, int>> size;
    vector<int> dist;
    vector<vector<int>> ansector;

    int dfs(int u, int p, int d) {
        parent[u] = p;
        dist[u] = d;

        int total_size = 1;

        for(int v : adj[u]){
            if(v != p){
                int sz = dfs(v, u, d+1);
                size[u].insert({v, sz});
                total_size += sz;
            }
        }

        size[u].insert({-1,total_size});

        return total_size;
    }

    vector<vector<int>> build_parent(int n) {
        int log2n = ceil(log2(n)) + 1;
        vector<vector<int>> par(n, vector<int>(log2n));

        for(int i = 0; i < n; i++){
            par[i][0] = parent[i];
        }

        for(int i = 0; i < n; i++){
            for(int j = 1; j < log2n; j++){
                par[i][j] = par[par[i][j-1]][j-1];
            }
        }

        return par;
    }

    int move_k(int p, int k) {
        int n = ansector.size();
        int log2n = ceil(log2(n)) + 1;

        for(int i = log2n - 1; i >= 0; i--){
            if(k & (1 << i)){
                p = ansector[p][i];
            }
        }

        return p;
    }

public:
    void solve() {
        int n; cin >> n;

        adj.resize(n);
        parent.assign(n, -1);
        size.resize(n);
        dist.resize(n);

        for(int i = 0; i < n - 1; i++){
            int u, v; cin >> u >> v; u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, 0, 0);
        ansector = build_parent(n);

        int m; cin >> m;

        for(int i = 0; i < m; i++){
            int x, y; cin >> x >> y; x--; y--;

            int val = find_ansector(x, y);

            int dx = dist[x] - dist[val];
            int dy = dist[y] - dist[val];

            if((dx + dy) % 2 == 1){
                cout << 0 << endl;
                continue;
            }

            int len = (dx + dy) / 2;

            if(dx == dy){
                if(x == y){
                    cout << n << endl;
                    continue;
                }

                int lval = move_k(x, len - 1);
                int rval = move_k(y, len - 1);

                int ans = n - size[val][lval] - size[val][rval];

                cout << ans << endl;
            } else {
                if(dx > dy){
                    swap(x, y);
                }

                int middle_minus_one = move_k(y, len - 1);
                int middle = parent[middle_minus_one];
                int ans = size[middle][-1] - size[middle][middle_minus_one];

                cout << ans << endl;
            }
        }
    }

    int find_ansector(int x, int y) {
        int n = dist.size();
        int log2n = ceil(log2(n)) + 1;

        int dx = dist[x];
        int dy = dist[y];

        if(dx < dy){
            swap(x, y);
            swap(dx, dy);
        }

        int level = dx - dy;
        int u = x, v = y;

        u = move_k(u, level);

        if(u == v){
            return v;
        }

        for(int i = log2n - 1; i >= 0; i--){
            if(ansector[u][i] != ansector[v][i]){
                u = ansector[u][i];
                v = ansector[v][i];
            }
        }

        assert(ansector[u][0] == ansector[v][0]);

        return ansector[u][0];
    }
};

int main() {
    #ifdef SAGAR
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
    #endif

    TreeSolver solver;
    solver.solve();

    return 0;
}

