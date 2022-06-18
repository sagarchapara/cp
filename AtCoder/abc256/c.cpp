// g++ -o out <filename>.cpp
// .\out.exe

// #define SAGAR

#include <bits/stdc++.h>
using namespace std;                                    


/*
 *==========================================
 * Input 
 *==========================================
 */
void read(){}
void read(long long& a){scanf("%lld",&a);}
void read(long& a){scanf("%ld",&a);}
void read(int& a){scanf("%d",&a);}
void read(double& a){scanf("%lf",&a);}
void read(float& a){scanf("%f",&a);}
void read(string& a){cin>>a;}
template<typename x>void read(x& a){for(auto  &i : a) read(i);}
template<typename x,typename y>void read(pair<x,y>& a){ read(a.first),read(a.second);}
template<typename... x>void read(x&... a){((read(a)), ...);}


/*
 *==========================================
 * Output and Debug
 *==========================================
 */

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
    vi row(3);
    vi col(3);
    cin >> row[0] >> row[1] >> row[2] >> col[0] >> col[1] >> col[2];

    int ans = 0;
    
    for(int a = 1;a<= min(row[0]-2,col[0]-2);a++){
        for(int b = 1 ; a+b <= row[0]-1;b++){
            for(int e = 1; e+a <=col[0]-1;e++){
                for(int f = 1;e+f<=row[1]-1 && b+f<= col[1]-1;f++){
                    int h = col[0]-a-e;
                    int i = col[1]-b-f;
                    int c = row[0]-a-b;
                    int g = row[1]-e-f;
                    
                    if(row[2]-h-i == col[2]-g-c){
                        int j = col[2]-g-c;
                        if(a>0 & b>0 && c>0 && e>0 && f>0  &&g>0 && i>0 && j>0){
                            ans++;
                        }
                    }
                }
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
