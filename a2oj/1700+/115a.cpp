// g++ -o out <filename>.cpp
// cmd /c '.\out.exe < input.txt'

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

void dfs(int curr, vector<vector<int>>& emp, vector<int>& dep, int& ans){
    int curr_depth = 1;
    for(int c: emp[curr]){
        if(dep[c]==-1){
            dfs(c, emp, dep, ans);
        }
        curr_depth = max(1+ dep[c], curr_depth);
    }
    dep[curr] = curr_depth;

    ans = max( ans, curr_depth);
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> emp(n);

    vector<int> dep(n, -1);

    for(int i=0;i<n;i++){
        int man;
        cin >> man;
        if(man!=-1){
            emp[man-1].push_back(i);
        }    
    }

    dbg(emp);

     int ans =0;
    for(int i=0;i<n;i++){
        if(dep[i]==-1){
            dfs(i, emp, dep, ans);
        }
    }

    dbg(dep);

    cout << ans << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
