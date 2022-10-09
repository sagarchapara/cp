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

bool isPossible(int p, int n, int k, vi arr){
    int num =0;
    rep(i,0,n){
        if(arr[i]*2 < p){
            num++; arr[i] = 1e9;
            if(num > k) return false;
        }
    }

    if(k >= num+2) return true;

    rep(i,1,n){
        if(min(arr[i], arr[i-1]) >= p) return true;
    }

    rep(i,1,n){
        if(arr[i] >=p && arr[i-1] < p ){
            if( k>= num +1) return true;
        }
        
        if(arr[i] < p && arr[i-1] >= p ){
            if( k>= num +1) return true;
        }
    }

    return false;
}


void solve() {
    int n,k;
    cin >> n >> k;
    vi arr(n); rep(i,0,n) cin >> arr[i];

    if(k>=n){
        cout << 1000000000 << endl;
        return;
    }

    int l =1, r = 1e9;
    while(r-l>1){
        int mid = (l+r)/2;
        if(isPossible(mid, n, k, arr)){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }

    rep(i, r+1, l){
        if(isPossible(i, n, k, arr)){
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

    auto start = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }

    auto stop = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();

    #ifdef SAGAR
        cerr << "Took " << stop - start << "ms" << endl;
    #endif
}
