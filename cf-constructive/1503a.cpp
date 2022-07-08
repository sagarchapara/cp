// g++ -o out <filename>.cpp
// .\out.exe

#define SAGAR

#include <bits/stdc++.h>
using namespace std;                                    

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x ; return os;}
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
    string s; cin >> s;
    int curr =0; vector<char> ans1(n), ans2(n); int ones =0, zeros =0, num1=0, num2 =0;
    if(s[0] == '0' || s[n-1] == '0') goto bad; 

    for(int i=0;i<n;i++){
        if(s[i] == '0') zeros++;
        else ones++;
    }
    if(ones%2 !=0 ) goto bad;

    for(int i=0;i<n;i++){
        if(s[i] == '1'){
            if(num1< (ones/2)) ans1[i] = ans2[i] = '(';
            else ans1[i] = ans2[i] = ')';
            num1++;
        }
        else{
            if(num2%2==0){
                ans1[i] = '('; 
                ans2[i] = ')';
            }
            else{
                ans1[i] = ')'; 
                ans2[i] = '(';
            }
            num2++;
        }
    }

    cout << "YES" << endl;
    cout << ans1 << endl;
    cout << ans2 << endl;
    return;

    bad:
        cout << "NO" << endl;
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
