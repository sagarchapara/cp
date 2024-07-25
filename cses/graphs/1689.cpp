// g++ -o out <filename>.cpp -D SAGAR
// .\out.exe

#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> 
ostream& operator<<(ostream &os, const pair<A, B> &p) { 
    return os << p.first << " " << p.second; 
}

template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> 
ostream& operator<<(ostream &os, const T_container &v) { 
    for (const T &x : v) os << x << " "; 
    return os;
}

void dbg_out() { cerr << "" << endl; }

template<typename Head, typename... Tail> 
void dbg_out(Head H, Tail... T) { 
    cerr << H << " "; 
    dbg_out(T...); 
}

#ifdef SAGAR
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vpi vector<pi>
#define vvpi vector<vpi>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define Unique(store) store.resize(unique(store.begin(), store.end()) - store.begin())
#define sz(x) (int)(x).size()

int xx[] = {-1, -2, -1, -2, 1, 2, 1, 2};
int yy[] = {-2, -1, 2, 1, -2, -1, 2, 1};

bool is_good(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void mark(int num, int x, int y, vector<vector<int>>& arr, vector<vector<int>>& d) {
    for (int i = 0; i < 8; i++) {
        if (is_good(x + xx[i], y + yy[i], 8) && arr[x + xx[i]][y + yy[i]] == 0) {
            d[x + xx[i]][y + yy[i]]--;
        }
    }
    arr[x][y] = num;
}

void unmark(int x, int y, vector<vector<int>>& arr, vector<vector<int>>& d) {
    for (int i = 0; i < 8; i++) {
        if (is_good(x + xx[i], y + yy[i], 8) && arr[x + xx[i]][y + yy[i]] == 0) {
            d[x + xx[i]][y + yy[i]]++;
        }
    }
    arr[x][y] = 0;
}

int get_num(int x, int y, vector<vector<int>>& arr) {
    int num = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + xx[i];
        int ny = y + yy[i];
        if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) {
            continue;
        }
        if (arr[nx][ny] != 0) {
            continue;
        }
        num++;
    }
    return num;
}

bool dfs(int num, int x, int y, vector<vector<int>>& arr, vector<vector<int>>& d) {
    
    dbg(num,x,y);
    
    mark(num, x, y, arr, d);
    if (num >= 64) {
        return true;
    }
    vector<pair<int, int>> next_values;
    for (int i = 0; i < 8; i++) {
        int nx = x + xx[i];
        int ny = y + yy[i];
        if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) {
            continue;
        }
        if (arr[nx][ny] != 0) {
            continue;
        }
        int num_values = get_num(nx, ny, arr);
        next_values.push_back({d[nx][ny], i});
    }
    sort(next_values.begin(), next_values.end());

    dbg(next_values);

    for (auto [values, i] : next_values) {
        int nx = x + xx[i];
        int ny = y + yy[i];
        if (dfs(num + 1, nx, ny, arr, d)) {
            return true;
        }
    }
    unmark(x, y, arr, d);
    return false;
}

void solve() {
    int x, y;
    cin >> x >> y;
    x--, y--;
    vector<vector<int>> arr(8, vector<int>(8, 0)), d(8, vector<int>(8, 0));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                int u = i + xx[k];
                int v = j + yy[k];
                if (is_good(u, v, 8)) {
                    d[u][v]++;
                }
            }
        }
    }
    bool result = dfs(1, x, y, arr, d);
    if (!result) {
        cout << "No solution found" << endl;
        return;
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int32_t main() {
#ifdef SAGAR
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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
