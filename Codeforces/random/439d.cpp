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
#define vvi vector<vi>
#define vpi vector<pi>
#define vvpi vector<vpi>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define sz(x) (int)(x).size()

int check(int k, vector<int>& a, vector<int>& b){
    //a should be mininzed and b should be maximized

    int ans = 0;
    for(int i: a){
        ans += max(0ll, k-i);
    }

    for(int i: b){
        ans += max(0ll,i-k);
    }

    return ans;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);

    int min_val = 1e9+5;
    int max_val = 0;

    for(int i=0;i<n;i++){
        cin >> a[i];
        min_val = min(a[i], min_val);
        max_val = max(a[i], max_val);
    }
    
    for(int i=0;i<m;i++){
        cin >> b[i];
        min_val = min(b[i], min_val);
        max_val = max(b[i], max_val);
    }

    int l = min_val, r = max_val;

    dbg(a, b);

    dbg(l,r);

    while (r-l>2)
    {
        int l1 = l + ((r-l)/3);
        int l2 = r - ((r-l)/3);

        int val1 = check(l1, a, b);
        int val2 = check(l2, a, b);

        if(val1 == val2){
            l = l1;
            r = l2;
        }
        else if(val1 < val2){
            r = l2;
        }
        else{
            l = l1;
        }

        dbg(l,r,l1,val1,l2, val2);
    }

    int ans;

    for(int i=l;i<=r;i++){
        if(i == l){
            ans = check(i, a, b);
        }
        else{
            ans = min(ans, check(i,a,b));
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

    auto start = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }

    auto stop = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();

    #ifdef SAGAR
		cerr << "Took " << stop - start << "ms" << endl;
	#endif
}
