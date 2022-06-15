// g++ -o out <filename>.cpp
//  cmd /c '.\out.exe < input.txt'

#include <bits/stdc++.h>                                    

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define mp make_pair
#define pb push_back

void solve() {
    int n;
    vector<int> arr(3);
    cin >> n >> arr[0]>> arr[1] >> arr[2];

    sort(arr.begin(), arr.end());
    dbg(arr);
    int ans =0;
    for(int k= 0; k*arr[2]<= n ;k++){
        for(int j =0 ;k*arr[2]+j*arr[1]<=n; j++){
            int rem = n - k*arr[2] - j*arr[1];
            if(rem % arr[0] == 0){
                int div = rem/arr[0];
                ans = max( ans, k+j+div);
            }
        }
    }

    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
