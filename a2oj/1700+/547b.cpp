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
#define all(x) (x).begin(), (x).end()
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define sz(x) (int)(x).size()

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

vector<int> prevLesserElem(vector<int>& v){
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
    int n ; cin >> n;
    vi arr(n); for(int &x:arr) cin >> x;

    vi nle = nextLesserElem(arr);
    vi ple = prevLesserElem(arr);

    vi ans(n,1);

    // dbg(nle); dbg(ple);

    rep(i,0,n){
        int left = ple[i]; 
        int right = nle[i];
        int len = (right -left-1);
        // dbg(len);
        ans[len-1] = max(ans[len-1], arr[i]);
    }

    // dbg(ans);

    rep(i,n-1,0){
        ans[i] = max(ans[i], ans[i+1]);
    }

    cout << ans<< endl;

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
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
