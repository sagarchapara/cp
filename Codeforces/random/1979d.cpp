// g++ -o out <filename>.cpp -D SAGAR
// .\out.exe

#include <bits/stdc++.h>
using namespace std;                                    

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x << " "; return os;}
void dbg_out() { cerr << "" << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << " " ; dbg_out(T...); }
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


vector<int> Z_func(string& s, string& p){
    string k = p + "#" + s;

    vector<int> z (s.size()+p.size()+1, 0);

    int l =0,r= 0;

    for(int i=1;i<z.size();i++){
        if(r > i){
            z[i] = min(z[i-l], r-i);
        }

        while (i+z[i]<z.size() && k[z[i]] == k[i+z[i]])
        {
            z[i]++;
        }

        if(z[i] > 0 && i+z[i] > r){
            l = i;
            r = i+z[i];
        }
    }

    dbg(z);

    //now map from (p + n + 1) --> (n)
    vector<int> ans(s.size());

    for(int i=p.size()+1;i<z.size();i++){
        ans[i-(p.size()+1)] = z[i];
    }

    return ans;
}

string get_string(int n, int k, bool one_or_zero){
    string p;

    bool one = one_or_zero;
    int num = k;

    for(int i=0;i<n;i++){
        if(one){
            p+='1';
            num--;

            if(num ==0){
                one = false;
                num =k;
            }
        }
        else{
            p+='0';
            num--;

            if(num == 0){
                one = true;
                num =k;
            }
        }
    }

    return p;
}

void solve() {
    int n,k;

    cin >> n >> k;

    string s;

    cin >> s;

    //there are two possibilities
    //000...111...000...
    //111...000...111...
    //first verify if char sizes matches
    int n_ones =0, n_zeros=0;

    for(char& c: s){
        n_ones += (c-'0');
    }

    n_zeros = n - n_ones;

    dbg(n_ones, n_zeros);

    if(n_ones%k !=0)
    {
        cout << -1 << endl;
        return;
    }

    if((abs(n_ones-n_zeros)/k) > 1)
    {
        cout << -1 << endl;
        return;
    }

    bool one_poss = false;
    bool zero_poss = false;

    if(n_ones == n_zeros){
        //two are possible
        one_poss = true;
        zero_poss = true;
    }
    else if(n_ones > n_zeros){
        //starts with ones
        one_poss = true;
    }
    else{
        //starts with zeros
        zero_poss = true;
    }
    dbg(one_poss, zero_poss);

    if(one_poss){
        string p = get_string(n, k, true);

        vector<int> z = Z_func(s, p);

        dbg("one_poss", p, z);

        bool matching_suffix = (s[0] == p[n-1]);

        for(int i=1;i<=n;i++){

            //then the reverse prefix should match
            if(i > 0){
                matching_suffix &= (s[i-1] == p[n-i]);
            }

            if(!matching_suffix){
                break;
            }

            if(z[i] == (n-i)){
                //means if it equals the whole prefix, then it's a candidate
                if(matching_suffix){
                    cout << i << endl;

                    return;
                }

            }
        }
    }

    if(zero_poss){
        string p = get_string(n, k, false);

        vector<int> z = Z_func(s, p);

        dbg("zero_poss", p, z);

        bool matching_suffix = (s[0] == p[n-1]);

        for(int i=1;i<=n;i++){

            //then the reverse prefix should match
            if(i > 0){
                matching_suffix &= (s[i-1] == p[n-i]);
            }

            if(!matching_suffix){
                break;
            }

            if(z[i] == (n-i)){
                //means if it equals the whole prefix, then it's a candidate
                if(matching_suffix){
                    cout << i << endl;
                    return;
                }
            }
        }
    }

    cout << -1 << endl;
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
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }

    auto stop = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();

    #ifdef SAGAR
		cerr << "Took " << stop - start << "ms" << endl;
	#endif
}
