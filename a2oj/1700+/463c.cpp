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

void solve() {
    int n; cin >> n;
    vi dp1(2*n,0), dp2(2*n,0);
    vector<vi> arr(n,vi(n));
    rep(i,0,n){
        rep(j,0,n){
            int x; cin >> x;
            arr[i][j] = x;
            dp1[i+j]+=x;
            dp2[n+i-j]+=x;
        }
    }
    int max1 = -1; int max2 =-1;
    pi p1,p2;
    rep(i,0,n){
        rep(j,0,n){
            int next = dp1[i+j]+ dp2[n+i-j] - arr[i][j];
            if((i+j)%2==0){
                if(next > max1){
                    max1 = next;
                    p1 = {i+1, j+1};
                }
            }
            else {
                if(next > max2){
                    max2 = next;
                    p2 = {i+1, j+1};
                }
            }
        }
    }

    cout << max1 + max2 << endl;
    cout << p1 << " " << p2 << endl;
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
