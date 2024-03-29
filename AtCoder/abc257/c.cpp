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

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vi arr(n);
    map<int,int> child, adult;

    rep(i,0,n){
        int w; cin >> w; arr[i] = w;
        if(s[i]=='0'){
            if(!child.count(w)){
                child[w]=0;
            }
            child[w]++;
        }
        else{
            if(!adult.count(w)){
                adult[w]=0;
            }
            adult[w]++;
        }
    }

    int val =0;
    for(auto [k,v]: child){
        val+=v;
        child[k] = val;
    }

    val = 0;
    for (auto iter = adult.rbegin(); iter != adult.rend(); ++iter) {
        val+= iter->second;
        adult[iter->first] = val;
    }

    dbg(child); dbg(adult);

    int ans =0;
    rep(i,0,n){
        int w = arr[i], w2 = (arr[i]+1);
        int total =0;

        auto it = child.lower_bound(w);
        if(it != child.begin()){
            --it;
            total+= it->second;
        }
        

        it = adult.lower_bound(w);
        if(it != adult.end()){
            total += it->second;
        }

        ans = max(ans, total);

        total =0;

        it = child.lower_bound(w2);
        if(it != child.begin()){
            --it;
            total+= it->second;
        }
        

        it = adult.lower_bound(w2);
        if(it != adult.end()){
            total += it->second;
        }

        ans = max(ans, total);
    }

    cout << ans;    
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
