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
#define vpi vector<pi>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define sz(x) (int)(x).size()


const int MAXN = 1e6;

int n, t[4*MAXN];

//build v= 1 tl=0 tr=n-1

void build(vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm))
                ,query(v*2+1, tm+1, tr, max(l, tm+1), r));
}





void solve() {
    int n, m; cin >> n >> m;
    vi arr(m); for(int &x: arr) cin >> x;
    build(arr,1,0,m-1);

    dbg(arr);

    int q; cin >> q;
    rep(t,0,q){
        vi l(2),r(2); int k;
        rep(i,0,2)  { cin >> l[i]; l[i]--;}
        rep(i,0,2)  { cin >> r[i]; r[i]--;}
        cin >> k;

        // dbg(l); dbg(r); dbg(k);

        if((abs(l[0] - r[0])%k)!=0) {
            cout << "NO\n";
            continue;
        }
        if((abs(l[1] - r[1])%k)!=0){
            cout << "NO\n";
            continue;
        }

        
        //check now if those are blocked

        if(arr[l[1]] > l[0]){
            cout << "NO\n";
            continue;
        }

        if(arr[r[1]] > r[0]){
            cout << "NO\n";
            continue;
        }

        // now get the max between l and r
        int h = query(1,0,m-1,min(l[1], r[1])+1, max(l[1], r[1])-1);

        dbg(h);

        if( h <= max(arr[l[1]], arr[r[1]])){
            cout << "YES\n";
            continue;
        }

        int y = max(l[0], r[0]);

        //find y greater than hl

        if(y>=h){
            cout << "YES\n";
            continue;
        }

        int num = (h-y+k-1)/k;

        y = y + num*k;

        if(y<n){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
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
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
