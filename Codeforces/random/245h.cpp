// g++ -o out <filename>.cpp -D SAGAR
// .\out.exe

#include <bits/stdc++.h>
using namespace std;                                    

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x << " "; return os;}
void dbg_out() { cerr << "" << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << " " ; dbg_out(T...); }
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

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    int dp[n][n];
    bool isPalindrome[n][n];

    memset(dp, 0, sizeof(dp));
    memset(isPalindrome, false, sizeof(isPalindrome));

    for(int i=0;i<n;i++){
        dp[i][i] = 1;
        isPalindrome[i][i] = true;
    }

    for(int len=1;len<n;len++){
        for(int i=0;i+len<n;i++){
            int j = i + len;

            if(len == 1){
                isPalindrome[i][j] = (s[i] == s[j]);
            }
            else{
                isPalindrome[i][j] = isPalindrome[i+1][j-1] && (s[i] == s[j]);
            }

            dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] + (isPalindrome[i][j] ? 1 : 0);

            dbg(i, j, dp[i][j], dp[i+1][j], dp[i][j-1], dp[i+1][j-1]);
        }
    }

    int q; cin >> q;

    while (q--)
    {
        int l, r; cin >> l >> r; l--, r--;

        cout << dp[l][r] << endl;
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
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }

    auto stop = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();

    #ifdef SAGAR
		cerr << "Took " << stop - start << "ms" << endl;
	#endif
}
