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

void dfs(int curr, vector<pair<int,int>>& points, vector<char>& isReach){
    isReach[curr] = true;
    for(int i=0; i< points.size(); i++){
        if(isReach[i]){
            continue;
        }
        pair<int,int>  pcurr = points[curr];
        pair<int,int> pi = points[i];
        if(pi.first == pcurr.first || pi.second == pcurr.second){
            dfs(i, points, isReach);
        }
    }
}


void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> points(n);

    for(int i=0;i<n;++i){
        int x,y;
        cin >> x >> y;
        points[i] = make_pair(x,y);
    }

    vector<char> isReach(n, false);

    int ans =0;

    for(int i=0;i<n ; ++i){
        if(!isReach[i]){
            ++ans;
            dfs(i, points, isReach);
        }
       
    }

    cout << ans-1 << endl;
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
