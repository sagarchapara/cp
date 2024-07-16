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

#define MOD 1000000007

void solve() {
    int n, m; 
    cin >> n >> m;

    vector<pair<int, int>> line;

    for(int i=0; i<m; i++) {
        int x, y; 
        cin >> x >> y;
        line.push_back({y, 0});
        line.push_back({x, 1});
        line.push_back({x-1, 2});
    }

    sort(line.begin(), line.end());

    map<int, int> dp;
    int sum = 0;

    int l = line.size();

    int last_removed = -1;

    for(int i=l-1; i>=0; i--) {
        auto& p = line[i];

        if(p.first == n) {
            sum += 1;
        }
        else if(p.second == 0) {
            sum = (2 * sum) % MOD;
            last_removed = -1;
        }
        else if(p.second == 1) {
            dp[p.first] = sum;
            last_removed = -1;
        }
        else {
            if(p.first + 1 == last_removed) {
                continue;
            }
            sum = (sum - dp[p.first+1] + MOD) % MOD;       
            last_removed = p.first+1;     
        }
    }

    cout << dp[0] << endl;
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
