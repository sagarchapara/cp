// g++ -o out <filename>.cpp -D SAGAR
// .\out.exe

#include <bits/stdc++.h>
using namespace std;                                    

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x << " "; return os;}
void dbg_out() { cerr << "" << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << " "; dbg_out(T...); }
#ifdef SAGAR
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define pi pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vpi vector<pi>
#define vvpi vector<vpi>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define sz(x) (int)(x).size()

void solve() {
    int n, m; cin >> n >> m;
    vvi arr(n, vi(m));
    rep(i,0,n){
        rep(j,0,m){
            cin >> arr[i][j];
        }
    }   

    rep(b,0,10){
        vvi p(n);
        rep(i,0,n){
            rep(j,0,m){
                if((1<<b) & arr[i][j]){
                    p[i].push_back(j);
                }
            }
        }
        int x =0, y= 0, z =0;
        rep(i,0,n){
            if(p[i].size() == m){
                x++;
            }
            else if(p[i].size() > 0){
                y++;
            }
            else{
                z++;
            }
        }
        if((x+y)%2 == 1){
            puts("TAK");

            rep(i,0,n){
                if(p[i].size() >0){
                    printf("%d ", p[i].front()+1);
                }
                else{
                    printf("%d ", 1);
                }
            }
            printf("\n");
            return;
        }

        if(y == 0) continue;

        int num =0;

        puts("TAK");

        rep(i,0,n){
            if(p[i].size() >0){   
                if(p[i].size() == m){
                    printf("%d ", p[i].front()+1);
                }
                else{
                    if(num < (y-1)){
                        printf("%d ", p[i].front()+1);
                        num++;
                    }
                    else{
                        rep(j,0,m){
                            if((arr[i][j] & (1<<b)) == 0){
                                printf("%d ", j+1);
                                num++;
                                break;
                            }
                        }
                    }
                }
            }
            else{
                printf("%d ", 1);
            }
        }
        printf("\n");
        return;
    }

    puts("NIE");

}

int32_t main() {
    #ifdef SAGAR
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
    #endif

    auto start = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }

    auto stop = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();

    #ifdef SAGAR
        cerr << "Took " << stop - start << "ms" << endl;
    #endif
}
