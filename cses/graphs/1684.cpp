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

void dfs(int curr, vector<vector<int>>& adjL, vector<int>& visited, vector<int>& tpg){
    visited[curr] = true;

    for(int u : adjL[curr]){
        if(!visited[u]){
            dfs(u, adjL, visited, tpg);
        }
    }

    tpg.push_back(curr);
}

void solve() {
    int n, m; cin >> m >> n;

    vector<vector<int>> adjL(2*n), radjL(2*n);

    for(int i=0;i<m;i++){
        char op1, op2;
        int x, y;

        cin >> op1 >> x >> op2 >> y; x--, y--;

        dbg(op1, op2, x, y);

        if(op1 == '+' && op2 == '+'){
            //both true
            adjL[x+n].push_back(y); radjL[y].push_back(x+n);
            adjL[y+n].push_back(x); radjL[x].push_back(y+n);
        }
        else if(op1 == '-' && op2 == '+'){
            adjL[x].push_back(y); radjL[y].push_back(x);
            adjL[y+n].push_back(x+n); radjL[x+n].push_back(y+n);
        }
        else if(op1 == '+' && op2 == '-'){
            adjL[x+n].push_back(y+n); radjL[y+n].push_back(x+n);
            adjL[y].push_back(x); radjL[x].push_back(x);
        }
        else if(op1 == '-' && op2 == '-'){
            adjL[x].push_back(y+n); radjL[y+n].push_back(x);
            adjL[y].push_back(x+n); radjL[x+n].push_back(y);
        }
    }

    vector<int> tpg;
    vector<int> visited(2*n, false);

    for(int i=0;i<2*n;i++){
        if(!visited[i]){
            dfs(i, adjL, visited, tpg);
        }
    }

    reverse(tpg.begin(), tpg.end());

    visited.assign(2*n, false);

    vector<int> component_num(2*n);

    int start = 0;

    for(int i: tpg){
        if(!visited[i]){
            vector<int> comp;
            dfs(i, radjL, visited, comp);

            for(int u: comp){
                component_num[u] = start;
            }

            start++;
        }
    }

    dbg(component_num);

    //now try to assign values
    string ans;

    for(int i=0;i<n;i++){
        if(component_num[i] == component_num[i+n]){
            cout << "IMPOSSIBLE" << endl;
            return;
        }

        if(component_num[i] > component_num[i+n]){
            ans+= "+ ";
        }
        else{
            ans+= "- ";
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
