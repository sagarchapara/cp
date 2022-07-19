// // g++ -o out <filename>.cpp -D SAGAR
// // .\out.exe

// #include <bits/stdc++.h>
// using namespace std;                                    

// template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
// template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x << " "; return os;}
// void dbg_out() { cerr << "" << endl; }
// template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H ; dbg_out(T...); }
// #ifdef SAGAR
// #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
// #else
// #define dbg(...)
// #endif

// #define int long long
// #define pi pair<int,int>
// #define vi vector<int>
// #define vpi vector<pi>
// #define all(x) (x).begin(), (x).end()
// #define rall(x) (x).rbegin(), (x).rend()
// #define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
// #define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
// #define sz(x) (int)(x).size()

// void solve() {
//     int n, m; cin >> n >> m;
//     vector<set<int>> arr(n);
//     vector<set<int>> pos(m+1);
//     vector<int> f;
//     rep(i,0,n){
//         int x,y; cin >> x >> y;
//         arr[i].insert(x);
//         arr[i].insert(y);
//         pos[x].insert(i);
//         pos[y].insert(i);
//         f.push_back(x); f.push_back(y);
//     }
//     sort(all(f)); Unique(f);

//     dbg(f); dbg(pos);

//     int num = f.size();

//     int start = 0, end = 0;

//     vpi p;

//     int curr = f[0]; set<int> idx; idx.insert(all(pos[f[0]]));
//     for(int i=1;i<num;i++){
//         if(f[i] != curr+1){
//             if(idx.size() == n){
//                 p.push_back({start,end});
//                 idx.clear();
//             }
//             start = i;
//         }
//         idx.insert(all(pos[f[i]]));
//         end = i;
//         curr = f[i];
//     }
//     if(idx.size() == n){
//         p.push_back({start,end});
//     }
//     dbg(pos);
//     dbg(p);

//     vi ans(m+1,0);

//     for(auto [x,y]:p){

//         vector<vi> t(n);

//         for(int i=x;i<=y;i++){
//             dbg(f[i]);
//             dbg(pos[f[i]]);
//             for(int k: pos[f[i]]){
//                 t[k].push_back(i);
//             }
//         }

//         dbg(t);
        
//         int max_idx = n;
//         for(int i=y;i>=x;i--){
//             for(int k: pos[f[i]]){
//                 bool isLess = false;
//                 for(int a: t[k]){
//                     if(a<i) isLess = true;
//                 }
//                 if(!isLess){
//                     max_idx =i;
//                     goto next;
//                 }
//             }
//         }

//         next:

//         dbg(max_idx);

//         // ans[y-x+1]++;
        

//         // bool completed = false;
//         // for(int i=x+1;i<=y;i++){
//         //     for(int k: pos[f[i-1]]){
//         //         bool isLess = true;
//         //         for(int a: t[k]){
//         //             if(a>=i) isLess = false;
//         //         }
//         //         if(isLess) goto fin;
//         //         max_idx = max(max_idx, t[k][0]);
//         //         max_idx = max(max_idx, t[k][1]);
//         //     }
//         //     // ans[y-i+1]++;
//         //     ans[max_idx-i]++;
//         // }

//         fin:
//             continue;
//     }

//     dbg(ans);

//     for(int i=m-1;i>=0;i--){
//         ans[i]+=ans[i+1];
//     }

//     rep(i,1,m+1){
//         printf("%d ", ans[i]);
//     }
//     printf("\n");

// }

// int32_t main() {
//     #ifdef SAGAR
//         freopen("input.txt", "r", stdin);
//         // freopen("output.txt", "w", stdout);
//     #else
//         ios_base::sync_with_stdio(0);
//         cin.tie(0); cout.tie(0);
//     #endif

//     int tc = 1;
//     // cin >> tc;
//     for (int t = 1; t <= tc; t++) {
//         solve();
//     }
// }
