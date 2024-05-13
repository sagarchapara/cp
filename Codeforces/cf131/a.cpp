// g++ -o out <filename>.cpp -D SAGAR
// .\out.exe

#define SAGAR

#include <bits/stdc++.h>
using namespace std;                                    

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x << " "; return os;}
void dbg_out() { cerr << "" << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H ; dbg_out(T...); }
#ifdef SAGAR
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define pi pair<int,int>
#define vi vector<int>
#define vpi vector<pi>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define sz(x) (int)(x).size()



class Edge {
public:
    int dist;
    int idx;
    int num;

    Edge(int dist, int num, int idx) : dist(dist), num(num), idx(idx){};

    bool operator<(const Edge& other) const {
        return dist > other.dist;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& points, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adjL(n);

        for (const vector<int>& vv : points) {
            int u = vv[0];
            int v = vv[1]; 
            int w = vv[2];
            adjL[u].push_back({v, w});
        }

        priority_queue<Edge> pq;

        pq.emplace(0, -1, src);

        while (!pq.empty()) {
            const Edge curr = pq.top();
            pq.pop();

            if (curr.num > k)
                continue;

            if (curr.idx == dst) {
                return curr.dist;
            }

            if (curr.num == k)
                continue;

            for (const auto& [u, w] : adjL[curr.idx]) {
                int next_dist = curr.dist + w;
                pq.emplace(next_dist, curr.num + 1, u);
            }
        }

        // finally return -1
        return - 1;
    }
};
 

int32_t main() {
    Solution solution;

    int n = 5;
    vector<vector<int>> points = {{0, 1, 100}, {1, 2, 200}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    int src = 0;
    int dst = 3;
    int k = 1;

    int result = solution.findCheapestPrice(n, points, src, dst, k);

    if (result != -1) {
        std::cout << "The cheapest price from " << src << " to " << dst << " with at most " << k << " stops is: " << result << std::endl;
    } else {
        std::cout << "There is no valid path from " << src << " to " << dst << " with at most " << k << " stops." << std::endl;
    }

    return 0;
}
