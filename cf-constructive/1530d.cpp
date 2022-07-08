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
#define vvi vector<vi>
#define all(x) (x).begin(), (x).end()
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vi arr(n); for(int &x: arr) cin >> x;
    vi assn(n); int ans =0;
    vvi  egdes(n);
    rep(i,0,n){
        egdes[arr[i]-1].push_back(i);
    }
    vector<bool> visit(n, false), assigned(n, false);

    for(int i=0;i<n;i++){
        int size = egdes[i].size();
        if(size>0){
            int back = egdes[i][size-1]; 
            assn[back] = i+1;
            visit[i] = true;
            assigned[back] = true;
            ans++;
        }
    }

    int curr = n-1;
    int first = -1;
    for(int i=0;i<n;i++){
        if(!assigned[i]){
            if(first == -1){
                first = i;
            }
            while(curr >= 0 && visit[curr] == true){
                curr--;
            }
            assigned[i] = true;
            assn[i] = (curr+1);
            visit[curr]= true;
        }
    }

    // dbg(first);

    if(first!=-1){
        for(int i=0;i<n;i++){
            if(assn[i] == (i+1)){
                if(first == i){
                    int s = egdes[arr[i]-1].size();
                    int next = egdes[arr[i]-1][s-1];
                    swap(assn[i], assn[next]);
                }
                else{
                    swap(assn[first], assn[i]);
                }
            }
        }
    }
    

    cout << ans << endl;
    cout << assn << endl;
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
