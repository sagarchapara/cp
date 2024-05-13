#include <bits/stdc++.h>
using namespace std;

class FindCyclesInDAG{
public:
    int n;
    vector<vector<int>> adj;
    vector<int> color;

    bool dfs(int curr, int par){
        color[curr] = 1;

        for(int next: adj[curr]){
            if(next != par){
                if(color[next] == 0){
                    if(dfs(next, curr)) return true;
                }
                else if(color[next] == 1){
                    return true;
                }
            }
        }
        color[curr] = 2;
        return false;
    }

    bool hasCycle(int n, vector<vector<int>>& adj){
        vector<int> color(n, 0);

        for(int i=0;i<n;i++){
            if(color[0] == 0){
                if(dfs(i, -1)) return true;
            }
        }
    }
};

class DSU {
public:
    int n;
    vector<int> parent;
    vector<int> size;

    DSU(int _n) : n(_n) {
        parent.resize(n);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0ll);
    }

    int find_set(int k) {
        if (parent[k] == k) {
            return k;
        }
        return parent[k] = find_set(parent[k]);
    }

    void merge(int a, int b) {
        a = find_set(a);
        b = find_set(b);

        if (a != b) {
            if (size[a] < size[b]) {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }

    int find_size(int a) { return size[find_set(a)]; }
};


class LCA{
private:
    int n, l;
    vector<vector<int>> adj;

    int timer;
    vector<int> tin, tout;
    vector<vector<int>> up;

    LCA(int _n, vector<vector<int>>& _adj) : n(_n), adj(_adj)
    {
        tin.resize(n);
        tout.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.assign(n, vector<int>(l + 1));
        dfs(0, 0);
    }
    
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
};