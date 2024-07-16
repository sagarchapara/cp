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

    return true;
}

bool is_empty_block(int x, int y, bool horizontal, vector<vector<bool>>& filled, pair<int,int>& block){
    int h = filled.size();
    int w = filled[0].size();
    
    if(horizontal){
        if(x + block.first > h){
            return false;
        }

        if(y + block.second > w){
            return false;
        }

        //x and y are same
        for(int i = x;i<(x+block.first);i++){
            for(int j=y;j<(y+block.second);j++){
                if(filled[i][j]){
                    return false;
                }
            }
        }
    }
    else{
        //y and x
        if(x + block.second > h){
            return false;
        }

        if(y + block.first > w){
            return false;
        }

        //x and y are same
        for(int i = x;i<(x+block.second);i++){
            for(int j=y;j<(y+block.first);j++){
                if(filled[i][j]){
                    return false;
                }
            }
        }
    }

    return true;
}

void fill_block(int x, int y, int u, int v, vector<vector<bool>>& filled, bool fill){
    //x and y are same
    for(int i = x;i<x+u;i++){
        for(int j=y;j<y+v;j++){
            if(fill){
                filled[i][j] = true;
            }
            else{
                filled[i][j] = false;
            }
        }
    }
}

bool solve(int idx, vector<vector<bool>>& filled, vector<pair<int, int>>& blocks){
    int n = blocks.size();

    int h = filled.size();
    int w = filled[0].size();

    if(idx == n){
        return is_filled(filled);
    }

    //not using current block
    bool ans = solve(idx+1, filled, blocks);

    if(ans) return true;

    vector<vector<int>> width(h,vector<int>(w, 0));
    vector<vector<int>> height(h, vector<int>(w, 0));

    for(int i=0;i<h;i++){
        int prev_filled = w;
        for(int j=w-1;j>=0;j--){
            if(filled[i][j]){
                prev_filled = j;
            }
            else{
                width[i][j] = (prev_filled-j);
            }
        }
    }

    for(int j=0;j<w;j++){
        int prev_filled = h;
        for(int i=h-1;i>=0;i--){
            if(filled[i][j]){
                prev_filled = i;
            }
            else{
                height[i][j] = (prev_filled-i);
            }
        }
    }


    set<int> wx,wy, hx, hy;


    for(int i=0;i<h;i++){
        if(i+blocks[idx].first >h && i+blocks[idx].second > h){
            break;
        }

        for(int j=0;j<w;j++){
            if(j+blocks[idx].first >w && j+blocks[idx].second > w){
                break;
            }

            //check if i, j can support any of the rotation.
            if(is_empty_block(i,j,true,filled,blocks[idx])){
                fill_block(i,j,blocks[idx].first,blocks[idx].second, filled, true);
                ans |=  solve(idx+1, filled, blocks);
                fill_block(i,j,blocks[idx].first,blocks[idx].second, filled, false);

                if(ans) return true;
            }

            if(is_empty_block(i,j,false,filled,blocks[idx])){
                fill_block(i,j,blocks[idx].second,blocks[idx].first, filled, true);
                ans |=  solve(idx+1, filled, blocks);
                fill_block(i,j,blocks[idx].second,blocks[idx].first, filled, false);

                if(ans) return true;
            }
        }
    }

    return ans;
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

    vector<vector<bool>> filled(h, vector<bool>(w,false));

    if(solve(0,filled,blocks)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
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
