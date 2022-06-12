#include <bits/stdc++.h>
// #define LOCAL

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define mp make_pair
#define pb push_back

const int MAXN = 1e6;
const int ninf = -1e15;

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
        while(!s.empty() && v[i] > v[s.top()]){
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
        while(!s.empty() && v[i] > v[s.top()]){
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    return ans;
}

//build v= 1 tl=0 tr=n-1

void build(vector<int>& t,vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(t, a, v*2, tl, tm);
        build(t, a, v*2+1, tm+1, tr);
        t[v] = max(t[v*2] , t[v*2+1]);
    }
}

int query(vector<int>& t, int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return ninf;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(query(t, v*2, tl, tm, l, min(r, tm)),
                query(t, v*2+1, tm+1, tr, max(l, tm+1), r));
}

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i=0;i<n;i++){
        int j;
        cin >> j;
        v[i] =j;
    }

    vector<int> pref(n);
    vector<int> suff(n);

    for(int i=0;i<n;i++){
        if(i==0){
            pref[i] = v[i];
        }
        else{
            pref[i] = pref[i-1]+v[i];
        }
    }

    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            suff[i] = v[i];
        }
        else{
            suff[i] = suff[i+1]+v[i];
        }
    }
    
    vector<int> prefTree(4*n);
    vector<int> suffTree(4*n);

    build(prefTree, pref, 1, 0 , n-1);
    build(suffTree, suff, 1, 0 , n-1);

    auto nge = nextGreaterElem(v);
    auto pge = prevGreaterElem(v);

    dbg(suff);
    dbg(pref);
    dbg(nge);
    dbg(pge);
    dbg(prefTree);
    dbg(suffTree);

    bool isTrue = true;

    for (int i=0;i<n;i++){

        int leftMax = query(prefTree, 1, 0 , n-1, i+1, nge[i] - 1) - pref[i];
        int rightMax = query(suffTree, 1, 0, n-1, pge[i]+1, i-1) - suff[i];

        if(max(leftMax, rightMax) > 0){
            isTrue = false;
            break;
        }
    }

     if (isTrue) 
            cout << "YES\n";
        else 
            cout << "NO\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}


