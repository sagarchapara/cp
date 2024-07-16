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

class SegmentTree{

    int n;
    vector<int> t;

    inline void build(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = min(t[v*2], t[v*2+1]);
        }
    }

    inline int query(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 1e6;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return min(query(v*2, tl, tm, l, min(r, tm))
            ,query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }

    inline void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            t[v] = min(t[v*2],t[v*2+1]);
        }
    }

public:

    SegmentTree(int _n, vector<int>& arr): n(_n){
        t.resize(4*n);
        build(arr, 1, 0, n-1);
    }

    inline int query(int l, int r){
        return query(1, 0, n-1, l, r);
    }

    inline void update(int p, int val){
        update(1,0,n-1,p,val);
    }
};

/**
 * @brief Returns index of the next greater element
 * If there is no nge returns n
 * @param v input vector
 * @return vector<int> 
 */
vector<int> nextGreaterElem(vector<int>& v){
    stack<int> s;

    int n = v.size();

    vector<int> ans(n, n);
    s.push(0);

    for(int i=1;i<n;i++){
        while(!s.empty() && v[i] < v[s.top()]){
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    return ans;
}

/**
 * @brief Returns index of the next greater element
 * If there is no pge returns -1
 * @param v input vector
 * @return vector<int> 
 */
vector<int> prevGreaterElem(vector<int>& v){
    stack<int> s;

    int n = v.size();

    vector<int> ans(n, -1);
    s.push(n-1);

    for(int i= n-1;i>=0;i--){
        while(!s.empty() && v[i] < v[s.top()]){
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    return ans;
}

void solve() {
    int n; cin >> n;

    vector<int> arr(n);

    map<int, int> lookup;

    for(int i=0;i<n;i++){
        cin >> arr[i]; arr[i]--;
        lookup[arr[i]] = i;
    }

    SegmentTree tree(n, arr);

    vector<int> nge = nextGreaterElem(arr);
    vector<int> pge = nextGreaterElem(arr);

    int ans = 0;

    vector<int> dp(n+1, 0);

    for(int i=0;i<n;i++){
        int val = (nge[i] - i) * (i - pge[i]);
        ans += val;
        dp[i] -= (val);

        if(pge[i] != -1){
            //then if we remove next, we need to find, pge again  
            int next = pge[i];

            int start = pge[pge[i]]+1;

            int r = pge[i] -1;
            int l = start;

            while (l < r)
            {
                //find first prefix with minimun < arr[i]
                int mid = (l+r+1)/2;

                if(tree.query(start, mid) < arr[i]){
                    l = mid;
                }
                else{
                    r = mid-1;
                }

                dbg(l,r);
            }

            //we got the l;
            dp[next] += (nge[i] - i)*(pge[i]-l-1);  
        }

        if(nge[i] != n){
            int next = nge[i];

            int end = nge[nge[i]];

            int l = next+1;
            int r = end-1;

            while (l < r)
            {
                int mid = (l+1+r)/2;

                if(tree.query(next+1,mid) > arr[i]){
                    l = mid+1;
                }
                else{
                    r = mid;
                }

                dbg(l,r);
            }

            dp[next] += (i - pge[i])*(l-nge[i]-1);
        }
    }

    for(int i=0;i<n;i++){
        dp[i] += ans;

        cout << dp[i] << " " <<endl;
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
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }

    auto stop = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();

    #ifdef SAGAR
		cerr << "Took " << stop - start << "ms" << endl;
	#endif
}
