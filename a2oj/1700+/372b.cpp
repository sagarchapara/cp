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
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x << " "; return os;}
void dbg_out() { cerr << ""; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << endl; dbg_out(T...); }
#ifdef SAGAR
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    dbg(n, m ,q);

    vector<vector<int>> arr(n);
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<m;j++){
            arr[i].push_back(s[j]-'0');
        }
    }


    dbg(arr);
    vector<vector<int>> left(n, vector<int>(m, 0));
    vector<vector<int>> sum(n, vector<int>(m, 0));

    for(int i=0;i<n;i++){
        stack<int> s;
        for(int j=m-1;j>=0;j--){
            if(arr[i][j]==1){
                left[i][j] = j;
                while(!s.empty()){
                    left[i][s.top()] = j;
                    s.pop();
                }
            }
            else{
                s.push(j);
            }
        }
        while(!s.empty()){
            left[i][s.top()] = -1;
            s.pop();
        }
    }

    dbg(left);
    

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sum[i][j] = 0;
            if(i-1 >= 0){
                sum[i][j]+=sum[i-1][j];
            }
            if(j-1 >=0){
                sum[i][j]+=sum[i][j-1];
            }
            if(i-1 >=0 && j-1 >=0){
                sum[i][j]-=sum[i-1][j-1];
            }
            if(arr[i][j] == 1){
                continue;
            }
            int mins = j-left[i][j];
            sum[i][j]+=mins;
            int k = i-1;
            int num =0;
            int inc =0;
            while(k>=0 && arr[k][j]==0){
                mins = min(mins, j- left[k][j]);
                int temp = (mins*(i-k+1));
                temp -= mins;
                temp -= (i-k+1);
                temp+=1;
                sum[i][j]+=temp;
                sum[i][j]-=inc;
                inc = temp;
                k--;
                num++;
            }
            sum[i][j]+=num;
        }
    }

    dbg(sum);

    for(int i=0;i<q;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d ;

        // int ans = sum[c-1][d-1] + sum[a-1][b-1] - sum[c-1][b-1] - sum[a-1][d-1];
        int ans = sum[c-1][d-1];
        if(c-2>=0)

        cout << ans << endl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

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
