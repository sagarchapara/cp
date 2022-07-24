// g++ -o out <filename>.cpp -D SAGAR
// .\out.exe

#include <bits/stdc++.h>
using namespace std;      

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x << " "; return os;}
void dbg_out() { cerr << "" << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << " "; dbg_out(T...); }
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

class FenwickTree{
    int n;
    vector<int> bit;
    
    inline int query(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1){
            ret += bit[r];
        }  
        return ret;
    }

public:

    FenwickTree(int _n, vector<int>& arr): n(_n){
        bit.resize(n,0);
        for(int i=0;i<n;i++){
            update(i, arr[i]);
        }
    }

    FenwickTree(int _n): n(_n){
        bit.resize(n,0);
    }

    inline void update(int idx, int delta){
        for(; idx<n ; idx = (idx | (idx+1))){
            bit[idx]+=delta;
        }
    }

    inline int query(int l, int r){
        return query(r) - query(l-1);
    }
};


int unique_transform(int n, vector<int>& arr){
    set<int> s(arr.begin(), arr.end());
    int i =0; map<int,int> m;
    for(int k: s) m.insert({k,i++});
    for(int i=0;i<n;i++) arr[i] = m[arr[i]];
    return s.size();
}

int MAXN = 3e5+5;


void solve() {
    int n; cin >> n;
    int ans =0;

    FenwickTree tree(n);

    vi col(n); rep(i,0,n){ cin >> col[i]; col[i]--;}

    int num = unique_transform(n, col);

    vvi arr(num);
    vi b(n);

    for(int i=0;i<n;i++){
        int x; cin >> x; x--;
        b[i] = x;
        ans+= tree.query(x+1, n-1);
        tree.update(x, 1);
        arr[col[i]].push_back(x);
    }

    rep(i,0,n) tree.update(b[i],-1);


    rep(i,0,num){
        for(int x: arr[i]){
            ans-=tree.query(x+1, n-1);
            tree.update(x,1);
        }
        for(int x: arr[i]) tree.update(x,-1);
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
