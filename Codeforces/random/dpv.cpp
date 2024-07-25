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

const int MOD = 1e9+7;

vector<vector<int>> matrix_mul(vector<vector<int>>& a, vector<vector<int>>& b){
    assert(a[0].size() == b.size());
    vector<vector<int>> ab(a.size(), vector<int>(b[0].size(),0));

    for(int i=0;i<a.size();i++){
        for(int j=0;j<b[0].size();j++){
            for(int k=0;k<a[0].size();k++){
                ab[i][j] = (ab[i][j] + a[i][k]*b[k][j])%MOD;
            }
        }
    }

    return ab;
}

vector<vector<int>> matrix_pow_k(vector<vector<int>>& arr, int k){
    int n = arr.size();
    vector<vector<int>> ans(n, vector<int>(n, 0));
    
    // Initialize ans as the identity matrix
    for (int i = 0; i < n; i++) {
        ans[i][i] = 1;
    }

    auto val = arr;

    while(k > 0){
        if(k & 1){
            dbg(k);
            ans = matrix_mul(ans, val);
        }

        val = matrix_mul(val, val);
        k>>=1;
    }

    return ans;
}

void solve() {
    int n, k; cin >> n >> k;

    vector<vector<int>> arr(n, vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }

    int ans = 0;

    auto val = matrix_pow_k(arr, k);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans = (ans + val[i][j])%MOD;
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
