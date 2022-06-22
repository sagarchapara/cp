// g++ -o out <filename>.cpp
// .\out.exe

// #define SAGAR

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

bool bs(int k, vi& has, vi& cost, vi& cnt,int total){
    int sum =0;
    rep(i,0,3){
        int req = k*cnt[i] - has[i];
        if(req >0){
            sum += req*cost[i];
        }
    }

    return sum <= total;
}

void solve() {
    string s; cin >> s;
    vi has(3); for(int &x: has) cin >> x;
    vi cost(3); for(int &x: cost) cin >> x;
    int total; cin >> total;
    vi cnt(3,0); 
    for(char c: s){
        if(c == 'B') ++cnt[0];
        else if(c == 'S') ++cnt[1];
        else ++cnt[2];
    }

    dbg(cnt);

    int l=0, r= 1e15 +5 ;

    while(r-l>1){
        int mid = (r+l)/2;
        if(bs(mid,has,cost,cnt,total)){
            l = mid;
        }
        else{
            r = mid-1;
        }
    }

    rep(i,r+1,l){
        if (bs(i,has,cost,cnt,total)) {
            cout << i << endl;
            return;
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
