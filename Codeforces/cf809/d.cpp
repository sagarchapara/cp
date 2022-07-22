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
#define vpi vector<pi>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define sz(x) (int)(x).size()


void solve() {
    int n,k; cin >> n >> k;

    int max_n =0;
    vi arr(n); for(int &x: arr){ cin >> x; max_n = max(max_n, x);}
    set<int> s(all(arr));

    dbg(arr); dbg(max_n);

    int ans = max_n; int idx = 0;
    for(int i=1;i<=max_n;i++){

        int t = 0;

        if((max_n/k) > i) continue;

        for(int j=1; (i*(j-1)<max_n) && (j<=k);j++){

            auto it = s.upper_bound(i*(j-1)); 
            if(it == s.end())   break;

            // dbg(i,j);

            int p = *it;

            if((p/j) <= i){
                int u = p/j; int v = i+1;
                if( j>1) v = p/(j-1);
                if(v<=i){
                    u = max(u,v);
                }
                t = max(t, abs((i - u)));
            }
            // dbg(t);
            // dbg(p);
        }

        // dbg(t);
        if(t < ans){
            ans  =t;
            idx =i;
        }
    }

    dbg(idx);

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
