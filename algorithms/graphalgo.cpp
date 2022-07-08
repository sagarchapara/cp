#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(x) (x).begin(), (x).end()

/**
===============================================================
    Strongly connected components
================================================================
**/

vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component;

void dfs1(int v, vector<vector<int>>& adj, vector<bool>& used, vector<int>& order) {
    used[v] = true;
    for (int u : adj[v]){
        if (!used[u]){
            dfs1(u, adj, used, order);
        }
    }    
    order.push_back(v);
}

void dfs2(int v, vector<vector<int>>& adj_rev, vector<bool>& used, vector<int>& component){
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v]){
        if (!used[u]){
            dfs2(u, adj_rev, used, component);
        }
    }     
}

// int main() {
//     int n;
//     // ... read n ...
//      
//     adj.resize(n); adj_rev.resize(n);   
//
//     for (;;) {
//         int a, b;
//         // ... read next directed edge (a,b) ...
//         adj[a].push_back(b);
//         adj_rev[b].push_back(a);
//     }

//     used.assign(n, false);

//     for (int i = 0; i < n; i++)
//         if (!used[i])
//             dfs1(i);

//     used.assign(n, false);
//     reverse(order.begin(), order.end());

//     for (auto v : order)
//         if (!used[v]) {
//             dfs2 (v);

//             // ... processing next component ...

//             component.clear();
//         }
// }


/**
===============================================================
    Floyd Warshall (shortest distance between all vertices)
================================================================
**/

// for (int k = 0; k < n; ++k) {
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             if (d[i][k] < INF && d[k][j] < INF)
//                 d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
//         }
//     }
// }

//DSU
class DSU {
    vi parent;
    int n;

    public:
        DSU (int _n): n(_n){
            parent.resize(n);
            iota(all(parent), 0ll);
        }

        ~DSU(){
            parent.clear();
        }

        int find_set(int v) {
            if (v == parent[v])
                return v;
            return parent[v] = find_set(parent[v]);
        }

        bool check(int u, int v){
            return find_set(u) != find_set(v);
        }

        void union_sets(int a, int b) {
            a = find_set(a);
            b = find_set(b);
            if (a != b)
                parent[b] = a;
        }
};