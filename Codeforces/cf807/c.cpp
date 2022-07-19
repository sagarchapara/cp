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
#define vi vector<int>
#define vpi vector<pi>
#define vvpi vector<vpi>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define sz(x) (int)(x).size()

void solve() {
    int n, c,q ; cin >>  n >> c >> q;

    // dbg(n,c,q);

    string str; cin >> str;
    vvpi arr(c+1); vi pref(c+1,0);

    pref[0] = n;
    arr[0].push_back({0,n-1});

    rep(i,1,c+1){
        int l, r; cin >> l >> r; l--, r--;

        pref[i] = (r-l+1) + pref[i-1];

        //find the pref in which l lies;
        int idx;
        rep(j,0,i){
            if(pref[j]>l){
                idx =j; 
                break;
            }
        }

        // dbg(idx);


        // need to insert all 
        bool filled  = false;

        int p = (idx > 0) ? pref[idx-1] : 0;

        while(p <= r){
            for(auto [s,e]: arr[idx]){
                if(p > r) break;

                if(!filled){
                    if ( p+ (e-s) < l){
                        p += (e-s+1);
                    }
                    else{
                        int left = s + (l-p);

                        arr[i].push_back({left, s+ min(r-p, e-s)});
                        p = min(r+1, p+(e-s+1));
                        filled = true;             
                    }
                }
                else{
                    if(p + (e-s) >= r){
                        //we have end here
                        arr[i].push_back({s, s+ min(r-p, e-s)});
                        p = min(r+1, p+(e-s+1));
                        break;
                    }
                    else{
                        arr[i].push_back({s,e});
                        p+= (e-s+1);
                    }
                }
            }
            idx++;
        }
        
    }

    dbg(arr);
    // dbg(str);
    // dbg(pref);

    rep(i,0,q){
        int k; cin >> k; k--;
        int idx;
        // dbg(k);

        for(int j=0;j<(c+1);j++){
            if(pref[j] > k){
                idx = j;
                break;
            }
        }
        // dbg(idx);

        int start = (idx>0)? pref[idx-1]: 0;
        for(auto [s,e]: arr[idx]){
            if(start + (e-s) >= k){
                //answer lies here
                dbg(start, s, e, k);
                cout << str[s + (k-start)] << endl;
                break;
            }
            else{
                start+=(e-s+1);
            }
        }
    }
    return;

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
