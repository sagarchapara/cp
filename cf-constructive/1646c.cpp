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


const int nbits = 40;
const int nf = 20;
const int total = (1<<nf);

int fac[nf];
int sum[total];

void compute(){
    int num = 1;fac[0] = fac[1] = 1;
    for(int i=2;i<nf;i++){
        num*=i; fac[i] =num;
    }

    for(int i=1;i<total;i++){
        int s=0;
        for(int j=0;j<nf;j++){
            if(i&(1<<j)){
                s+=fac[j];
            }
        }
        sum[i] = s;
    }
}

void solve() {
    int n; cin >> n; int ans = nbits+1;
    

    for(int i=0;i<total;i++){
        int t = 0; int mask = n;
        if(mask>= sum[i]){
            t += __popcount(i);
            mask-=sum[i];    
        }

        for(int i=0;i<nbits;i++){
            if(mask&(1ll<<i)){
                t++;
            }
        }
        ans = min(ans, t);
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

    compute();

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
