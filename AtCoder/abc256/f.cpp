// g++ -o out <filename>.cpp
// .\out.exe

#define SAGAR

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


const int MAXN = 1e6;

int t[4*MAXN];

//build v= 1 tl=0 tr=n-1

void build(vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, min(r, tm))
           + query(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

void solve() {
    int n, q;
    cin >> n >> q;

    vi arr(n);
    rep(i,0,n){
        cin >> arr[i];
    }
    vi b(arr);
    rep(i,1,n){
        b[i]+=b[i-1];
    }
    vi c(b);
    rep(i,1,n){
        c[i]+=c[i-1];
    }
    vi d(c);
    rep(i,1,n){
        d[i]+=d[i-1];
    }
    vector<pair<int,pi>> queries(q);
    set<int> unique_d;

    fill(t, t + 4*MAXN, 0);

    build(c, 1, 0 , n-1);

    rep(i,0,q){
        int t, x, v = -1;
        cin >> t >> x;
        if(t == 1){
            cin >> v;
        }
        else{
            unique_d.insert(x-1);
        }
        queries[i] = {t, {x-1,v}};
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
