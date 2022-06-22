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
#define all(x) (x).begin(), (x).end()
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define sz(x) (int)(x).size()

const int MAXN = 1e5 + 5;
// const int MAXN = 20;

set<int> t[4*MAXN];

set<int> query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return set<int>() ;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;

    auto s1 = query(v*2, tl, tm, l, min(r, tm));
    auto s2 = query(v*2+1, tm+1, tr, max(l, tm+1), r);
    
    set<int> fSet;

    merge(all(s1), all(s2), inserter(fSet, fSet.end()));

    return fSet;
}

void update(int v, int tl, int tr, int pos, set<int>& new_val) {
    // dbg(new_val);
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);

        merge(all(t[2*v]), all(t[2*v+1]), inserter(t[v], t[v].end()));
    }
}

vector<set<int>> divisors(MAXN);

void compute(){
    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) {
            divisors[j].insert(i);
        }
    }
}

void solve() {
    int n ; cin >> n;

    vector<multiset<int>> div(n);

    compute();
    rep(i,0,n){
        int x,y;
        cin >> x >> y;

        auto curr = divisors[x];

        multiset<int> fSet;
        if(i-y-1>=0){
            set_difference(all(divisors[i-1]), all(divisors[i-y-1]), inserter(fSet, fSet.end()));
        }
        else if(i-1 >=0){
            fSet.insert(all(div[i-1]));
        }
        
        set<int> diffSet;

        set_difference(all(curr), all(fSet), inserter(diffSet, diffSet.end()));

        dbg(fSet);
        dbg(curr);
        dbg(diffSet);

        if(i-1 >=0){   
            merge(all(curr), all(div[i-1]), inserter(div[i], div[i].end()));
        }
        else{
            div[i].insert(all(curr));
        }

        dbg(div[i]);


        cout << diffSet.size() << endl;
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
