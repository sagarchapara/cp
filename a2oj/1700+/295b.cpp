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
#define all(x) (x).begin(), (x).end()

const int INF = 1e10;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> arr (n, vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }

    auto dist(arr);

    vector<int> vert (n);
    for(int i=0;i<n;i++){
        cin >> vert[i];
    }

    reverse(all(vert));

    vector<int> ans;
    set<int> comv;

    for(int rem: vert){
        int curr_ans =0;
        
        for(int i: comv){
            for(int j:comv){
                dist[i][rem-1] = min(dist[i][rem-1], dist[i][j]+ dist[j][rem-1]);
                dist[rem-1][i] = min(dist[rem-1][i], dist[rem-1][j] + dist[j][i]); 
            }
            curr_ans+= dist[i][rem-1] + dist[rem-1][i];
        }

        comv.insert(rem-1);

        for(int i: comv){
            for(int j: comv){
                if((i== rem-1) || (j == rem-1)){
                    continue;
                }
                else{
                    dist[i][j] = min(dist[i][j], dist[i][rem-1]+dist[rem-1][j]);
                    curr_ans+=dist[i][j];
                }
            }
        }

        ans.push_back(curr_ans);
    }

    reverse(all(ans));

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
