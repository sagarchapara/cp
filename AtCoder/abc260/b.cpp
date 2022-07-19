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
    int n,x,y,z; cin >> n >> x >> y >> z;
    vi a(n), b(n);
    vpi math(n), eng(n), sum(n);
    rep(i,0,n) cin >> a[i];
    rep(i,0,n) cin >> b[i];
    rep(i,0,n){
        math[i] = {a[i], i};
        eng[i]  = {b[i], i};
        sum[i] = {a[i]+b[i], i};
    }

    std::sort(math.begin(), math.end(),
        [](const pi &x, const pi &y) {
            if (x.first == y.first) {
                return x.second < y.second;
            }
            return x.first > y.first;
        }
    );

    std::sort(eng.begin(), eng.end(),
    [](const pi &x, const pi &y) {
        if (x.first == y.first) {
            return x.second < y.second;
        }
        return x.first > y.first;
    });

    std::sort(sum.begin(), sum.end(),
    [](const pi &x, const pi &y) {
        if (x.first == y.first) {
            return x.second < y.second;
        }
        return x.first > y.first;
    });
        

    vi visited(n,0);

    dbg(math);
    dbg(eng);
    dbg(sum);

    vi ans;

    for(int i=0;i<x;i++){
        visited[math[i].second] = 1;
        // printf("%d\n", );
        ans.push_back(math[i].second+1);
    }
    int num =0;
    for(int i=0;i<n;i++){
        if(num>=y) break;
        if(visited[eng[i].second] == 0){
            visited[eng[i].second] = 1;
            // printf("%d\n", eng[i].second+1);
            ans.push_back(eng[i].second+1);
            num++;
        }
    }
    num =0;
    for(int i=0;i<n;i++){
        if(num>=z) break;
        if(visited[sum[i].second] == 0){
            visited[sum[i].second] = 1;
            // printf("%d\n", sum[i].second+1);
            ans.push_back(sum[i].second+1);
            num++;
        }
    }


    sort(all(ans));
    for(int i: ans){
        printf("%d\n", i);
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
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
