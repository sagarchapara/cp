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

void solve() {
    int a,b ; cin >> a >> b;
    string s; cin >> s;

    int num = sz(s)+1;

    vpi points(num);
    pi curr = {0,0}; int n_x = 0, n_y =0;

    points[0] = curr;

    rep(i,1,num){
        char c = s[i-1];
        if(c == 'R'){
            curr.F++; n_x++;
            
        }
        else if( c== 'L'){
            curr.F --; n_x--;
        }
        else if(c=='U'){
            curr.S++; n_y++;
        }
        else{
            curr.S-- ; n_y--;
        }
        points[i] = curr;
    }

    // dbg(points);

    // dbg(n_x); dbg(n_y);
    pi to = {a,b};

    rep(i,0,num){
        int x_diff = to.F - points[i].F;
        int y_diff = to.S - points[i].S;

        // dbg(i); dbg(x_diff); dbg(y_diff);

        if(n_x ==0){
            if(x_diff!=0){
                continue;
            }
        }
        if(n_y ==0){
            if(y_diff!=0){
                continue;
            }
        }

        int xrem = (n_x ==0)? 0 : (x_diff% n_x);
        int yrem = (n_y ==0)? 0 : (y_diff%n_y);

        if( xrem==0 && yrem==0){

            // dbg(i); dbg(x_diff); dbg(y_diff); dbg(points[i]); dbg(n_x); dbg(n_y);

            if(n_x == 0 || n_y ==0){
                if(n_y!=0){
                    int k2 = y_diff/n_y;
                    if(k2 <0){
                        continue;
                    }
                }
                else if(n_x!=0){
                    int k1 = x_diff/n_x;
                    if(k1<0){
                    continue;
                    }
                }
                cout << "Yes" << endl;
                return;
            }

            int k1 = x_diff/n_x;
            int k2 = y_diff/n_y;

            if(k1==k2 && k1 >=0){
                cout << "Yes" << endl;
                return;
            }
        }
    }

    cout << "No" << endl;

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
