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

bool isPossible(int time, int n, int m , vi arr){
    // dbg(time);
    int curr = n-1;        
    for(int i=0;i<m;i++){
        if(curr <0){
            return true;
        }
        while(arr[curr]==0 && curr>=0){
            curr--;
        }
        if(curr== -1){
            return true;
        }
        // dbg(curr);
        int time_taken = curr+1;
        int rem = time - time_taken;
        if(rem <= 0){
            return false;
        }
        while(rem >0){
            // dbg(rem);
            while(arr[curr]==0 && curr>=0){
                curr--;
            }
            if(curr== -1){
                return true;
            }
            // dbg(curr);
            int temp = min(arr[curr], rem);
            rem -= temp;
            arr[curr] -= temp;
        }
    }
    // dbg(curr);
    while(arr[curr]==0 && curr>=0){
        curr--;
    }
    if(curr== -1){
        return true;
    }

    return false;
}

void solve() {
    int n, m; cin >> n >> m;
    vi arr(n); for(int &x: arr) cin >> x;

    int l = 0, r = 1e18;

    int ans = r;

    while(r-l>1){
        int mid = (l+r)/2;
        if(isPossible(mid, n, m, arr)){
            r = mid;
            ans = min(ans, mid);
        }
        else{
            l = mid+1;
        }
    }

    rep(i,l,r+1){
        if(isPossible(i,n,m,arr)) ans = min(ans, i);
    }

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
