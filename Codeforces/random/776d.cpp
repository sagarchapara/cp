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


bool dfs(int i, vector<int>& color, vector<vector<int>>& edges, vector<vector<int>>& nodes, vector<int>& rooms){
    int n = edges.size();
    int m = nodes.size();

    bool ans = true;

    //it's already colored
    //i is the node
    //now see all the bulbs it has
    for(int next: nodes[i]){
        //get the edge
        int val = rooms[next];

        for(int j: edges[next]){
            if(i!=j){
                if(val == 1){
                    //they should belong to same color
                    if(color[j] != -1){
                        if(color[j] != color[i]){
                            return false;
                        }
                    }
                    else{
                        color[j] = color[i];
                        ans &= dfs(j, color, edges, nodes, rooms);
                    }
                }
                else{
                    //they should have opposite color
                    //they should belong to same color
                    if(color[j] != -1){
                        if(color[j] == color[i]){
                            return false;
                        }
                    }
                    else{
                        color[j] = 1- color[i];
                        ans &= dfs(j, color, edges, nodes, rooms);
                    }
                }

                if(!ans){
                    return ans;
                }
            }
        }
    }

    return ans;
}

void solve() {
    int n, m;
    
    cin >> n >> m;

    vector<int> rooms(n);

    for(int i=0;i<n;i++){
        cin >> rooms[i];
    }

    vector<vector<int>> edges(n, vector<int>());

    vector<vector<int>> nodes(m, vector<int>());

    for(int i=0;i<m;i++){
        int k; cin >> k;

        for(int j=0;j<k;j++){
            int a; cin >> a;
            nodes[i].push_back(a-1);
            edges[a-1].push_back(i);
        }
    }

    //so now what
    //go though edges, if it's 1,
    //they should belong to same group, if it's zero they should belong to different group 

    vector<int> color(m, -1);

    for(int i=0;i<m;i++){
        if(color[i] == -1){
            color[i] = 0;

            if(!dfs(i, color, edges, nodes, rooms)){
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
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
