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
#define vpi vector<pi>
#define all(x) (x).begin(), (x).end()
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define sz(x) (int)(x).size()

void print(vpi& ans){
    printf("%d\n", ans.size());
    for(pi p: ans){
        printf("%d %d\n", p.first+1, p.second+1);
    }
}

void solve() {
    int n; cin >> n;
    vi arr(n); for(int &x: arr) cin >> x;
    set<pi> max_min;
    rep(i,0,n){
        if(arr[i]!=0){
            max_min.insert({arr[i], i});
        }
    }
    vpi ans;
    while(max_min.size()>=2){
        pi least = *max_min.begin();
        pi most = *(--max_min.end());

        auto start = max_min.begin();
        auto end = max_min.end();
        end--;

        if(most.first >0 && least.first> 0 ){
            ans.push_back({most.second, least.second});
            max_min.erase(start);
            max_min.erase(end);
            if(most.first > 1){
                max_min.insert({most.first-1, most.second});
            }
            if(least.first>1){
                max_min.insert({least.first-1, least.second});
            }
        }
    }
    print(ans);
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
