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

#define MAX_NUM 2

class Trie{

    struct Node{
        bool isRoot;
        int child[MAX_NUM];
        bool isEnd;

        Node(bool _isRoot, bool _isEnd): isRoot(_isRoot), isEnd(_isEnd){
            for(int i=0;i<MAX_NUM;i++){
                child[i] = -1;
            }
        }
    };

    vector<Node> nodes;

public:
    Trie(){
        nodes.emplace_back(true, false);
    }

    int add(string& s){

        int curr_idx = 0;

        int ans = 0;

        for(char c: s){
            int idx = c -'0';

            Node& curr = nodes[curr_idx];

            dbg(idx, curr_idx, curr.child[idx]);

            if(curr.child[idx] == -1){
                curr_idx = nodes.size();

                curr.child[idx] = curr_idx;

                nodes.emplace_back(false, false);

                ans++;
            }
            else{
                curr_idx = curr.child[idx];
            }
        }

        assert(curr_idx != -1);

        nodes[curr_idx].isEnd = true;

        return ans;
    }
};

void solve() {
    int n, k; cin >> n >> k;

    Trie trie;

    int ans = k;

    for(int i=0;i<n;i++){
        string s; cin >> s;

        int val = trie.add(s);

        dbg(val);

        ans = min(ans, val);
    }

    cout << ans << endl;
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
