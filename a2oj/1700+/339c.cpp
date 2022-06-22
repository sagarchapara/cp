// g++ -o out <filename>.cpp
// .\out.exe

#define SAGAR

#include <bits/stdc++.h>
using namespace std;                                    

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

int dp[10005][10][10];
int m;
vi arr(10);
int max_ans =0;

int dfs(int sum, int diff, int prev){
    if(sum >=10005 || diff >=10 || prev > 10 || diff <0 || sum <0 || prev<0){
        return 0;
    }
    if(dp[sum][diff][prev]!=-1){
        return dp[sum][diff][prev];
    }
    int ans = 0;
    rep(i,1,11){
        if(arr[i-1]>0 && prev!=i){
            if(i>diff){
                int nxt_sum = sum+i;
                int nxt_diff = i-diff;
                ans = max(1+dfs(nxt_sum, nxt_diff, i), ans);
            }
        }
    }

    dp[sum][diff][prev] =ans;
    // dbg(sum); dbg(diff); dbg(prev);
    max_ans = max(ans, max_ans);
    return ans;
}

vi edges;

void find(int sum, int diff, int prev, int dpt){
    if(dpt <=0){
        return;
    }
    if(sum >=10005 || diff >=10 || prev > 10 || diff <0 || sum <0 || prev <0){
        return;
    }
    if(dp[sum][diff][prev] < dpt){
        return;
    }

    rep(i,1,11){
        if(arr[i-1]>0 && prev!=i){
            if(i>diff){
                int nxt_sum = sum+i;
                int nxt_diff = i-diff;
                if(dfs(nxt_sum, nxt_diff, i) >= (dpt-1)){
                    // dbg(i);
                    edges.push_back(i);
                    find(nxt_sum,nxt_diff,i,dpt-1);
                    return;
                }
            }
        }
    }
}

void solve() {
    string s ; cin >> s;
    rep(i,0,10) arr[i] = s[i]-'0';
    cin >> m;
    fill_n(&dp[0][0][0], 10005*10*10, -1);

    max_ans = 0;

    int ans = dfs(0, 0, 0);

    // dbg(max_ans);

    if(max_ans < m){
        cout << "NO" << endl;
        return;
    }
    else{
        cout << "YES" <<endl;

        find(0,0,0,m);

        cout << edges << endl;
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

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
