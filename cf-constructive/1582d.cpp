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

void solve() {
    int n; cin >> n;
    vi arr(n); for(int &x: arr) cin >> x;

    vi ans(n);

    int num = n/2;
    if(n%2==0){ 
        for(int i=0;i<num;i++){
            int l = lcm(abs(arr[i]), abs(arr[n-1-i]));
            ans[i] = l/arr[i];
            ans[n-1-i] = (-1)*(l/arr[n-1-i]);
        }
    }
    else{
        for(int i=0;i<num-1;i++){
            int l = lcm(abs(arr[i]), abs(arr[n-1-i]));
            ans[i] = l/arr[i];
            ans[n-1-i] = (-1)*(l/arr[n-1-i]);
        }
        int sum = arr[num-1]+ arr[num];

        if(sum!=0){
            int l = lcm(abs(sum), abs(arr[num+1]));
            ans[num-1] = ans[num] = l/(sum);
            ans[num+1] = (-1)*(l/arr[num+1]);
        }
        else{
            sum = arr[num-1]-arr[num];
            int l = lcm(abs(sum), abs(arr[num+1]));
            ans[num-1] = l/(sum);
            ans[num] = -1*ans[num-1];
            ans[num+1] = (-1)*(l/arr[num+1]);
        }    

        
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

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
