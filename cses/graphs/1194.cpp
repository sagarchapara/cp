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


struct Edge
{
    int i;
    int j;
    bool isMan;
    int time;

    Edge(int _i, int _j, bool _isMan, int _time): i(_i), j(_j), isMan(_isMan), time(_time){}
};


void trace_route(int sx, int sy, vector<vector<pair<int, int>>>& parent){
    string s;
    
    while (parent[sx][sy].first != -1 && parent[sx][sy].second != -1)
    {
        int next_sx = parent[sx][sy].first;
        int next_sy = parent[sx][sy].second;

        int dx = sx - next_sx;
        int dy = sy - next_sy;

        if(dx == 0){
            s += (dy == 1)? "R" : "L";
        }
        else{
            s += (dx == 1)? "D": "U";
        }

        sx = next_sx;
        sy = next_sy;
    }

    cout << s.size() << endl;

    reverse(s.begin(), s.end());

    cout << s << endl;
}

void solve() {
    int n,m; cin >> n >> m;

    vector<string> arr(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    vector<vector<pair<int,int>>> visited(n, vector<pair<int,int>>(m, {-1,-1}));

    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m));

    queue<Edge> q;

    int manx, many;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 'M'){
                q.emplace(i,j,false,0);
                visited[i][j] = {-1, 0};
            }
            else if(arr[i][j] == 'A'){
                manx = i;
                many = j;
                visited[i][j] = {0, -1};
                parent[i][j] = {-1,-1};
            }
        }
    }

    q.emplace(manx, many, true, 0);

    while (!q.empty())
    {
        Edge e = q.front(); q.pop();

        if(e.isMan && (e.i == 0 || e.i == n-1 || e.j == m-1 || e.j == 0)){
            if(visited[e.i][e.j].second == -1 || (visited[e.i][e.j].first < visited[e.i][e.j].second)){
                cout << "YES" << endl;
                trace_route(e.i,e.j, parent);
                return;
            }
        }

        int xx[] = {-1,0,1,0};
        int yy[] = {0,-1,0,1};


        //go thorough each and seemonster hasn't reached yet
        for(int i=0;i<4;i++){
            int nx = e.i + xx[i];
            int ny = e.j + yy[i];

            if(nx <0 || nx >=n || ny<0 || ny>=m){
                continue;
            }

            if(arr[nx][ny] == '#'){
                continue;
            }

            if(e.isMan){
                if(visited[nx][ny].second == -1 && visited[nx][ny].first == -1){
                    visited[nx][ny] = {e.time+1, -1};
                    q.emplace(nx,ny,true,e.time+1);
                    parent[nx][ny] = {e.i, e.j};
                }
            }
            else{
                if(visited[nx][ny].second == -1){
                    visited[nx][ny] = {visited[nx][ny].first, e.time+1};
                    q.emplace(nx,ny,false,e.time+1);
                }
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
