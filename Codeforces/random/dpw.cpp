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

struct Interval
{
    int start;
    int end;
    int cost;
    Interval(int s, int e, int c): start(s), end(e), cost(c){}
};


void solve() {
    int n, m; cin >> n >> m;

    vector<int> cnt(n+1, 0);

    vector<Interval> intervals;

    map<int, vector<pair<int, int>>> pos;

    for(int i=0;i<m;i++){
        int x, y, c; cin >> x >> y >> c;

        cnt[x]+=c;

        if(y+1 <= n){
            cnt[y+1]-=c; 
        }

        Interval itr(x, y, c);

        intervals.push_back(itr);

        pos[x-1].push_back({i, -1});
        pos[y].push_back({i,1});
    }

    for(int i=1;i<=n;i++){
        cnt[i]+= cnt[i-1];
    }

    dbg(cnt);

    //let's sort the intervals
    vector<int> dp (n+1, 0);

    set<pair<int, int>> max_right;

    int ans =0;

    for(int i=n;i>=0;i--){
        for(auto& p : pos[i]){
            if(p.second == 1){
                //insert into set
                max_right.insert({intervals[p.first].end, p.first});
            }
            else{
                max_right.erase({intervals[p.first].end, p.first});
            }

            if(i == n){
                dp[i] = cnt[i];
                continue;
            }

            dp[i] = dp[i+1];

            if(max_right.size() == 0){
                continue;
            }

            int right = max_right.rbegin()->first;

            int val = cnt[i];

            if(right + 1 <= n){
                val += dp[right+1];
            }

            dp[i] = max(val, dp[i]);
        }

        ans = max(ans, dp[i]);
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
