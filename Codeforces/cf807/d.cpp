// g++ -o out <filename>.cpp -D SAGAR
// .\out.exe

#include <bits/stdc++.h>
using namespace std;                                    

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x << " "; return os;}
void dbg_out() { cerr << "" << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H ; dbg_out(T...); }
#ifdef SAGAR
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define pi pair<int,int>
#define vi vector<int>
#define vpi vector<pi>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    vi arr1(n-1), arr2(n-1);
    int num1 =0, num2 =0; int ans =0; int curr1 =0, curr2 =0;
    if(s[0]!= t[0] || s[n-1]!=t[n-1]) goto bad;
    rep(i,1,n){
        arr1[i-1] = (s[i]-'0')^(s[i-1]-'0');
        arr2[i-1] = (t[i]-'0')^(t[i-1]-'0');
        num1+=arr1[i-1]; num2+=arr2[i-1];
    }
    if(num1 != num2) goto bad;
    
    for(int i=0;i<num1;i++){
        while(arr1[curr1] == 0){
            curr1++;
        }
        while(arr2[curr2] == 0){
            curr2++;
        }
        ans+= abs(curr1 - curr2);
        curr1++; curr2++;
    }

    cout << ans << endl;
    return;

    bad:
        cout << -1 << endl;
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
