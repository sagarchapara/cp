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

void dfs(int curr, int par, vector<vector<pair<int,int>>>& edges, vector<int>& arr, vector<int>& count){
    int ans =0;
    bool shouldPush = false;
    for(pair p: edges[curr]){
        int to = p.first;
        int w = p.second;
        if(to != par){
            dfs(to, curr, edges, arr, count);
            if(arr[to]>0){
                ans+=arr[to];
            }
            else if(w == 2){
                ans+=1;
                count.push_back(to+1);
            }
        }
    }
    arr[curr] = ans;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<pair<int,int>>> edges(n);

    for(int i=0;i<n-1;i++){
        int to, fro, w;
        cin >> to >> fro >> w;

        edges[to-1].push_back(make_pair(fro-1, w));
        edges[fro-1].push_back(make_pair(to-1, w));
    }

    dbg(edges);

   

    vector<int> arr(n,0);
    vector<int> points;

    dfs(0, -1, edges, arr, points);

    cout << arr[0] << endl;

    cout << points;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef SAGAR
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
