#include <bits/stdc++.h>
using namespace std;

class Sieve{
    int n;

    void compute(int n, vector<bool>& isPrime, vector<int>& lpf){
        fill(isPrime.begin(), isPrime.end(), true);
        iota(lpf.begin(), lpf.end(), 0);

        isPrime[0] = isPrime[1] = false;

        for(int i=4;i<n;i+=2) {
            isPrime[i] = false;
            lpf[i] = 2;
        }

        for(int i=3;i<n;i+=2){
            if(isPrime[i]){
                for(int j= i*i;j<n;j+=i){
                    if(isPrime[j]){
                        isPrime[j] = false;
                        lpf[j] = i;
                    }
                }
            }
        }
    }
};