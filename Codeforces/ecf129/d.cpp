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

pair<set<int>, int> decimal(int k){
    set<int> s; int num =0;
    while(k>0){
        s.insert(k%10);
        k/=10;
        num++;
    }

    return {s, num};
}

void solve() {
    int n, x; cin >> n >> x;
    queue<pi> q; int ans = -1; 

    q.push({x, 0}); 

    set<int> seen; int max_num = -1;
    seen.insert(x);

    while(q.size()>0){
        pi p = q.front(); q.pop();        
        dbg(p);

        auto next = decimal(p.first);

        if(max_num == -1) max_num = next.second;
        else max_num = max(max_num, next.second);

        if(next.second == n){
            ans = p.second;
            break;
        }

        if(next.second < max_num-1){
            continue;
        }

        else if (next.second > n) continue;

        for(int i: next.first){
            if(i!=1 && i!=0){
                int k = i*p.first;
                if(!seen.count(k)){
                    q.push({i*p.first, p.second+1});
                    seen.insert(k);
                }
            }
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

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
