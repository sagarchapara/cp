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

int dp[20][11][2];

int num_values(string& s, int curr, int prev, int tight){
    if(curr  == s.size()){
        return 1;
    }

    if(dp[curr][prev][tight] != -1){

        dbg(s, curr, prev, tight, dp[curr][prev][tight]);

        return dp[curr][prev][tight];
    }

    //now number of ways for current digit
    int d = s[curr] - '0';

    dbg(d);

    int ans = 0;

    int limit = tight ? d : 9;

    for(int i=limit;i>=0;--i){
        if(i != prev){
            ans += num_values(s, curr+1, i, tight && (i==d));
        }
    }

    return dp[curr][prev][tight] = ans;
}

int count_values(int num) {
    string s = to_string(num);

    dbg(s);

    memset(dp, -1, sizeof(dp));
    return num_values(s, 0, 10, 1);
}

void solve() {
    int l, r;

    cin >> l >> r;

    dbg(count_values(r), r);

    dbg(count_values(l-1), l-1);

    dbg(count_values(10), count_values(9));

    int ans = count_values(r) - count_values(l-1);
    
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
