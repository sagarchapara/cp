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

class SegmentTree{

    int n;
    vector<int> t;

    inline void build(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }

    inline int query(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return query(v*2, tl, tm, l, min(r, tm))
            + query(v*2+1, tm+1, tr, max(l, tm+1), r);
    }

    inline void update(int v, int tl, int tr, int pos, int new_val) {
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

public:

    SegmentTree(int _n, vector<int>& arr): n(_n){
        t.resize(4*n);
        build(arr, 1, 0, n-1);
    }

    SegmentTree(int _n): n(_n){
        t.resize(4*n,0);
    }

    inline int query(int l, int r){
        return query(1, 0, n-1, l, r);
    }

    inline void update(int p, int val){
        update(1,0,n-1,p,val);
    }
};

const int MAXN = 2e5 + 5;

vvi fact(2*MAXN);

vi cnt;


void process(){

    for(int i=1;i<2*MAXN;i++){
        for(int j=i*2;j<2*MAXN; j+=i){
            fact[j].push_back(i);
        }
    }

    dbg("HI");

    cnt.resize(MAXN+1, 0);

    //LCM(i,j,k) = k
    for(int i=1;i<MAXN;i++){
        int sz = fact[i].size();
        for(int j=0;j<sz;j++){
            cnt[fact[i][j]] += (sz-1-j);
            cnt[i+1]-=(sz-1-j);
        }
    }

    dbg("Hi2");

    //LCM(i,j,k) = 2*k and i+j>k
    for(int i=1;i<MAXN;i++){
        //find k' t = k'
        int t = i, tp = 2;
        while(t%2 == 0){
            t/=2; tp*=2;
        }

        //tp is the two power multiplied to t divisors
        // a no of k' divisors less than k
        // b no of 2k divisors less than k
        int a =0, b =0;
        while(a < fact[t].size() && tp*fact[t][a] < i) a++;
        while(b < fact[2*i].size() && fact[2*i][b] < i) b++;

        //p is current index in fact k' 
        int p = 0;
        for(int j : fact[2*i]){
            if(j >= i) break;

            while(p < a && j + tp*fact[t][p] <= i) p++;

            while(p < a  && tp*fact[t][p] <= j) p++;

            if(p >=a) break;

            cnt[j-1]-= (a-p);
            cnt[i]+=(a-p);
        }

        //p is the current index in fact 2k
        p=0;
        for(int j: fact[t]){
            j = tp*j;
            if(j >= i) break;

            while(p < b && j+fact[2*i][p] <= i) p++;

            while(p < b && fact[2*i][p]<= j) p++;

            if(p>=b) break;

            cnt[j-1]-= (b-p);
            cnt[i]+=(b-p);
        }        
    }

    dbg("Hi3");
}


void solve(SegmentTree& segTree) {
    int l,r; cin >> l >> r;

    int ans = segTree.query(l, r+1);

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

    process();

    SegmentTree segTree(MAXN, cnt);

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve(segTree);
    }

    auto stop = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();

    #ifdef SAGAR
        cerr << "Took " << stop - start << "ms" << endl;
    #endif
}
