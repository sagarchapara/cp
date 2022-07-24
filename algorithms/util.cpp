#include <bits/stdc++.h>
using namespace std;

//Transforms array into unique elements from 0 to n-1
int unique_transform(int n, vector<int>& arr){
    set<int> s(arr.begin(), arr.end());
    int i =0; map<int,int> m;
    for(int k: s) m.insert({k,i++});
    for(int i=0;i<n;i++) arr[i] = m[arr[i]];
    return s.size();
}