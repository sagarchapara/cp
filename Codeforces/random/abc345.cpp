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

bool is_filled(vector<vector<bool>>& filled){
    int h = filled.size();
    int w = filled[0].size();

    //check if all blocks are filled
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(!filled[i][j]) return false;
        }
    }
}

void solve() {
    int n, h, w;

    cin >> n >> h >> w;

    vector<pair<int, int>> blocks;

    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        blocks.push_back({x,y});
    }

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        arr[i] = i;
    }

    do{
        for(int mask=0; mask < (1<<n);mask++){
            vector<vector<bool>> filled(h, vector<bool>(w, false));

            for(int i: arr){
                if(mask & (1<<i)){
                    //we need to put first empty block here
                    int x = -1, y = -1;
                    for(int xx =0;xx<h;xx++){
                        for(int yy=0;yy<w;yy++){
                            if(!filled[xx][yy]){
                                x = xx; y = yy;
                            }
                        }
                    }    

                    if(x == -1 && y == -1){
                        cout << "YES" << endl;

                        return;
                    }            

                }
            }
        }

    }while(next_permutation(arr.begin(), arr.end()));

    vector<vector<bool>> filled(h, vector<bool>(w,false));
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
