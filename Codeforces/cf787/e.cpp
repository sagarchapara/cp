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
    int n, k; cin >> n >>k;
    string s; cin >> s;
    vi pos(26);   rep(i,0,26) pos[i] = i; int prev_max = 0;

    rep(i,0,n){
        int num = k;
        int curr = s[i]-'a';
        dbg(curr);
        if(curr <= prev_max) continue;
        else{
            if(curr <= num){
                prev_max = curr;
            }
            else{
                num-=prev_max;
                dbg(curr); dbg(num);

                int to = curr - num;
                for(int j= curr; j>to;j--){
                    pos[j] = to;
                }
                break;
            }
        }
    }

    for(int j=0;j<=prev_max;j++){
        pos[j] =0;
    }

    dbg(pos);

    string ans;
    rep(i,0,n){
        char c = ('a'+ pos[s[i]-'a']);
        ans+=c;
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
