#include <bits/stdc++.h>
using namespace std;


class BinomialCoefficient{
    int n, p;
    vector<int> fact, invf;

    inline int power(int a, int b){
        int res = 1;
        a %= p;
        while (b > 0) 
        {
            if (b & 1)
                res = (res * a) % p;
            a = (a * a) % p;
            b >>= 1;
        }
        return res;
    }

    inline int modinv(int k){
        return power(k, p-2);
    }

    inline void compute(){
        fact[0] = 1;
        for(int i=1;i<n;i++) fact[i] = (i*fact[i-1])%p;

        invf[n-1] = modinv(fact[n-1]);
        for(int i=n-2;i>=0;i--){
            invf[i] = (i+1)*(invf[i+1]);
            invf[i]%=p;
        }   
    }

public:

    BinomialCoefficient(int _n, int _p): n(_n), p(_p){
        fact.resize(n), invf.resize(n);
        compute();
    }

    inline int ncr(int l, int r){

        if (l < r || r < 0 || l < 0) return 0;

        int ans = (((fact[l]*invf[r])%p)*invf[l-r])%p;
        return ans;
    } 
};
