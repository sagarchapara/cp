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
    int val;
    int l;
    int r;

    Edge(int _val, int _l, int _r): val(_val), l(_l), r(_r){} 

    bool operator<(const Edge& other) const {
        if (val != other.val) return val < other.val;
        if (l != other.l) return l < other.l;
        return r < other.r;
    }

    bool operator==(const Edge& other) const {
        return l == other.l && r == other.r && val == other.val;
    }

    friend ostream& operator<<(ostream& out, const Edge& curr){
        out << curr.l << " " << curr.r << " " << curr.val; 

        return out; 
    }
};


void solve() {
    int n, k; cin >> n >> k;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    dbg(arr);

    //let's keep all the k less edges;
    set<Edge> edges1, edges2; int sum1 = 0, sum2 = 0, ans = -1;

    for(int i=1;i<n;i++){
        //we are worrying about (i-1, i);
        Edge e(arr[i]-arr[i-1], i-1, i);

        edges2.insert(e);

        sum2 += e.val;

        if(i-2>=0){
            Edge prev_edge(arr[i-1]-arr[i-2], i-2, i-1);

            if(edges1.find(prev_edge) == edges1.end()){
                dbg("edge_not_found");

                int val = sum1 + e.val;

                if(edges1.size() == k){
                    val -= edges1.rbegin()->val;
                }

                if(edges1.size() == k || edges1.size() == k-1){
                    if(ans == -1){
                        ans = val;
                    }
                    else{
                        ans = min(ans, val);
                    }
                }
            }
        }

        while (edges2.size() > k)
        {
            sum2 -= edges2.rbegin()->val;
            edges2.erase(prev(edges2.end()));
        }

        if(edges2.size() == k){
            if(ans == -1){
                ans = sum2;
            }
            else{
                ans = min(ans, sum2);
            }
        }

        swap(edges1, edges2);
        swap(sum1, sum2);

        dbg(edges1);
        dbg(edges2);
        dbg(sum1, sum2, ans);
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
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }

    auto stop = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();

    #ifdef SAGAR
		cerr << "Took " << stop - start << "ms" << endl;
	#endif
}
