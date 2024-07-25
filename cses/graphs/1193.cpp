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

struct Edge{
    int u;
    int v;
    int dist;

    Edge(){}

    Edge(int _u, int _v, int _dist): u(_u), v(_v), dist(_dist){}
};

string trace_path(int i, int j, vector<vector<Edge>>& parent){
    string s;

    // dbg(parent);

    while(parent[i][j].u != -1 && parent[i][j].v != -1){
        //which direction we moved

        dbg(i,j, parent[i][j].u , parent[i][j].v);

        int dx = i - parent[i][j].u;
        int dy = j - parent[i][j].v;

        if(dx == 0){
            s += (dy >0) ? 'R' : 'L';
        }
        else{
            s+= (dx >0)? 'D' : 'U';
        }

        int next_i = parent[i][j].u;
        int next_j = parent[i][j].v;

        i = next_i;
        j = next_j;
    }

    reverse(s.begin(), s.end());

    return s;
}

void solve() {
   int n, m; cin >> n >> m;

   vector<vector<char>> grid(n, vector<char>(m));
   
   queue<Edge> q;

   vector<vector<bool>> visited(n, vector<bool>(m));
   vector<vector<Edge>> parent(n, vector<Edge>(m));

   Edge end(-1,-1,-1);

   for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
        cin >> grid[i][j];
        if(grid[i][j] == 'A'){
            q.emplace(i,j, 0);
            visited[i][j] = true;
            parent[i][j] = Edge(-1,-1,-1);
        }
        else if(grid[i][j] == 'B'){
            end = Edge(i,j, -1);
        }
     }
   }

   while (!q.empty())
   {
        Edge e = q.front(); q.pop();

        if(e.u == end.u && e.v == end.v){
            cout << "YES" << endl;
            string s = trace_path(e.u,e.v,parent);
            cout << s.size() << endl;
            cout << s << endl;

            return;
        }

        int xx[] = {0,-1,1,0};
        int yy[] = {-1,0,0,1};

        for(int i=0;i<4;i++){
            int nx = e.u + xx[i];
            int ny = e.v + yy[i];

            if(nx <0 || nx >=n || ny <0 || ny >= m){
                continue;
            }

            if(!visited[nx][ny] && grid[nx][ny] != '#'){
                visited[nx][ny] = true;
                q.emplace(nx,ny,e.dist+1);
                parent[nx][ny] = Edge(e.u,e.v,-1);
            }
        }
   }

   cout << "NO" << endl;
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
