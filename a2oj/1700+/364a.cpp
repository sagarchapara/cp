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
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define sz(x) (int)(x).size()



void solve() {
    int total ; cin >> total;
    string s; cin >> s; int n = sz(s);
    
    int uq_sum[(n*9)+5] ={};

    int ans =0, tc=0;

    rep(i,0,n){
        int sum = (s[i]-'0');
        rep(j,i+1,n+1){
            uq_sum[sum]++;
            if(j<n) {
                sum+= (s[j]-'0');
            }
        }
    }


    
    for(int i=0;i<((9*n)+5);i++){
        int sum1 = i; int val1 = uq_sum[i];
        dbg(sum1); dbg(val1);
        if(total == 0 && sum1==0){
            // dbg("a");
            ans+= val1*(n*(n+1)/2);
        }
        else if (total == 0){
            // dbg("b");
            ans+= (uq_sum[0])*val1;
        }
        else if(sum1 ==0){
            continue;
        }
        else{
            if((total% sum1)==0){
                int k = (total/sum1);
                if(k > 9*n) continue;
                int it = uq_sum[(total/sum1)];
                ans+= (it)*val1;
            }
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
