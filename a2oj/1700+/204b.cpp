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

int bs(int col, vpi& arr, int n, int req){
    int curr =0; int total =0; int zop = 0; int sop =0;
    for(auto [a,b]: arr){
        if(a == col){
            zop++;
        }
        else if(b == col){
            sop++;
        }
    }
    
    if(zop + sop < req){
        return -1;
    }

    if(zop >= req){
        return 0;
    }
    else{
        return req-zop;
    }
}

void solve() {
    int n; cin >>n;

    map<int,int> cnt;

    int req = (n+1)/2; 

    vpi arr(n);

    rep(i,0,n){
        int a , b; cin >> a >> b;
        arr[i] = {a,b};
        if(!cnt.count(a)){
            cnt[a] =0;
        }
        cnt[a]++;

        if(!cnt.count(b)){
            cnt[b] =0;
        }
        cnt[b]++;
    }
    int ans = -1;
    for(auto [key, val]: cnt){
        if(val>=req){
            int k = bs(key, arr, n, req);
            if(k!=-1){
                if(ans !=-1){
                    ans = min(k, ans);
                }
                else{
                    ans = k;
                }
            }
        }
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

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
