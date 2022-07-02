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

const int MOD = 1e9+7;

vi zfunc(string s, int n){
    vi z(n);
    z[0]= 0;
    for(int i =1, l=0, r=0; i<n;i++){
        if(i<=r){
            z[i] = min(z[i-l], r-i+1);
        }
        while(i+z[i]< n && s[i+z[i]]==s[z[i]]){
            ++z[i];
        }
        if(i+z[i]-1 > r){
            l =i, r = i+z[i]-1;
        }
    }

    return z;
}

void solve() {
    string s, t; cin >> s >> t;

    if(t.size() > s.size()){
        cout << 0;
        return;
    }

    string sp = t + '$'+ s;

    vi z = zfunc(sp, sz(sp));

    //find all starting positions
    vi arr; int t_size = t.size(); int s_size = s.size();

    for(int i = t_size+1;i < sz(sp); i++){
        if(z[i] == t_size){
            arr.push_back(i-t_size-1);
        }
    }

    if(arr.size()==0){
        cout << 0;
        return;
    }
    int n = arr.size();

    vector<vi> dp(n, vi(2));

    int eidx = (arr[n-1]+t_size-1);
    dp[n-1][0] = dp[n-1][1] =(s_size-eidx+1);

    for(int i=n-2;i>=0;i--){
        int t = dp[i+1][0]/(s_size-eidx+1) ;
        
        int currIdx = arr[i+1]-arr[i] - 

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
