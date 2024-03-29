// g++ -o out <filename>.cpp
// .\out.exe

#define SAGAR

#include <bits/stdc++.h>
using namespace std;                                    

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x << " "; return os;}
void dbg_out() { cerr << ""; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << endl; dbg_out(T...); }
#ifdef SAGAR
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define F first
#define S second
#define pi pair<int,int>
#define vi vector<int>
#define vpi vector<pi>
#define all(x) (x).begin(), (x).end()
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define sz(x) (int)(x).size()

void dfs(int curr, vector<vi>& adj, vi& visited){
    visited[curr] = true;
    for(int i: adj[curr]){
        if(!visited[i]){
            dfs(i, adj, visited);
        }
    }
}

bool isPossible(int s, int n, vpi& points, vi& power){
    vector<vi> adj(n);
    rep(i,0,n){
        rep(j,0,n){
            if(i!=j){
                int sum = abs(points[i].F - points[j].F);
                sum+= abs(points[i].S - points[j].S);
                if(sum <=  s*power[i]){
                    adj[i].push_back(j);
                }
            }
        }
    }

    rep(i,0,n){
        vi visited(n, false);
        dfs(i,adj,visited);
        bool isTrue = true;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                isTrue = false;
                break;
            }
        }
        if(isTrue){
            return true;
        }
    }

    return false;
}

void solve() {
    int n; cin >> n;
    vpi points(n); vi power(n);
    rep(i,0,n){
        int x, y, p;
        cin >> x >> y >> p;
        points[i]= {x,y};
        power[i] = p;
    }

    int l = 0,  r = 1e10;

    while(r-l>1){
        int mid = (l+r)/2;
        if(isPossible(mid,n,points,power)){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }

    int ans = r;
    for(int i=l; i<=r;i++){
        if(isPossible(i,n,points,power)){
            ans = i;
            break;
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
