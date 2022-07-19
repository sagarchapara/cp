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
#define pii pair<pi,pi>
#define vi vector<int>
#define vpi vector<pi>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define sz(x) (int)(x).size()

void print(vi& ans, int n){
    rep(i,0,n){
        printf("%d ", ans[i]);
    }
    printf("\n");
}

void solve() {
    int n; cin >> n;
    vi arr(n); for(int &x: arr) cin >> x;
    vpi pos;
    // dbg(arr);
    rep(i,1,n+1){
        int b = arr[i-1];
        int l = i/(b+1) + 1;
        pos.push_back({l,i});
    }
    sort(all(pos));

    set<pi> s; int j =0; vi ans(n);
    rep(i,1,n+1){
        while(j<n && pos[j].first == i){
            int idx = pos[j].second;
            int r = (arr[idx-1])? idx/(arr[idx-1]) : n;
            s.insert({r, idx});
            j++;
        }
        ans[s.begin()->second - 1] = i;
        s.erase(s.begin());
    }
    print(ans, n);
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
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
