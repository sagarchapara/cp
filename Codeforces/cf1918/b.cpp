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

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;

    vi arr(n), p(n), rev(n);

    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    for(int i=0;i<n;i++)
    {
        cin >> p[i];
        rev[p[i]-1] = i;
    }

    vector<pair<int,int>> vp;

    for(int i=0;i<n;i++)
    {
        vp.emplace_back(arr[i], rev[i]+1);
    }

    dbg(vp);

    sort(vp.begin(), vp.end(), [](const pair<int,int>& p, const pair<int,int>& q){
        if(p.first == q.first)
        {
            return p.second < q.second;
        }
        
        return p.first > q.first;
    });

    //dbg(vp);

    int ans = 0, anspos = 0, currpos = 0;

    set<int> curr_set;

    for(int i=0;i<n;i++)
    {
        //dbg(currpos);

        int num = i+1;

        int need = 1;
        
        //remove previous index if exists
        if(curr_set.find(i) != curr_set.end())
        {
            need++;
            curr_set.erase(i);
        }

        while (currpos < n && need > 0)
        {
            if(vp[currpos].second > i)
            {
                need--;
                curr_set.insert(vp[currpos].second);
            }

            currpos++;
        }

        if(need > 0)
        {
            //not possible from now on
            break;
        }

        //comeback to the last entered one
        currpos--;

        //w
        if( num * vp[currpos].first > ans ){
            anspos = num;
            ans = num * (vp[currpos].first);

            //dbg(ans, anspos, num, currpos);
        }

        currpos++;
    }

    cout << ans << " " << anspos << endl;
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
