// g++ -o out <filename>.cpp
// .\out.exe

#define SAGAR

#include <bits/stdc++.h>
using namespace std;                                    

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x << " "; return os;}
void dbg_out() { cerr << ""; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << endl; dbg_out(T...); }
#ifdef SAGAR
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define F first
#define S second
#define pi pair<int,int>
#define vi vector<int>
#define vpi vector<pi>
#define all(x) (x).begin(), (x).end()
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define sz(x) (int)(x).size()

void print(vpi& ans){
    printf("%d\n", ans.size());
    for(pi p: ans){
        printf("%d %d\n", p.first, p.second);
    }
}

class DSU {
    vi parent;
    int n;

    public:
        DSU (int _n): n(_n){
            parent.resize(n);
            iota(all(parent), 0ll);
        }

        ~DSU(){
            parent.clear();
        }

        int find_set(int v) {
            if (v == parent[v])
                return v;
            return parent[v] = find_set(parent[v]);
        }

        bool check(int u, int v){
            return find_set(u) != find_set(v);
        }

        void union_sets(int a, int b) {
            a = find_set(a);
            b = find_set(b);
            if (a != b)
                parent[b] = a;
        }
};

void solve() {
    int n, m1 ,m2; cin >> n >> m1 >> m2;
    DSU a(n), b(n);

    rep(i,0,m1){
        int u,v; cin >> u >> v;  u--, v--;
        a.union_sets(u,v);
    }

    rep(i,0,m2){
        int u,v; cin >> u >> v;  u--, v--;
        b.union_sets(u,v);
    }
    
    vpi ans;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a.check(i,j) && b.check(i,j)){
                ans.push_back({i+1, j+1});
                a.union_sets(i,j), b.union_sets(i,j);
            }
        }
    }

    print(ans);
}

int32_t main() {
    #ifdef SAGAR
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
    #endif

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
