//  cmd /c '.\out.exe < input.txt'

#include <bits/stdc++.h>
// #define LOCAL                                    

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

void dfs(int curr, int par,vector<int>& val, vector<vector<int>>& edges, vector<pair<int,int>>& maxmin){

    int min= 0, max =0 , max_pos =0 , max_neg =0;
    for(auto itr = edges[curr].begin(); itr!= edges[curr].end(); ++itr){
        if(*itr != par){
            dfs(*itr, curr, val, edges, maxmin);
            pair<int,int> cnt = maxmin[*itr];
            max_pos = std::max(cnt.second, max_pos);
            max_neg = std::max(cnt.first, max_neg);
        }
    }

    val[curr] -= max_pos - max_neg;
    if(val[curr] >0){
        max_pos += val[curr];
    }
    else{
        max_neg -=val[curr];
    }

    maxmin[curr] = make_pair(max_neg, max_pos);  
}

void solve() {
    int n;
    cin >> n;

    vector<int> val (n);
    vector<vector<int>> edges(n);
    vector<pair<int,int>> maxmin(n);

    for (int i=0;i<n-1;i++){
        int to, fro;
        cin >> to >> fro;
        edges[to-1].pb(fro-1);
        edges[fro-1].pb(to-1);
    }

    for(int i=0;i<n;i++){
        cin >> val[i];
    }

    int ans =0;

    dfs(0, -1, val, edges, maxmin);

    cout << (maxmin[0].first + maxmin[0].second) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;

    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
