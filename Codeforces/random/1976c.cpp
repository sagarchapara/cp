// g++ -o out <filename>.cpp -D SAGAR
// .\out.exe

//https://codeforces.com/contest/1976/problem/C

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


int search(vector<int>& num_p, int pos, bool p_or_q, int diff){
    int l = pos+1, r = num_p.size() -1;

    while (l<r)
    {
        int mid = (l+r+1)/2;

        int num;

        if(p_or_q)
        {
            num = num_p[pos+1] - num_p[mid];
        }
        else
        {
            num = (mid - pos) - (num_p[pos+1] - num_p[mid]);
        }

        if(num == diff)
        {
            if(mid == 0) return 0;

            if (num_p[mid] - num_p[mid-1] == (p_or_q ? 1 : 0))
            {
                return mid;
            }
        }
        
        if (num >= diff){
            r = mid-1;
        }
        else{
            l = mid + 1;
        }
    }

    //let's check
    if(p_or_q){
        assert(diff == num_p[pos+1] - num_p[l]);
    }
    else{
        assert(diff == (l - pos) - (num_p[pos+1] - num_p[l]));
    }

    return l;
}

void solve() {
    int n, m;

    cin >> n >> m;

    vector<int> p (n+m+1), t(n+m+1);

    vector<int> suff_p(n+m+1), suff_t(n+m+1), suff_g(n+m+1);

    vector<int> num_p(n+m+1);

    for(int i=0;i<n+m+1;i++){
        cin >> p[i];
    }

    for(int i=0;i<n+m+1;i++){
        cin >> t[i];
    }

    dbg(p,t, n,m);

    suff_g[n+m] = max(p[n+m], t[n+m]);
    suff_t[n+m] = t[n+m];
    suff_p[n+m] = p[n+m];
    num_p[n+m] = (p[n+m] > t[n+m] ? 1 : 0);

    for(int i=n+m-1;i>=0;i--){
        suff_p[i] = p[i] + suff_p[i+1];
        suff_t[i] = t[i] + suff_t[i+1];
        suff_g[i] = max(p[i], t[i]) +  suff_g[i+1];

        num_p[i] = (p[i] > t[i] ? 1 : 0) + num_p[i+1];
    }

    dbg(suff_p, suff_g, suff_t, num_p);

    int np =0 , nt= 0, val = 0;

    for(int i=0;i<n+m;i++){
        int ans = val;

        int next_val = val;
        int next_p = np, next_t = nt;

        if (np == n){
            ans += suff_t[i+1];

            next_val += t[i];
            next_t++;
        }
        else if(nt == m){
            ans += suff_p[i+1];

            next_val += p[i];
            next_p++;
        }
        else{
            //you need to find pos where num_p[k] - num_p[i] == n - np
            // num_t[k] - num_t[i] == m - nt
            int sp = search(num_p,i,true, n - np);
            int sq = search(num_p,i,false, m-nt );

            dbg(i, sp, sq);

            if(sp < sq)
            {
                ans += suff_g[i+1];

                if (sp +1<=n+m){
                    ans-=suff_g[sp+1];
                    ans+=suff_t[sp+1];
                }
            }
            else
            {
                ans += suff_g[i+1];

                if(sq+1<=n+m){
                    ans-=suff_g[sq+1];
                    ans+=suff_p[sq+1];
                }
            }

            if(p[i] > t[i]){
                next_val+= p[i];
                next_p++;
            }
            else{
                next_val+=t[i];
                next_t++;
            }
        }

        cout << ans << " ";

        val = next_val;
        np = next_p;
        nt = next_t;
    }

    cout << val << endl;
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
