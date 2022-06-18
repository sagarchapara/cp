// g++ -o out <filename>.cpp
// .\out.exe

// #define SAGAR

#include <bits/stdc++.h>
using namespace std;                                    


/*
 *==========================================
 * Input 
 *==========================================
 */
void read(){}
void read(long long& a){scanf("%lld",&a);}
void read(long& a){scanf("%ld",&a);}
void read(int& a){scanf("%d",&a);}
void read(double& a){scanf("%lf",&a);}
void read(float& a){scanf("%f",&a);}
void read(string& a){cin>>a;}
template<typename x>void read(x& a){for(auto  &i : a) read(i);}
template<typename x,typename y>void read(pair<x,y>& a){ read(a.first),read(a.second);}
template<typename... x>void read(x&... a){((read(a)), ...);}


/*
 *==========================================
 * Output and Debug
 *==========================================
 */

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
#define all(x) (x).begin(), (x).end()
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define sz(x) (int)(x).size()

void dfs(int curr, int par, vi& arr, vector<vi>& edges, map<int,set<int>>& cmap, vector<bool>& visited){
    dbg(curr);
    visited[curr] = true;
    for(int adj: edges[curr]){
        if(arr[curr]!= arr[adj]){
            cmap[arr[curr]].insert(arr[adj]);
            cmap[arr[adj]].insert(arr[curr]);
            dbg(adj);
            dbg(cmap[arr[curr]]);
            dbg(cmap[arr[adj]]);
        }
        if(!visited[adj]){
            dfs(adj, curr, arr, edges, cmap, visited);
        }
    }
}




void solve() {
    int n, m;
    cin >> n >> m;
    vi arr(n);
    map<int,set<int>> cmap;

    int min_color = 1e10;
    rep(i,0,n){
        cin >> arr[i];
        min_color = min(arr[i], min_color);
    }

    dbg(arr); 

    vector<vi> edges(n);

    rep(i,0,m){
        int x, y;
        cin >> x >> y;
        edges[x-1].push_back(y-1);
        edges[y-1].push_back(x-1);
    }

    dbg(edges);

    vector<bool> visited(n, false);

    rep(i,0,n){
        if(!visited[i]){
            dfs(i,-1,arr,edges,cmap, visited);
        }
    }

    int color = min_color;
    int max = 0;

    for(auto [key, val]: cmap){
        dbg(key);
        dbg(val);
        if(sz(val)> max){
            color = key;
            max = sz(val);
        }
    }

    cout << color;
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
