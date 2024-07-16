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


int num_ballons(int time, int t, int z, int y){
    int l = 0;
    int r = 15000;

    while(r-l>1){
        int mid = (l+r+1)/2;

        int val = mid*(z*t) + (mid)*y;

        if(val > time){
            r = mid-1;
        }
        else{
            l = mid;
        }
    }

    for(int i=r;i>=l;i--){
        int val = i*(z*t) + (i)*y;

        if(val <= time){
            int ans = i*z;
            ans += min(z, (time-val)/t);

            return ans;
        }
    }

    return 0;
}

bool check(int time, int m, int n, vector<int>& t, vector<int>& z, vector<int>& y){
    int sum = 0;

    for(int i=0;i<n;i++){
        sum += num_ballons(time, t[i], z[i], y[i]);

        if(sum >= m) return true;
    }

    return false;
}

void solve() {
    int n, m; cin >> m >> n;

    vector<int> t(n), z(n), y(n);

    for(int i=0;i<n;i++){
        cin >> t[i] >> z[i] >> y[i];
    }

    int l = 0;
    int r = 1e18;

    while (r-l>1)
    {
        int mid = (l+r+1)/2;

        if(check(mid, m, n, t, z, y)){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }

    for(int i=l;i<=r;i++){
        if(check(i,m,n,t,z,y)){
            cout << i << endl;

            for(int j=0;j<n;j++){
                int num = num_ballons(i,t[j],z[j],y[j]);

                cout << num << " ";
            }

            cout << endl;

            return;
        }
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
