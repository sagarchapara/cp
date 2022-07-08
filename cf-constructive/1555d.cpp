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

void solve() {
    int n, m ; cin >> n >> m;
    string s; cin >> s;
    int pref[n][3][3] = {0};

    for(int i=0;i<n;i++){
        pref[i][i%3][s[i]-'a']++;     
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                pref[i][j][k]+=pref[i-1][j][k];
            }
        }
    }

    for(int i=0;i<m;i++){
        int l, r; cin >> l >> r; l--, r--;

        int size = r-l+1;
        if(size == 1){
            cout << 0 << endl;
            continue;
        }
        if(size == 2){
            if(s[l]==s[r]){
                cout << 1 << endl;
                continue;
            }
            else{
                cout << 0 << endl;
            }
            continue;
        }
        
        int curr[3][3];
        
        rep(j,0,3){
            rep(k,0,3){
                curr[j][k] = pref[r][j][k];
                if(l>0){
                    curr[j][k]-=pref[l-1][j][k];
                }
            }   
        }
        
        int ans = r-l+1;

        int mod = l%3;

        for(int ii=0;ii<3;ii++){
            for(int jj=0;jj<3;jj++){
                if(ii!=jj){
                    int kk = 3-ii-jj;
                    int a = curr[(mod+0)%3][ii];
                    int b = curr[(mod+1)%3][jj];
                    int c = curr[(mod+2)%3][kk];

                    int req = size - a - b - c;

                    ans = min(req, ans);
                }
            }
        }

        cout << ans << endl;
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
