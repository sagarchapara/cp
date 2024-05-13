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

bool isPossible(int k, vi& arr, vi& pref)
{
    int n = arr.size();

    vi dp(n);

    set<pi> curr_val;

    for(int i=n-1;i>=0;i--)
    {
        if(arr[i] > k)
        {
            return false;
        }

        while(curr_val.size() > 0)
        {
            //check for the top one, see if the prefix sum is less than k
            int idx = curr_val.begin()->second;

            int val = pref[idx-1] - pref[i];

            if(val <= k)
            {
                break;   
            }

            //erase the element as it's too forward
            curr_val.erase(curr_val.begin());
        }

        int next = pref[n-1] - pref[i];

        if(next > k && curr_val.size() == 0)
        {
            //suffix is too big, then no answer
            return false;
        }

        if(next <= k)
        {
            dp[i] = arr[i];
        }
        else
        {
            dp[i] = curr_val.begin()->first + arr[i];
        }

        curr_val.insert({dp[i], i});
    }

    for(int i=0;i<n;i++)
    {
        bool isFound = dp[i] <= k;

        if(i > 0)
        {
            isFound &= (pref[i-1] <= k);
        }

        if(isFound)
        {
            return true;
        }
    }

    return false;
}

void solve() {
    int n;

    cin >> n;

    vi arr(n), pref(n);

    for(int i=0;i<n;i++)
    {
        cin >> arr[i];

        pref[i] = arr[i];

        if(i>0)
        {
            pref[i]+=pref[i-1];
        }
    }

    int l = 0, r = 1e14;

    while (l < r)
    {
        int mid = (l+r)/2;

        if(isPossible(mid, arr, pref))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << l << endl;
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
