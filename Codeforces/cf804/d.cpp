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
#define vi vector<int>
#define vpi vector<pi>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define sz(x) (int)(x).size()


void solve() {
    int n; cin >> n; int max_elem = 1;
    vi arr(n); for(int &x: arr){cin >> x;}

    vector<vector<bool>> canBeRemoved(n, vector<bool>(n,false));
    
    for(int i=0;i<n;i++){
        vi cnt(n+1,0); int max_len = 0;
        for(int j=i;j<n;j++){
            int len = j-i+1;
            cnt[arr[j]]++;
            max_len = max(cnt[arr[j]], max_len);
            if(len%2==1){
                continue;
            }
            if(max_len > len/2){
                canBeRemoved[i][j] = false;
            }
            else{
                canBeRemoved[i][j] = true;
            }
            
        }
    }

    // dbg(canBeRemoved);

    vector<int> dp(n,0);
    dp[n-1] = 1;
    rep(i,n-1,0){
        // dbg(i);
        if(canBeRemoved[i+1][n-1]) dp[i] = 1;
        rep(j,i+1,n){
            if(i+1 == j){
                if(arr[i] == arr[j]){
                    if(dp[j]>0){
                        dp[i] = max(dp[i], dp[j]+1);
                    }
                }
            }
            else if(arr[i]== arr[j] && canBeRemoved[i+1][j-1]){
                if(dp[j]>0){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
    }

    dbg(dp);

    int ans =0;
    rep(i,0,n){
        if(i == 0){
            ans = max(ans, dp[i]);
        }
        else{
            if(canBeRemoved[0][i-1]){
                ans = max(ans, dp[i]);
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
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
