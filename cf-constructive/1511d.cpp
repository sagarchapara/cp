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
    int n,k; cin >> n >> k;
    string s; int ans;
    int num = k*k+1;

    ans = n; int itr = 0;

    int curr =0; int start = 0; char c;
    while(curr < ans){
        for(int i=0;i<k;i++){
            if(curr == ans) goto end;  
            c = 'a'+i; s+=c; curr++;
            if(curr == ans) goto end;

            // if(i==k-1 && itr == 0){
            //     c = 'a'; s+=c; curr++;
            //     if(curr == ans) goto end;
            //     continue;
            // }

            for(int j=i+1;j<k;j++){
                c = 'a'+i; s+=c; curr++;
                if(curr == ans) goto end;
                c = 'a'+j; s+=c; curr++;
                if(curr == ans) goto end;
            }     
        }
        itr++;
    }
    
    
    end:
        cout << s<< endl;
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
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
