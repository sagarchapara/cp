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

struct Interval{
    int index;
    int start;
    int end;

    Interval(int idx, int s, int e): index(idx), start(s), end(e){}

    bool operator<(const Interval& other) const{
        if(end != other.end){
            return end < other.end;
        }
        else if(start != other.start){
            return start < other.start;
        }
        
        return index < other.index;
    }
};


set<int> is_possible(int k, int a, vector<Interval> intervals){
    int n = intervals.size();
    
    multiset<Interval> s;

    set<int> solution;

    int num_taken = 0;

    for(int i=0;i<n;i++){
        //remove that are ending <= intervals[i]
        while(!s.empty() && s.begin()->end <= intervals[i].start){
            s.erase(s.begin());
        }

        if(s.size() < k){
            s.insert(intervals[i]);
            num_taken++;
            solution.insert(intervals[i].index);
            continue;
        }

        if(!s.empty() && s.rbegin()->end > intervals[i].end){
            //then i can take this
            solution.erase(prev(s.end())->index);
            s.erase(prev(s.end()));
            s.insert(intervals[i]);

            solution.insert(intervals[i].index);
        }
    }

    if(num_taken >= a){
        return solution;
    }
    else{
        return set<int>();
    }
}

void solve() {
    int n, a; cin >> n >> a;

    vector<Interval> intervals;

    for(int i=0;i<n;i++){
        int u,v; cin >> u >> v;
        intervals.emplace_back(i+1, u, u+v);
    }

    sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
        if(a.start == b.start){
            a.end < b.end;
        }

        return a.start < b.start;
    });

    int l = 1, r = a;

    set<int> s;

    while(r-l > 1){
        int mid = (l+r)/2;

        s = is_possible(mid, a , intervals);
        if(!s.empty()){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }

    for(;l<=r;l++){
        s = is_possible(l, a, intervals);

        if(!s.empty()) break;
    }

    cout << l << endl;

    for(int i: s){
        cout << i << " ";
    }
    cout << endl;
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
