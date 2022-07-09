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
    vi a(n), b(n);
    for(int &x: a) cin >> x;
    for(int &x: b) cin >> x;

    vi sa(a), sb(b);

    vpi moves;

    sort(all(sa)); sort(all(sb));
    int curr =0;

    while(curr < n){
        bool found = false;
        rep(i,curr,n){
            if(sa[i]==a[curr] && sb[i]==b[curr]){
                found = true;
                swap(sa[i], sa[curr]);
                swap(sb[i], sb[curr]);
                if(curr!=i) moves.push_back({curr+1, i+1});
                break;
            }
        }
        if(!found) goto bad;
        curr++;
    }

    cout << moves.size() << endl;
    for(auto itr = moves.rbegin(); itr!= moves.rend(); itr++){
        cout << (*itr) << endl;
    }

    return;

    bad:
        // dbg(moves);
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
