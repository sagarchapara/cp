// g++ -o out <filename>.cpp -D SAGAR
// .\out.exe

#include <bits/stdc++.h>
using namespace std;                                    

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x << " "; return os;}
void dbg_out() { cerr << "" << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << " " ; dbg_out(T...); }
#ifdef SAGAR
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define float long double
#define pi pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vpi vector<pi>
#define vvpi vector<vpi>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define sz(x) (int)(x).size()

void solve() {
    int k; cin >> k;

    int n = 8;

    float dp [n*n][n][n][k+1] = {0.0};


    
    for(int kk=0;kk<k;kk++){
        for(int num=0;num<n*n;num++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(kk == 0){
                        if(i*8+j == num){
                            dp[num][i][j][kk] = 1.0;
                        }
                    }

                    int x[4] = {-1,0,1,0};
                    int y[4] = {0,-1,0,1};

                    int num_val = 0;

                    for(int z =0;z<4;z++){
                        if((i+x[z]>=0) && (i+x[z]<n) && (j+y[z]>=0) && (j+y[z]<n)){
                            num_val++;
                        }
                    }

                    for(int z =0;z<4;z++){
                        if((i+x[z]>=0) && (i+x[z]<n) && (j+y[z]>=0) && (j+y[z]<n)){
                            dp[num][i+x[z]][j+y[z]][kk+1] += (dp[num][i][j][kk]*1.0/num_val);
                        }
                    }
                }
            }
        }
    }

    float ans = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            float t = 1.0;
            for(int num=0;num<n*n;num++){
                t *= (1.0 - dp[num][i][j][k]);
            }

            // dbg(t);
        
            ans += (t);
        }
    }

    printf("%.8Lf\n", ans);
}

int32_t main() {
    #ifdef SAGAR
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
    #endif

    auto start = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }

    auto stop = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();

    #ifdef SAGAR
		cerr << "Took " << stop - start << "ms" << endl;
	#endif
}
