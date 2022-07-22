// g++ -o out <filename>.cpp -D SAGAR
// .\out.exe

#include <bits/stdc++.h>
using namespace std;                                    

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x << " "; return os;}
void dbg_out() { cerr << "" << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << " " ; dbg_out(T...); }
#ifdef SAGAR
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define pi pair<int,int>
#define pii pair<int,pi>
#define vi vector<int>
#define vpi vector<pii>
#define vvpi vector<vpi>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define sz(x) (int)(x).size()

char find(int k, int idx, vvpi& arr, vi& pref, string& s, int c, int n){
    // dbg(k);
    if(idx == 0){
        return s[k];
    }
    else{
        //find next index of k
        int t = 0;
        for(auto [i, p]: arr[idx]){
            auto [u,v] = p;
            if((t + (v-u+1)) > k){
                //means it belongs here
                int diff = k - t;
                int next = diff + u;
                return find(next, i, arr, pref, s, c, n);
            }
            t+= (v-u+1);
        }
        // cout << s << endl;
    }
    
    return 0;
}



void solve() {
    int n, c,q ; cin >>  n >> c >> q;

    // dbg(n,c,q);

    string str; cin >> str;
    vvpi arr(c+1); vi pref(c+1,0);

    pref[0] = n;
    arr[0].push_back({0, {0,n-1}});

    rep(i,1,c+1){
        int l,r; cin >> l >> r; l--, r--;
        pref[i] = (r-l+1)+pref[i-1];

        //find idx in which l lies
        int idx;
        for(int j=0;j<i;j++){
            if(pref[j]>l){
                idx = j; break;
            }
        }
        int curr =l;
        for(int j=idx;j<i;j++){
            if(curr >= r) break;
            int num = (j==0) ? 0 : pref[j-1];
            arr[i].push_back({j, {max((l-num),0ll), min(r-num, pref[j]-num-1)}});
            curr = min(r, pref[j]-1);
        }
    }

    // dbg(pref);
    // dbg(arr);

    rep(i,0,q){
        int k; cin >> k; k--;
        int idx;
        rep(j,0,c+1) if(pref[j]>k) {idx =j; break;}

        int num = (idx ==0)? 0 : pref[idx-1];

        char t = find(k-num, idx, arr, pref, str, c, n);

        cout << t << endl;
    }



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
