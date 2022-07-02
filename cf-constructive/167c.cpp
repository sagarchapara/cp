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
    string s,t ; cin >> s >> t;
    int i=0; int currb =0, currc = 0;
    while(i<n){
        if(s[i] == t[i]) {
            i++;
            continue;
        }
        if(s[i] == 'a' && t[i] == 'b'){
            //find next b
            currb = max(i, currb); 
            while(currb < n && s[currb]=='a'){
                currb++;
            }
            if(currb == n || s[currb]!= 'b'){
                cout << "NO\n";
                return;
            }
            swap(s[i], s[currb]);
        }
        else if(s[i] == 'b' && t[i] == 'c'){
            //find next c
            currc = max(i, currc);
            while(currc < n && s[currc]=='b'){
                currc++;
            }
            if(currc == n || s[currc]!= 'c'){
                cout << "NO\n";
                return;
            }
            swap(s[i], s[currc]);
        }
        else{
            cout << "NO\n";
            return;
        }
        i++;
    }
    cout << "YES\n";
    return;
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
