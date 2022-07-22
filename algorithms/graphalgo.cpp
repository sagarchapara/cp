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


//LCA with Binary Lifting
class LCA{
    int n, l, timer, root;
    vector<vector<int>> adj;

    vector<int> tin, tout;
    vector<vector<int>> up;

    void dfs(int v, int p)
    {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i-1]][i-1];

        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v);
        }

        tout[v] = ++timer;
    }

    bool is_ancestor(int u, int v)
    {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

public:

    int lca(int u, int v)
    {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }

    LCA (int _n, vector<vector<int>>& _adj, int _root = 0): n(_n), adj(_adj), root(_root){
        tin.resize(n), tout.resize(n);
        timer = 0, l = ceil(log2(n));
        up.assign(n, vector<int>(l + 1));
        dfs(root, root);
    }   
};