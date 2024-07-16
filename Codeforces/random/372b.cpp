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
    int n, m, q; cin >> n >> m >> q;

    int arr[n][m];

    for(int i=0;i<n;i++){
        string s; cin >> s;
        for(int j=0;j<m;j++){
            char c = s[j];
            arr[i][j] = c - '0';
        }
    }

    int down_zeros[n][m], left_zeros[n][m];

    for(int i =0;i<n;i++){
        int last_zero = -1;
        for(int j=0;j<m;j++){
            if(arr[i][j] == 0){
                left_zeros[i][j] = (j - last_zero);
                dbg(left_zeros[i][j]);
            }
            else{
                last_zero = j;
                left_zeros[i][j] =0;
            }
        }
    }

    for(int j=0;j<m;j++){
        int last_zero = n;
        for(int i=n-1;i>=0;i--){
            if(arr[i][j] == 0){
                down_zeros[i][j] = (last_zero - i);
                dbg(down_zeros[i][j]);
            }
            else{
                last_zero = i;
                down_zeros[i][j] =0;
            }
        }
    }

    int dp[n][n][m][m];
    bool isGood[n][n][m][m];

    memset(dp, 0, sizeof(dp));
    memset(isGood, false, sizeof(isGood));

    //two rows, one column
    for(int xlen =0;xlen<n;xlen++){
        for(int ylen =0;ylen<m;ylen++){
            for(int i=0;i+xlen<n;i++){
                for(int j=0;j+ylen<m;j++){
                    int i2 = i + xlen;
                    int j2 = j + ylen;

                    if(i == i2){
                        int last_one = j-1;
                        for(int k= j;k<=j2;k++){
                            if(arr[i][k] == 0){
                                dp[i][i2][j][j2]+= (k - last_one);
                            }
                            else{
                                last_one = k;
                            }
                        }

                        if(last_one == j-1){
                            isGood[i][i2][j][j2] = true;
                        }
                    }
                    else if(j == j2){
                        int last_one = i-1;
                        for(int k=i;k<=i2;k++){
                            if(arr[k][j] == 0){
                                dp[i][i2][j][j2] += (k - last_one);
                            }
                            else{
                                last_one = k;
                            }
                        }

                        if(last_one == i-1){
                            isGood[i][i2][j][j2] = true;
                        }
                    }
                    else{

                        isGood[i][i2][j][j2] = (arr[i][j2] == 0) && (isGood[i+1][i2][j][j2]) && (isGood[i][i2][j][j2-1]);

                        //number of good arrays
                        for(int ii = i;ii<=i2;ii++){
                            for(int jj =j;jj<=j2;jj++){
                                if(isGood[i][ii][jj][j2]){
                                    dp[i][i2][j][j2]++;
                                }
                            }
                        }
                        
                        dbg(i, i2, j, j2, dp[i][i2][j][j2]);

                        // //left zeros of i2 and down zeros of i2
                        // dp[i][i2][j][j2] = min(left_zeros[i][j2], ylen+1) + min(down_zeros[i][j2], xlen+1) - ((arr[i][j2] == 0) ? 1: 0);

                        // dbg(left_zeros[i][j2], down_zeros[i][j2]);

                        dp[i][i2][j][j2] += dp[i+1][i2][j][j2] + dp[i][i2][j][j2-1] - dp[i+1][i2][j][j2-1];
                    }

                    dbg(i, i2, j, j2, dp[i][i2][j][j2], isGood[i][i2][j][j2]);
                }
            }
        }
    }

    while (q--)
    {
        int a, b, c, d; cin >> a >> b >> c >> d; a--,b--,c--,d--;

        cout << dp[a][c][b][d] << endl;
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
