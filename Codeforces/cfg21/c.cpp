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
    int n,m,k ; cin >> n >> m;
    vi a(n); for(int &x: a) cin >> x;
    cin >> k; vi b(k); for(int &x: b) cin>> x;

    // if((n-k)%(m-1)!=0){
    //     cout << "No\n";
    //     return;
    // }

    vector<pi> na;
    rep(i,0,n){
        int x = a[i]; int num =1;
        while((x%m)==0){
            x/=m;
            num*=m;
        }
        na.push_back({x,num});
    }

    dbg(na);
    vector<pi> nb;
    rep(i,0,k){
        int x = b[i], num =1;
        while((x%m)==0){
            x/=m;
            num*=m;
        }
        nb.push_back({x,num});
    }
    dbg(nb);



    vector<pi> ma, mb;
    int count = na.size();
    rep(i,0,count){
        if(i==0){
            ma.push_back(na[i]);
        }
        else{
            int prev = ma.size()-1;
            if(ma[prev].first == na[i].first){
                ma[prev].second+=na[i].second;
            }
            else{
                ma.push_back(na[i]);
            }
        }
    }
    count = nb.size();
    rep(i,0,count){
        if(i==0){
            mb.push_back(nb[i]);
        }
        else{
            int prev = mb.size()-1;
            if(mb[prev].first == nb[i].first){
                mb[prev].second+=nb[i].second;
            }
            else{
                mb.push_back(nb[i]);
            }
        }
    }

    dbg(ma);
    dbg(mb);

    if(ma.size() != mb.size()){
        cout << "NO\n";
        return;
    }

    count = ma.size();
    rep(i,0,count){
        if(ma[i]!=mb[i]){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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
