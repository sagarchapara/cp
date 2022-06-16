// g++ -o out <filename>.cpp
// cmd /c '.\out.exe < input.txt'

// #define SAGAR

#include <bits/stdc++.h>
using namespace std;                                    


/*
 *==========================================
 * Input 
 *==========================================
 */
void read(){}
void read(long long& a){scanf("%lld",&a);}
void read(long& a){scanf("%ld",&a);}
void read(int& a){scanf("%d",&a);}
void read(double& a){scanf("%lf",&a);}
void read(float& a){scanf("%f",&a);}
void read(string& a){cin>>a;}
template<typename x>void read(x& a){for(auto  &i : a) read(i);}
template<typename x,typename y>void read(pair<x,y>& a){ read(a.first),read(a.second);}
template<typename... x>void read(x&... a){((read(a)), ...);}


/*
 *==========================================
 * Output and Debug
 *==========================================
 */

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

void dfs1(int v, vector<vector<int>>& adj, vector<bool>& used, vector<int>& order) {
    used[v] = true;
    for (int u : adj[v]){
        if (!used[u]){
            dfs1(u, adj, used, order);
        }
    }    
    order.push_back(v);
}

void dfs2(int v, vector<vector<int>>& adj_rev, vector<bool>& used, vector<int>& component){
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v]){
        if (!used[u]){
            dfs2(u, adj_rev, used, component);
        }
    }
        
}

const int MAXN = 1e9 +7 ; 

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    dbg(arr);

    vector<vector<int>> adj(n);
    vector<vector<int>> adj_rev(n);
    vector<bool> used(n, false);
    vector<int> order, component;

    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj_rev[b-1].push_back(a-1);
    }

    dbg(arr);
    dbg(adj);

    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i, adj, used, order);

    used.assign(n, false);
    reverse(order.begin(), order.end());


    
    dbg(adj_rev);

    vector<int> cnt;

    int ans =0;

    for (auto v : order){
        if (!used[v]) {
            dfs2 (v, adj_rev, used, component);

            map<int,int> cost;
            for(int i: component){
                auto itr = cost.find(arr[i]);
                if(itr != cost.end()){
                    itr->second +=1;
                }
                else{
                    cost[arr[i]] = 1;
                }
            }

            cnt.push_back(cost.begin()->second);

            ans+=cost.begin()->first;

            component.clear();
        }
    }

    int count = 1;
    for(int i: cnt){
        count = (count*i)%MAXN;
    }

    cout << ans << " "<<count;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
