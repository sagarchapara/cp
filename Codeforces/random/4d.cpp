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

template<typename T>
class SegmentTree{
    vector<T> t;
    int n;
    function<T(T,T)> merge_func;

    void build(vector<T>& arr, int v, int tl, int tr){
        if(tl == tr){
            t[v] = arr[tl];
        }
        else{
            int mid = (tl+tr)/2;
            build(arr, 2*v, tl, mid);
            build(arr, 2*v+1, mid+1, tr);

            t[v] = merge_func(t[2*v], t[2*v+1]);
        }
    }

    void update(int v, int tl, int tr, int pos, T new_val){
        if(tl == tr){
            t[v] = new_val;
        }
        else{
            int tm = (tl+tr)/2;
            if(pos <= tm){
                update(2*v, tl, tm, pos, new_val);
            }
            else{
                update(2*v+1,tm+1, tr, pos, new_val);
            }
            t[v] = merge_func(t[2*v], t[2*v+1]);
        }
    }

    T get(int v, int tl, int tr, int l, int r){
        if(l > r){
            return T();
        }

        if(tl == l && tr == r){
            return t[v];
        }

        int tm = (tl + tr)/2;

        return merge_func(get(2*v, tl, tm, l, min(r, tm)),
                    get(2*v+1, tm+1, tr, max(l, tm+1), r));
    }


public:
    SegmentTree(int _n, vector<T>& arr, function<T(T,T)> _merge_func): n(_n), merge_func(_merge_func){
        t.resize(4*n);
        build(arr, 1, 0, n-1);
    }

    SegmentTree(int _n, function<T(T,T)> _merge_func): n(_n), merge_func(_merge_func){
        t.resize(4*n);
    }

    void update(int x, T val){
        update(1, 0, n-1, x, val);
    }

    T get(int l, int r){
        return get(1, 0, n-1, l, r);
    }
};

void solve() {
    int n, w, h;
    cin >> n >> w >> h;

    vector<pair<int, pair<int, int>>> arr;

    for(int i=0;i<n;i++){
        int x, y;
        cin >> x >> y;

        if(x > w && y > h){
            arr.push_back({i, {x, y}});
        }
    }

    if(arr.size()  == 0){
        cout << 0 << endl;
        return;
    }

    sort(arr.begin(), arr.end(), [](const auto& a, const auto& b){
        if(a.second.first == b.second.first){
            return a.second.second > b.second.second;
        }
        return a.second.first < b.second.first;
    });

    dbg(arr);

    int m = arr.size();

    auto func = [](const pair<int, int>& a, const pair<int,int>& b) -> pair<int,int>{
        if(a.first > b.first){
            return a;
        }
        else{
            return b;
        }
    };

    int MAX_VALUE = 1e6+2;

    SegmentTree<pair<int, int>> tree(1e6+2, func);

    int ans = 1, pos = m-1;

    pair<int, int> prev = arr[m-1].second;

    tree.update(arr[m-1].second.second, {1, m-1});

    vector<int> next(m,m);

    for(int i=m-2;i>=0;i--){
        auto& curr = arr[i].second;

        dbg(i, curr);

        if(curr == prev){
            continue;
        }

        //find the max value from curr.fist + 1
        auto val = tree.get(curr.second+1, 1e6);
        
        dbg(i, val);

        if(val.first > 0){
            next[i] = val.second;

            if(1 + val.first > ans){
                ans = 1 + val.first;
                pos = i;
            }
        }

        //update
        prev = curr;
        tree.update(curr.second, {1+val.first, i});
    }

    cout << ans << endl;

    int curr = pos;

    while(curr != m){
        cout << (arr[curr].first + 1) << " ";

        curr = next[curr]; 
    }

    cout << endl ;
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
