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
    int n; cin >> n;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(n+1, 0));

    vector<vector<pair<pair<int, int>, pair<int, int>>>> next(n, vector<pair<pair<int, int>, pair<int, int>>>(n+1));

    for(int i=0;i<n;i++){
        dp[i][n] = arr[i];
        next[i][n] = {{-1, n+1}, {i, -1}};

        dp[i][n-1] = max(arr[i], arr[n-1]);
        next[i][n-1] = {{-1, n+1}, {i, n-1}};
    }

    for(int i=n-1;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            //ok we have i and now what to do?
            dp[i][j] = max(arr[j], arr[j+1]) + dp[i][j+2];
            next[i][j] = {{i,j+2}, {j, j+1}};

            int val = max(arr[i], arr[j]) + dp[j+1][j+2];

            if(val < dp[i][j]){
                dp[i][j] = val;
                next[i][j] = {{j+1, j+2}, {i, j}};
            }

            val = max(arr[i], arr[j+1]) + dp[j][j+2];

            if(val < dp[i][j]){
                dp[i][j] = val;
                next[i][j] = {{j, j+2}, {i, j+1}};
            }
        }
    }

    if(n<=2){
        if(n == 1){
            cout << arr[0] << endl;
            cout << 1 << endl;
        }
        else{
            cout << max(arr[0], arr[1]) << endl;
            cout << 1 << 2 << endl;
        }
    }
    else{
        int ans = max(arr[0], arr[1]) + dp[2][3];
        pi start = {0,1}, nt = {2,3};

        if( ans < max(arr[0], arr[2]) + dp[1][3]){
            ans = max(arr[0], arr[2]) + dp[1][3];
            start = {0,2}, nt = {1,3};
        }

        if(ans < max(arr[1], arr[2]) + dp[0][3]){
            ans = max(arr[1], arr[2]) + dp[0][3];
            start ={1,2}, nt = {0,3};
        }

        cout << ans << endl;

        cout << (start.first + 1) << " " <<(start.second + 1) << endl;

        do{
            pi val = next[nt.first][nt.second].second;

            nt = next[nt.first][nt.second].first;

            if(val.second == -1){
                cout << (val.first + 1) << endl;
            }
            else{
                cout << (val.first + 1) << " " <<(val.second + 1) << endl;
            }

        }while (nt.second != n+1);
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
