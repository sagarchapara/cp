// g++ -o out <filename>.cpp
// cmd /c '.\out.exe < input.txt'

#include <bits/stdc++.h>                                    

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define mp make_pair
#define pb push_back



void solve(vector<int>& primes) {
    int n;
    cin >> n;

    int cnt  = primes.size();

    int start = 0;
    int end = cnt -1 ;

    while(start < end){
        int mid = (start+end)/2;

        int sqr = primes[mid]*primes[mid];

        if(sqr == n){
            cout << "YES" << endl;
            return;
        }

        if(sqr > n){
            end = mid-1;
        }

        if(sqr < n){
            start = mid+1;
        }
    }

    if(start >=0 && start < cnt && (primes[start]*primes[start]) == n){
        cout << "YES" << endl;
    }
    else if(end >=0 && end < cnt && (primes[end]*primes[end]) == n){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;

    int MAXN = 1e6+5;
    vector<int> primes;

    vector<int> is_prime(MAXN, true);

    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i <= MAXN; i+=2) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= MAXN; j += i)
                is_prime[j] = false;
        }
    }


    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve(primes);
    }
}
