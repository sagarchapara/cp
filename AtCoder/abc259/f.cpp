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
#define pii pair<int, pi>
#define vi vector<int>
#define vpi vector<pi>
#define vpii vector<set<pi>>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n; vpii arr(n); vi d(n);
    for(int &x: d) cin >> x;
    for(int i=0;i<n-1;i++){
        int u,v,w; cin >> u >> v >> w; u--, v--;
        if(u<v && w>0){
            arr[v].insert({w,u});
        }
        else if(v>u && w>0){
            arr[u].insert({w,v});
        }
    }


    map<int, multiset<int>> taken;
    rep(i,1,n){
        int rem = d[i];
        for(auto it = arr[i].rbegin(); it!= arr[i].rend(); ++it){
            pi p = (*it);
            int u = p.second, w = p.first;
            if(d[u]>0){
                if(taken.count(u)>0){
                    auto itr = taken[u].lower_bound(w);
                    if(itr!=taken[u].begin()){
                        if(d[u] == taken.count(u)){
                            taken[u].erase(taken[u].begin());
                        }
                    }
                    
                }
                else{
                    multiset<int> taken[u];
                    taken[u].insert(w);
                }
            }
        }
    }
    rep(i,0,n){

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

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
