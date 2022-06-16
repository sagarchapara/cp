#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Returns index of the next greater element
 * If there is no nge returns n
 * @param v input vector
 * @return vector<int> 
 */
vector<int> nextGreaterElem(vector<int>& v){
    stack<int> s;

    int n = v.size();

    vector<int> ans(n, n);
    s.push(0);

    for(int i=1;i<n;i++){
        while(!s.empty() && v[i] > v[s.top()]){
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    return ans;
}

/**
 * @brief Returns index of the next greater element
 * If there is no pge returns -1
 * @param v input vector
 * @return vector<int> 
 */
vector<int> prevGreaterElem(vector<int>& v){
    stack<int> s;

    int n = v.size();

    vector<int> ans(n, -1);
    s.push(n-1);

    for(int i= n-1;i>=0;i--){
        while(!s.empty() && v[i] > v[s.top()]){
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    return ans;
}