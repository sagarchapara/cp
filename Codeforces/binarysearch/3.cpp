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

bool is_good(int g, int k, int n, vector<int>& arr){
    map<int, int> remaining;

    remaining[k] = g;

    for(int i=0;i<n;i++){
        int used = 0;

        map<int, int> should_use;

        for(auto itr = remaining.rbegin(); itr!= remaining.rend(); ++itr){
            int can_use = min(itr->second, arr[i]-used);

            if(can_use == 0){
                break;
            }

            //update 
            should_use[itr->first] =can_use;
            used+= can_use;
        }

        //now update those
        for(auto itr = should_use.rbegin(); itr != should_use.rend(); ++itr){
            //update the remaining map
            remaining[itr->first] -= should_use[itr->first];

            if(itr->first > 1){
                remaining[itr->first -1 ]+= should_use[itr->first];
            }

            if(remaining[itr->first] == 0){
                remaining.erase(itr->first);
            }
        }
    }

    if(remaining.size() == 0){
        return true;
    }
    
    return false;

}

void solve() {
    int k, n;

    cin >> k >> n;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), std::greater<int>());

    int l = 0;
    int r = 1e18;

    while(r-l>1){
        int mid = (l+r)/2;

        if(is_good(mid, k, n, arr)){
            l = mid;
        }
        else{
            r = mid-1;
        }
    }

    for(int i=r;i>=l;i--){
        if(is_good(i,k,n,arr)){
            cout << i << endl;

            return;
        }
    }

    cout << 0 << endl;
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
