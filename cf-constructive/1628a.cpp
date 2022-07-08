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
#define si set<int>
#define vsi vector<si>
#define all(x) (x).begin(), (x).end()
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define sz(x) (int)(x).size()

void print(vi& ans){
    printf("%d\n", ans.size());
    for(int i : ans){
        printf("%d ", i);
    }
    printf("\n");
}

int solve(vi& arr,int l, int n ,vi& ans, vi& suff, vsi& pos){
    if(l>n){
        return n;
    }
    if(suff[l] == n-l){
        ans.push_back(suff[l]);
        return n;
    }
    if(suff[l] == 0){
        for(int i=l;i<n;i++){
            ans.push_back(0);
        }
        return n;
    }
    ans.push_back(suff[l]);
    int mex = suff[l], next =l;
    for(int i=0;i<mex;i++){
        auto it = pos[i].lower_bound(l);
        next = max(*it, next);
    }
    // dbg(next);
    return next;
}


void solve() {
    int n; cin >> n;
    vi cnt(n+1); vi suff(n); int mex =0; vsi pos(n+1);
    vi arr(n); 
    for(int i=0;i<n;i++){
        int x; cin >> x;
        cnt[x]++; 
        arr[i] = x;
        pos[x].insert(i);
    }
    while(mex <n && cnt[mex]>0){
        mex++;
    }
    // dbg(arr);

    for(int i=0;i<n;i++){
        suff[i] = mex;
        if(arr[i]< mex){
            if(cnt[arr[i]] == 1 ){
                mex = arr[i];
            }
        }
        cnt[arr[i]]--;
    }
    // dbg(suff);

    
    vi ans; int curr =0;

    while(curr < n){
        curr = solve(arr, curr, n, ans, suff,pos);
        // dbg(curr); dbg(pos);
        curr++;
    }

    print(ans);
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
