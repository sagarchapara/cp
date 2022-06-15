// g++ -o out <filename>.cpp
//  cmd /c '.\out.exe < input.txt'

// #define LOCAL

#include <bits/stdc++.h>                                    

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define mp make_pair
#define pb push_back

void solve() {
    string digits;

    cin >> digits;

    dbg(digits);
    //remove the first zero
    int n = digits.size();
    int i =0;

    while(i< n && digits[i]=='1'){
        i++;
    }

    if(i == n){
        for(int j=0;j<n-1;j++){
            cout << 1;
        }
    }
    else{
        for(int j=0;j< n ;j++ ){
            if(j!=i){
                cout << digits[j];
            }
        }
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
