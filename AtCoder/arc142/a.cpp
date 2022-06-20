// g++ -o out <filename>.cpp
// .\out.exe

// #define SAGAR

#include <bits/stdc++.h>
using namespace std;                                    

/*
 *==========================================
 * Output and Debug
 *==========================================
 */

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
    int n , k; cin >> n >> k;

    vi arr; int curr =k;
    while(curr!=0){
        arr.push_back(curr%10);
        curr = curr/10;
    }

    int num = sz(arr);

    int ans =0;

    dbg(arr);

    if(arr[0]== 0){
        cout << 0;
        return;
    }

    int rev =0;
    rep(i,0,num){
        rev = 10*rev + arr[i];
    }

    if(k > rev){
        ans =0;
    }

    dbg(rev);
    dbg(k);
    dbg(n);
    if(k<=rev){
        int start =k;
        while(start <=n){
            ans++;
            start*=10;
        }
        if(k!=rev){
            start = rev;
            while(start <=n){
                ans++;
                start*=10;
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
