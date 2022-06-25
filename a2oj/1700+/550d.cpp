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

// #define int long long
#define F first
#define S second
#define pi pair<int,int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define sz(x) (int)(x).size()

void print(int a, int b){
    printf("%d %d\n", a, b);
}

void solve() {
    int k; cin >> k;

    if(k%2==0){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    int nv = 2*(k*k - k +1);
    int ne = (k-1)*(k-1)*(k+1) + (2*k) -1 ;

    cout << nv << " " << ne << endl;

    int offset = (k*k) - k + 1;
    int prim = 1, sec = offset + prim;
    
    // cout << prim << " " << sec << endl ;
    print(prim, sec);


    for(int i=2;i<=k;i++){
        int ioff  = i+offset;
        // cout << 1 << " " << (i) << endl;
        print(1,i);
        print(sec, ioff);
        // cout << sec << " " << (ioff) << endl;
    }

    int start = k+1;
    for(int rep =0; rep <(k-1); rep++){
        for(int i = 0; i<(k-1); i++){
            int l1 = (start+i), l2 = (start+offset+i), r1 = (rep+2), r2 = (offset+ rep+2);
            // cout << l1 << " " << r1 << endl;
            print(l1, r1);
            print(l2, r2);
            // cout << l2 << " " << r2 << endl;
            for(int j= i+1 ; j<(k-1); j++){
                l1 = (start+i), l2 = (start+offset+i), r1 = (start+j), r2 = (offset+start+j);
                // cout << (l1) << " " << (r1) << endl;
                print(l1,r1);
                print(l2,r2);
                // cout << (l2) << " " << (r2) << endl;
            }
        }
        if(rep%2==0){
            for(int i=0;i<(k-1);i++){
                int l1 = (start+i), l2 = (start+offset+i), r1 = (start+(k-1)+i), r2 = (start+(k-1)+i+offset);
                // cout << l1 << " "<< r1 << endl;
                // cout << l2 << " "<< r2 << endl;
                print(l1,r1);
                print(l2,r2);
            }
        }
        start+= (k-1);
    }

    // cout << num;    
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
