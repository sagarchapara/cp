// g++ -o out <filename>.cpp
// .\out.exe

#define SAGAR

#include <bits/stdc++.h>
using namespace std;                                    

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x << " "; return os;}
void dbg_out() { cerr << ""; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << endl; dbg_out(T...); }
#ifdef SAGAR
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define F first
#define S second
#define pi pair<int,int>
#define vi vector<int>
#define vpi vector<pi>
#define all(x) (x).begin(), (x).end()
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define sz(x) (int)(x).size()

const int MAXN = 3e5;

vpi tmin, tmax;

//build v= 1 tl=0 tr=n-1

pi merge(pi& a, pi&b, bool minmax){
    pi ans;
    if(minmax){
        if(a.first < b. first) ans = a;
        else ans = b;  
    }
    else{
        if(a.first > b.first) ans = a;
        else ans =b;
    }
    return ans;
}

void build(vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        tmin[v] = {a[tl], tl};
        tmax[v] = {a[tl], tl};
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        tmin[v] = merge(tmin[v*2], tmin[v*2+1], true);
        tmax[v] = merge(tmax[v*2], tmax[v*2+1], false);
    }
}

pair<pi,pi> query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return {{MAXN,-1},{0,-1}};
    if (l == tl && r == tr) {
        return {tmin[v], tmax[v]};
    }
    int tm = (tl + tr) / 2;
    pair<pi,pi> a = query(v*2, tl, tm, l, min(r, tm));
    pair<pi,pi> b =query(v*2+1, tm+1, tr, max(l, tm+1), r);
    return {merge(a.first, b. first, true), merge(a.second, b.second, false)};
}

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

vector<int> nextLesserElem(vector<int>& v){
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



void solve() {
    int n; cin >> n;
    vi arr(n); for(int &x: arr) cin >> x;

    vi nge = nextGreaterElem(arr);
    vi nle = nextLesserElem(arr);

    tmin.clear(); tmax.clear();
    tmin.resize(4*n); tmax.resize(4*n);

    build(arr,1,0,n-1);

    vi dp(n); dp[n-1] =0;

    for(int i=n-2;i>=0;i--){
        int ngElem = nge[i];
        int nlElem = nle[i];

        dp[i] = dp[i+1]+1;
        //find index of min val from i+1 to nge-1
        auto minVal = query(1,0,n-1,i+1,ngElem-1);
        if(minVal.first.second != -1){
            dp[i] = min(dp[minVal.first.second]+1, dp[i]);
        }
        
        auto maxVal = query(1,0,n-1,i+1,nlElem-1);
        if(maxVal.second.second!=-1){
            dp[i] = min(dp[maxVal.second.second]+1 , dp[i]);
        }
    }

    cout << dp[0] << endl;
}

int32_t main() {
    #ifdef SAGAR
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
    #endif

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
