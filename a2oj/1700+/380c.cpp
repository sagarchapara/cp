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
#define pii pair<int,pi>
#define vpii vector<pii>
#define all(x) (x).begin(), (x).end()
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define sz(x) (int)(x).size()

vpii t;

pii merge_node(pii& a, pii& b){
    int minb = min(a.second.first, b.second.second);
    pii ans;
    ans.first = a.first+b.first + 2*(minb);
    ans.second.first = a.second.first + b.second.first - minb;
    ans.second.second = a.second.second + b.second.second -minb;

    return ans;
}

//build v= 1 tl=0 tr=n-1
void build(string& a, int v, int tl, int tr) {
    if (tl == tr) {
        if(a[tl]=='(') t[v] = {0,{1,0}};
        else t[v] = {0,{0,1}};
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = merge_node(t[v*2], t[v*2+1]);
    }
}

pii query(int v, int tl, int tr, int l, int r){
    if (l > r) 
        return {0,{0,0}};
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    int ans =0;
    auto a1 = query(v*2, tl, tm, l, min(r, tm));
    auto a2 = query(v*2+1, tm+1, tr, max(l, tm+1), r);
    return merge_node( a1,a2);
}

void solve() {
    string s; cin >> s;
    int n = s.size();

    t.resize(4*n);

    // dbg(n);

    build(s,1,0,n-1);

    // dbg(t);

    int m ; cin >> m;
    rep(i,0,m){
        int l,r ; cin >> l >> r; l-- ; r--;
        cout << query(1,0,n-1,l,r).first << endl;
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
