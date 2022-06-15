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
#define pi pair<int,int>
#define pii pair<pair<int,int>,int>

void solve() {
    int n , m, k;
    cin >> n >> m >> k ;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    vector<pii> op(m);
    for(int i=0;i<m ;i++){
        int l, r, d;
        cin >> l >> r >> d;
        op[i] = make_pair(make_pair(l-1,r-1), d);
    }

    vector<pi> quers(k);
    for(int i=0;i<k ;i++){
        int x,y;
        cin >> x >> y;
        quers[i] = make_pair(x-1,y-1);
    }

    vector<int> sum(m, 0);

    for(int i=0;i< k ;i++){
        sum[quers[i].first]++;
        if(quers[i].second +1 < m){
            sum[quers[i].second+1]--;
        }
    }

    for(int i=1;i<m;i++){
        sum[i]+=sum[i-1];
    }

    vector<int> cnt(n ,0);
    for(int i=0;i<m;i++){
        cnt[op[i].first.first]+= (sum[i]*op[i].second);

        if(op[i].first.second+1 < n){
            cnt[op[i].first.second+1]-= (sum[i]*op[i].second);
        } 
    }

    for(int i=1;i<n;i++){
        cnt[i]+=cnt[i-1];
    }



    dbg(arr);
    dbg(op);
    dbg(quers);
    dbg(cnt);
    dbg(sum);


    for(int i=0;i< n;i++){
        cout << arr[i]+cnt[i] << " ";
    }
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
