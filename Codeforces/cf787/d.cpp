// g++ -o out <filename>.cpp -D SAGAR
// .\out.exe

#include <bits/stdc++.h>
using namespace std;                                    

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x << " "; return os;}
void dbg_out() { cerr << "" << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H ; dbg_out(T...); }
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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define sz(x) (int)(x).size()

void form_set(int curr, vvi& adj,vi&d, vi& curr_set, vvi& ans){
    curr_set.push_back(curr);
    if(adj[curr].size()==0){
        ans.push_back(curr_set);
        return;
    }
    bool found = false; int idx =-1;
    for(int i: adj[curr]){
        if(d[i]+1 == d[curr]){
            found = true;
            idx = i;
            break;
        }
    }

    for(int i: adj[curr]){
        if(i == idx){
            form_set(i,adj,d, curr_set, ans);
        }
        else{
            vi s;
            form_set(i,adj,d,s, ans);
        }
    }
}

void dfs(int curr, vvi&adj, vi& d){
    d[curr] = 1;
    for(int i: adj[curr]){
        dfs(i,adj, d);
        d[curr] = max(d[curr], d[i]+1);
    }
}


void solve() {
    int n; cin >>n;
    vi p(n); for(int &x:p) {cin >> x; --x;}
    vvi adj(n);int root;
    rep(i,0,n){
        if(p[i]==i) root =i;
        else{
            adj[p[i]].push_back(i);
        }
    }
    vi depth(n,0);
    dfs(root, adj, depth);

    vvi ans;

    vi s;
    form_set(root, adj, depth, s, ans);

    printf("%d\n", ans.size());
    rep(i,0,sz(ans)){
        printf("%d\n", ans[i].size());
        for(int j: ans[i]){
            printf("%d ", (j+1));
        }
        printf("\n");
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

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
