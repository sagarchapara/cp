// g++ -o out <filename>.cpp
// .\out.exe

#define SAGAR

#include <bits/stdc++.h>
using namespace std;                                    


/*
 *==========================================
 * Input 
 *==========================================
 */
void read(){}
void read(long long& a){scanf("%lld",&a);}
void read(long& a){scanf("%ld",&a);}
void read(int& a){scanf("%d",&a);}
void read(double& a){scanf("%lf",&a);}
void read(float& a){scanf("%f",&a);}
void read(string& a){cin>>a;}
template<typename x>void read(x& a){for(auto  &i : a) read(i);}
template<typename x,typename y>void read(pair<x,y>& a){ read(a.first),read(a.second);}
template<typename... x>void read(x&... a){((read(a)), ...);}


/*
 *==========================================
 * Output and Debug
 *==========================================
 */

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x ; return os;}
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
#define rall(x) (x).rbegin(), (x).rend()
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define sz(x) (int)(x).size()

void solve() {
    int n;
    cin >> n;
    vi arr(9);
    rep(i, 0, 9){
        cin >> arr[i];
    }
    map<int, int> cost;
    
    rep(i, 0, 9){
        cost[arr[i]] = (i+1);
    }

    int min_cost = cost.begin()->first;

    int num = n/(cost.begin()->first);

    if(num <=0){
        cout << -1;
        return;
    }

    int rem = n - (num)*min_cost ;

    vi ans;

    while( rem > 0){

        dbg(rem);

        int next = cost.begin()->second;

        int nxtCost = 0;

        bool isFound = false;

        for (auto const& [key, val] : cost)
        {
            if(key <= (rem + min_cost)){
                if(val > next){
                    next = val;
                    nxtCost = key;
                    isFound = true;
                }
            }
        }

        if(!isFound){
            break;
        }

        rem-=nxtCost;
        rem+=min_cost;
        ans.push_back(next);

        dbg(rem);
    }
    
    dbg(ans);

    dbg(num-sz(ans));

    // int k = num - sz(ans);
    // for(int i=0;i<k; i++){
    //     ans.push_back(cost.begin()->second);
    // }

    int k = num - sz(ans);
    rep(i, k, 0){
        ans.push_back(cost.begin()->second);
        dbg("1sas");  
        dbg(i); 
    }

    dbg(ans);

    sort(rall(ans));

    

    

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
