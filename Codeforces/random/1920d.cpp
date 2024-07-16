// g++ -o out <filename>.cpp -D SAGAR
// .\out.exe

#include <bits/stdc++.h>
using namespace std;                                    

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x << " "; return os;}
void dbg_out() { cerr << "" << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << " " ; dbg_out(T...); }
#ifdef SAGAR
// #define dbg(...)
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

struct Operation
{
    int len;
    int type;
    int val; //type == 1, x //type == 2 rep x

    Operation(int _len, int _type, int _val) : len(_len), type(_type), val(_val){}
};


int find(int x, vector<Operation>& arr, vector<int>& prefix_sum){
    //first do binary search, to find the correct block
    int l = 0;
    int r = arr.size()-1;

    while(l<=r){
        int mid = (l+r+1)/2;

        dbg(x, l, r, mid, prefix_sum[mid]);

        if(x > prefix_sum[mid]){
            dbg("path_a");

            l = mid+1;
        }
        else if(prefix_sum[mid] > x){
            if(mid > 0 && prefix_sum[mid-1] < x){
                dbg("path_b");
                //if mid lies in this block
                //search in this block
                if(arr[mid].type == 1){
                    dbg("path_c");

                    return arr[mid].val;
                }
                else{
                    dbg("path_d");

                    //now array is len  [len, len, len , len ... x] times
                    int diff = x - prefix_sum[mid-1];

                    int rem = diff % arr[mid].len;

                    if(rem == 0){
                        rem = arr[mid].len;
                    }
                    
                    return find(rem, arr, prefix_sum);
                }
            }
            else{
                dbg("path_e");

                r = mid-1;
            }
        }
        else{
            //equals
            if(arr[mid].type == 1){
                dbg("path_f");

                return arr[mid].val;
            }
            else{
                //last elem
                dbg("path_g");

                return find(arr[mid].len, arr, prefix_sum);
            }
        }
    }

    if(arr[l].type == 1){
        dbg("path_h");

        return arr[l].val;
    }
    else{
        //last elem
        dbg("path_i");

        //now array is len  [len, len, len , len ... x] times
        int diff = x - prefix_sum[l-1];

        int rem = diff % arr[l].len;

        if(rem == 0){
            rem = arr[l].len;
        }
        
        return find(rem, arr, prefix_sum);
    }
}


void solve() {
    int n, q; cin >> n >> q;

    vector<Operation> ops;

    vector<int> prefix_sum(n);

    int len = 0;

    for(int i=0;i<n;i++){
        int type, x; cin >> type >> x;

        if(type == 1){
            ops.emplace_back(1, 1, x);
            len+=1;
        }
        else{
            ops.emplace_back(len, 2, x);
            len+= x*len;
        }

        prefix_sum[i] = len;
    }

    dbg(prefix_sum);

    for(int i=0;i<q;i++){
        int k; cin >> k;

        int ans = find(k, ops, prefix_sum);

        cout << ans << " ";
    }

    cout << endl;
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
