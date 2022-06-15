// g++ -o out <filename>.cpp
// cmd /c '.\out.exe < input.txt'

#define SAGAR

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

int cnt;

void dfs(int curr, string& f, int count, int& ans, int& total){
    int n = f.size();
    if(curr == n){
        if(cnt == count){
            ++ans;
        }
        ++total;
        return;
    }
    else{
        if(f[curr]== '?'){
            dfs(curr+1, f, count+1, ans, total);
            dfs(curr+1, f, count-1, ans, total);
        }
        else if(f[curr] == '+'){
            dfs(curr+1, f, count+1, ans, total);
        }
        else{
            dfs(curr+1, f, count-1, ans, total);
        }
    }
}

void solve() {
    string a, f ;
    read(a, f); //dbg(a, f);

    cnt =0;
    int n = a.size();
    for(auto itr = a.begin(); itr!= a.end();++itr){
        if (*itr == '+'){
            ++cnt;
        }
        else{
            --cnt;
        }
    }

    int ans =0;
    int total =0;
    dfs(0, f, 0, ans, total);

    //dbg(ans, total);

    double prob = (ans*1.0)/(total*1.0);
    cout << prob;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    cout.precision(12);
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
