#include <bits/stdc++.h>
using namespace std;

//build v= 1 tl=0 tr=n-1

class SegmentTree{

    int n;
    vector<int> t;

    inline void build(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }

    inline int query(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return query(v*2, tl, tm, l, min(r, tm))
            + query(v*2+1, tm+1, tr, max(l, tm+1), r);
    }

    inline void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            t[v] = t[v*2] + t[v*2+1];
        }
    }

public:

    SegmentTree(int _n, vector<int>& arr): n(_n){
        t.resize(4*n);
        build(arr, 1, 0, n-1);
    }

    inline int query(int l, int r){
        return query(1, 0, n-1, l, r);
    }

    inline void update(int p, int val){
        update(1,0,n-1,p,val);
    }
};

//Fenwick tree can also be used to range updates and range queries
class FenwickTree{
    int n;
    vector<int> bit;
    
    inline int query(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1){
            ret += bit[r];
        }  
        return ret;
    }

public:

    FenwickTree(int _n, vector<int>& arr): n(_n){
        bit.resize(n,0);
        for(int i=0;i<n;i++){
            update(i, arr[i]);
        }
    }

    FenwickTree(int _n): n(_n){
        bit.resize(n,0);
    }

    inline void update(int idx, int delta){
        for(; idx<n ; idx = (idx | (idx+1))){
            bit[idx]+=delta;
        }
    }

    inline int query(int l, int r){
        return query(r) - query(l-1);
    }
};