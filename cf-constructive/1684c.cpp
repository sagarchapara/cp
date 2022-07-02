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
#define vpi vector<vector<pi>>
#define vii vector<vector<int>>
#define all(x) (x).begin(), (x).end()
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define sz(x) (int)(x).size()

bool verify(vii& arr, int n, int m){
    rep(i,0,n){
        rep(j,1,m){
            if(arr[i][j] < arr[i][j-1]) return false;
        }
    }

    return true;
}

void solve() {
    int n,m ; cin >> n >> m;
    vii arr(n, vi(m));  vii sarr(n, vi(m));
    rep(i,0,n){
        rep(j,0,m){
            int x; cin >> x;
            arr[i][j] = x;
            sarr[i][j] = x;
        }
        sort(all(sarr[i]));
    }
    int num =0; int cola = 0, colb = 0;
    rep(j,0,m){
        bool areEqual = true;
        rep(i,0,n){
            if(arr[i][j]!= sarr[i][j]){
                areEqual = false;
                break;
            }
        }
        if(!areEqual){
            num++;
            if(num>2){
                cout << -1 << endl;
                return;
            }
            else if(num==2) colb = j;
            else cola =j;
        }
    }
    if(num==2){
        rep(i,0,n){
            swap(arr[i][cola], arr[i][colb]);
        }
    }
    if(verify(arr, n ,m)){
        cout << (cola+1) << " " << (colb+1) << endl;
        return;
    }

    cout << -1 << endl;
    
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