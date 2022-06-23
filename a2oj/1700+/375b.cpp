// g++ -o out <filename>.cpp
// .\out.exe

// #define SAGAR

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
#define rall(x) (x).rbegin(), (x).rend()
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define sz(x) (int)(x).size()

vector<int> nextLesserElem(vector<int>& v){
    stack<int> s;

    int n = v.size();

    vector<int> ans(n, n);
    s.push(0);

    for(int i=1;i<n;i++){
        while(!s.empty() && v[i] < v[s.top()]){
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    return ans;
}

void solve() {
    int n,m; cin >> n >> m;
    vector<vi> arr(n, vi(m));

    rep(i,0,n){
        string s; cin >> s;
        rep(j,0,m){
            arr[i][j] = (s[j]-'0');
        }
    }

    vector<vi> suff(m, vi(n,0));

    rep(i,0,n){
        vi nle = nextLesserElem(arr[i]);
        rep(j,m,0){
            if(arr[i][j]==1){
                suff[j][i] = (nle[j]-j);
            }
        }
    }

    // dbg(suff);

    int ans =0;
    rep(i,0,m){
        sort(rall(suff[i]));
        rep(j,0,n){
            ans = max(ans, suff[i][j]*(j+1));
        }
    }

    cout << ans;
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
