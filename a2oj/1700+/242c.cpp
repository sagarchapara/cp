// g++ -o out <filename>.cpp
// .\out.exe

// #define SAGAR

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
template<typename x,typename y>void read(pair<x,y>& a){ read(a.first),read(a.second);}
template<typename x>void read(x& a){for(auto  &i : a) read(i);}
template<typename... x>void read(x&... a){((read(a)), ...);}


/*
 *==========================================
 * Output and Debug
 *==========================================
 */

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
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >>x2 >> y2; --x1 ;--y1; --x2; --y2;

    int n; cin >> n;

    map<int,vector<pi>> rows;

    rep(i,0,n){
        int r, x, y;
        cin >> r >> x >> y; --r ; --x; --y;
        rows[r].push_back({x,y});
    }

    for(auto [key, val]: rows){
        dbg(key);
        dbg(val);
    }

    set<pi> points;

    for(auto [key, val]: rows){
        sort(all(val));

        vector<pi> merge;
        int start = val[0].F , end = val[0].S;
        for(auto p: val){
            if(p.F > end){
                merge.push_back({start,end});
                start = p.F; end = p.S;
            }
            else{
                end = max(end, p.S);
                start = min(start, p.F);
            }
        }

        merge.push_back({start, end});

        for(auto p: merge){
            rep(i, p.F, p.S+1){
                points.insert({key,i});
            }
        }
        dbg(key);
        dbg(points);
    }

    queue<pair<pi,int>> q;

    pi start = {x1,y1};
    pi dest = {x2,y2};

    q.push({{x1,y1},0});
 

    map<pi,bool> visited;

    visited[start] = true;

    while(q.size() >0 ){
        pair<pi,int> cur = q.front(); q.pop();

        dbg(cur);

        if(cur.F == dest){
            cout << cur.S << endl;
            return;
        }

        rep(i,-1,2){
            rep(j,-1,2){
                if(i==0 && j==0){
                    continue;
                }
                pi p = {cur.F.F+i, cur.F.S +j};
                if(points.count(p)){
                    if(!visited[p]){
                        q.push({p,cur.S+1});
                        visited[p] = true;
                    }
                }
            }
        }
    }

    cout << -1;
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
