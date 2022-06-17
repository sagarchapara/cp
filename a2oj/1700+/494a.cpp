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
    string s;
    cin >> s;

    int cntl =0, cntr =0, cnth =0, last_pos;

    int i =0;
    for(char c:s){
        if(c == '('){   
            cntl++;
        }
        else if(c == ')'){
            cntr++;
        }
        else{
            cnth++;
            last_pos = i;
        }
        i++;
    }

    if(cntl <= cntr){
        cout << -1;
        return;
    }

    if(cntl - cntr < cnth){
        cout << -1;
        return;
    }

    int n = s.size();
    int count  =0;
    int num = cntl - cntr;

    for(int i=0;i<n;i++){
        if(s[i] == '('){   
            count++;
        }
        else if(s[i] == ')'){
            count--;
        }
        else{
            if(i!=last_pos){
                count--;
            }
            else{
                count -= (cntl-cntr-cnth+1);
            }
        }

        if(count < 0){
            cout << -1;
            return;
        }
    }

    

    for(int i=0;i<cnth;i++){
        if(i==cnth-1){
            cout << (num-cnth+1) << endl;
        }
        else{
            cout << 1 << endl;
        }
    }
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
