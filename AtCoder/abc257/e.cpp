// g++ -o out <filename>.cpp
// .\out.exe

#define SAGAR

#include <bits/stdc++.h>
using namespace std;                                    

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x; return os;}
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
#define rall(x) (x).rbegin(), (x).rend()
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vi arr(9); map<int,int> cost;
    
    rep(i,0,9){
        int x; cin >> x;
        arr[i] = x;
        cost[x] = (i+1);
    }

    int min_cost = cost.begin()->first; 
    int min_i = cost.begin()->second;

    int num = n/min_cost ;

    int rem = n%min_cost;

    dbg(num); dbg(rem);

    vi ans;
    int t =0;
    while(rem >0 && t < num){
        int next_i = min_i;
        int cst = min_cost;
        bool isPresent = false;
        for(auto [key,val]: cost){
            if(key <= rem+min_cost){
                if(val > next_i){
                    cst = key;
                    next_i = val;
                    isPresent = true;
                }
            }
        }

        if(!isPresent){
            break;
        }

        dbg(cst-min_cost);

        rem -= cst;
        rem+= min_cost;
        ans.push_back(next_i);

        dbg(rem);
        t++;
    }

    while(ans.size()<num){
        ans.push_back(min_i);
    }

    sort(rall(ans));

    cout << ans;
    
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
