// g++ -o out <filename>.cpp
// .\out.exe

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
#define pi pair<int,int>

// bool cmp(pi a, pi b) { return a.second < b.second; }

pair<bool,int> isPossible(int k, int n, int m, int a, vector<int>& money, vector<int>& bikes){
    
    dbg(k);
   
    int rem = a;

    pair<bool, int> ans(false,0);

    int sum =0;

    for(int i=n-k;i<n;i++){
        dbg(rem);
        dbg(bikes[i-n+k]);
        dbg(money[i]);
        if(rem<0){
            return ans;
        }
        else if(rem + money[i] >= bikes[i-n+k]){
            rem-= max(0ll, bikes[i-n+k]-money[i]);
            
            sum+= min(money[i],bikes[i-n+k] );
        }
        else{
            return ans;
        }
        dbg(rem);
    }

    ans.first = true;
    ans.second = sum;

    return ans;
}

void solve() {
    int n , m ,a;
    cin >> n >> m >> a;

    dbg(n, m ,a);

    vector<int> money(n);
    for(int i=0;i<n;i++){
        int b;
        cin >> money[i];
    }

    sort(all(money));

    dbg(money);

    vector<int> bikes(m);
    for(int i=0;i<m;i++){
        cin >> bikes[i];
    }

    sort(all(bikes));

    dbg(bikes);
    
    int start =1 , end = min(m,n);

    while(end-start > 1){
        int mid = (start+end)/2;
        
        if(isPossible(mid,n,m,a,money,bikes).first){
            start = mid;
        }
        else{
            end = mid-1;
        }
    }

    bool isTrue = false;

    int max_ans, min_sum;

    for(int i=end; i>=start;i--){
        auto p= isPossible(i,n,m,a,money,bikes);
        if(p.first){
            isTrue = true;
            max_ans = i;
            min_sum = p.second;
            break;
        }
    }

    if(!isTrue){
        cout << 0 << " " << 0;
    }



    cout << max_ans << " " << min_sum ;

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
