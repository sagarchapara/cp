// g++ -o out <filename>.cpp -D SAGAR
// .\out.exe

#include <bits/stdc++.h>
using namespace std;                                    

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x << " "; return os;}
void dbg_out() { cerr << "" << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << " "; dbg_out(T...); }
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

int find(int k){
    int l = 1, r = 1e5;

    while(r-l>1){
        int mid = (l+r)/2;

        int p = mid*(mid-1);

        if(mid*(mid-1) == 2*k) return mid;
        else if( p < 2*k) l = mid+1;
        else r = mid-1;
    }

    rep(i,l,r+1){
        if(i*(i-1) == 2*k) return i;
    }

    return -1;
}

void solve() {
    int arr[2][2];
    rep(i,0,2) rep(j,0,2) cin >> arr[i][j];
    int n, m;
    n = find(arr[0][0]); if(n == -1) goto bad;
    m = find(arr[1][1]); if(m == -1) goto bad;

    dbg(n,m);

    if(m == 1 && arr[1][0] == 0 && arr[0][1] == 0){
        //means m = 0;
        string s;
        rep(i,0,n) s+='0';
        cout << s << endl;
        return;
    }
    else if(n == 1 && arr[1][0] == 0 && arr[0][1] == 0){
        //means n =0
        string s;
        rep(i,0,m) s+='1';
        cout << s<< endl;
        return;
    }

    if((arr[0][1]+arr[1][0])!= (n*m)) goto bad;

    if(arr[0][1] <= arr[1][0]){
        vi pos(n+1,0); int curr = arr[0][1];
        int num =0;
        for(int i = n;i >=1 && curr>0;i--){
            if((curr/i) == 0) continue;
            else{
                int k = curr/i;
                pos[i] = k; num+=k;
                curr -= (k*i);
            }
        }
        assert(num<=m);
        pos[0] = m - num;
        string s;

        for(int i=0;i<(n+1);i++){
            if(i!=0) s+='0';
            rep(j,0,pos[i]) s+='1';
        }

        cout << s << endl;
    }
    else{
        vi pos(m+1,0); int curr = arr[1][0];
        int num =0;
        for(int i = m;i >=1 && curr>0;i--){
            if((curr/i) == 0) continue;
            else{
                int k = curr/i;
                pos[i] = k; num+=k;
                curr -= (k*i);
            }
        }
        assert(num<=n);
        pos[0] = n - num;
        string s;

        for(int i=0;i<(m+1);i++){
            if(i!=0) s+='1';
            rep(j,0,pos[i]) s+='0';
        }

        cout << s << endl;
    }


    return;

bad:
    cout << "Impossible" << endl;

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
