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

int pref[19];
int power[19];

int find(int given){
    if(given ==0){
        return 1;
    }
    vi arr; int n = 0;
    while(given!=0){
        arr.push_back(given%10);
        given = given/10;
        n++;
    }
    dbg(arr);
    int num = pref[n-1];
    dbg(num);
    int s =0;
    for(int i = n-2; i >=1 ;i--){
        s = s*10 + arr[i];
    }
    dbg(s);
    num+= (s+1);
    if(arr[n-1] > arr[0]){
        --num;
        dbg(num);
        if(arr[n-1]>1){
            num+= (arr[n-1]-1)*(power[n-2]);
        }
        dbg(num);
    }
    else if(arr[n-1] < arr[0]){
        if(arr[n-1]>1){
            num+= (arr[n-1]-1)*(power[n-2]);
        }
        dbg(num);
    }
    else{
        dbg(num);
        if(n>=2){
            num+= (arr[n-1]-1)*(power[n-2]);
        }
        else if (n==1){
            num+= (arr[n-1]);
        }
        dbg(num);
    }

    return num;
}


void solve() {
    int l,r; cin >> l >> r;

    power[0] = 1;
    rep(i,1,19){
        power[i] = power[i-1]*10;
    }

    pref[0] =0; pref[1] =10; pref[2] =9;
    rep(i,3,19){
        pref[i] = pref[i-1]*10;
    }
    rep(i,1,19){
        pref[i]+=pref[i-1];
    } 

    int ans = find(r) - find(l-1);

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
