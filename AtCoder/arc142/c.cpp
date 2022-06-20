// g++ -o out <filename>.cpp
// .\out.exe

// #define SAGAR

#include <bits/stdc++.h>
using namespace std;                                    

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

// void dfs(int v, int par, vector<vi>& edges, vi& dist, int depth){
//     dist[v] = depth;
//     for(int i:edges[v]){
//         if(i!=par){
//             dfs(i, v,edges, dist, depth+1);
//         }
//     }
// }

// void helper(){
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     int n; cin >> n; 
//     // cout << n <<endl;
//     vector<vector<int>> adj(n);
//     rep(i,0,n-1){
//         int x, y ; cin >> x >> y ; --x ; --y;
//         adj[x].push_back(y);
//         adj[y].push_back(x);    
//     }

//     vi a(n,0), b(n,0);

//     dfs(0,-1,adj,a,0);
//     dfs(1,-1,adj,b,0);

//     rep(i,2,n){
//         cout << a[i] << endl;
//     }

//     rep(i,2,n){
//         cout << b[i] << endl;
//     }

//     cout << "ans " << a[1] << endl;
// }

void solve() {
    int n; cin >> n; 
    // cout << n << endl;

    if(n==2){
        cout << "! "<< 1 ;
    }

    vi a(n), b(n);
    rep(i,2,n){
        cout << "? " << 1 << " " <<(i+1) << endl;
        cin >> a[i]; 
    }
    rep(i,2,n){
        cout << "? " << 2 << " "<<(i+1) << endl;
        cin >> b[i]; 
    }

    // cout << "a " << a << endl;
    // cout << "b " << b << endl;

    bool isPoss = true;
    rep(i,2,n){
        if(abs(a[i]-b[i])!=1){
            isPoss = false;
        }
    }
    
    if(isPoss){
        cout << "! "<< 1 << endl;
        return;
    }

    int ans = n;
    rep(i,2,n){
        ans = min(ans,a[i]+b[i]);
    }

    cout << "! "<< ans << endl;
}

int32_t main() {
    // #ifdef SAGAR
    //     freopen("input.txt", "r", stdin);
    //     // freopen("output.txt", "w", stdout);
    // #else
    //     ios_base::sync_with_stdio(0);
    //     cin.tie(0); cout.tie(0);
    // #endif

    // freopen("output.txt", "r", stdin);
    // freopen("output2.txt", "w", stdout);

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // helper();
        solve();
    }
}
