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

int _gcd(int x, int y){
    if(y == 0){
        return x;
    }

    return gcd(y, x%y);
}

class GCDStack{
    stack<int> s;
    stack<int> gcd_s;

public:
    GCDStack(){}

    void push(int num){
        s.push(num);

        if(s.size() == 1){
            gcd_s.push(num);
        }
        else{
            gcd_s.push(_gcd(num,gcd_s.top()));
        }
    }

    void pop(){
        s.pop();
        gcd_s.pop();
    }

    int top(){
        return s.top();
    }

    bool empty(){
        return s.empty();
    }

    int gcd(){
        return gcd_s.top();
    }
};


class Queue{
    GCDStack s1;
    GCDStack s2;

public:
    Queue(){}

    void push_back(int num){
        s2.push(num);
    }

    void pop_front(){
        if(s1.empty()){
            //move all elements from s2 to s1
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }

        s1.pop();
    }

    int gcd(){
        if(s1.empty()){
            return s2.gcd();
        }
        else if(s2.empty()){
            return s1.gcd();
        }
        else{
            return _gcd(s1.gcd(), s2.gcd());
        }
    }

    int empty(){
        return s1.empty() && s2.empty();
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    dbg(arr);

    Queue queue;

    int ans = -1;
    int l =0;

    for(int r =0;r<n;r++){
        queue.push_back(arr[r]);

        dbg(l, r, queue.gcd());

        while(!queue.empty() && queue.gcd() == 1){

            dbg("gcd is one", l, r);
            
            //update answer may be
            //for this given l ... r
            if(ans == -1){
                ans = (r-l+1);
            }
            else{
                ans = min(ans, r-l+1);
            }


            queue.pop_front();
            l++;
        }

        dbg(ans);
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
