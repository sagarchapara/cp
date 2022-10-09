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

void dfs(int u, const vvpi& adj, vi& color, vi& count, bool& ok){
    count[color[u]]++;
    for(auto p: adj[u]){
        if(color[p.first] == -1){
            color[p.first] = color[u]^p.second;
            dfs(p.first, adj, color, count, ok);
        }
        else if(color[p.first] != color[u]^p.second){
            ok = false;
        }
    }
}



void solve() {
    const string imposter = "imposter";
    const string crewmate = "crewmate";

    int n,m; cin >> n >> m;

    vvpi adj(n);

    rep(t,0,m){
        int i,j; string s;
        cin >> i >> j >> s; --i, --j;
        if(s.compare(crewmate) == 0){
            adj[i].push_back({j,0});
            adj[j].push_back({i,0});
        }
        else{
            adj[i].push_back({j,1});
            adj[j].push_back({i,1});
        }
    }

    vi color(n,-1);

    int ans =0;

    rep(i,0,n){
        if(color[i] == -1){
            vi cnt(2,0); bool ok = true;
            color[i] =0;
            dfs(i,adj,color,cnt,ok);
            if(!ok){
                cout << -1 << endl;
                return;
            }
            ans += max(cnt[0], cnt[1]);
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
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }

    auto stop = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();

    #ifdef SAGAR
        cerr << "Took " << stop - start << "ms" << endl;
    #endif
}
