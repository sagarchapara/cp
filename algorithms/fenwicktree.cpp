#include <bits/stdc++.h>
using namespace std;

class FenwickTree
{
public:
    int n;
    vector<int> tree;

    FenwickTree(int _n): n(_n){ tree.resize(n, 0); };

    FenwickTree(int _n, vector<int>& arr) : n(_n)
    {
        tree.assign(n,0);

        for(int i=0;i<n;i++)
        {
            tree[i]+=arr[i];

            int next = i | (i+1);

            if(next<n) tree[next]+=tree[i];
        }
    }

    void update(int idx, int delta)
    {
        for(;idx<n;idx = idx|(idx+1))
        {
            tree[idx] +=delta;
        }
    }

    int get(int idx)
    {
        int ans =0;
        for(;idx>=0;idx = (idx&(idx+1))-1)
        {
            ans+=tree[idx];
        }
    }

    int get(int l, int r)
    {
        return get(r) - get(l-1);
    }
};