#include <bits/stdc++.h>
using namespace std;

//find inversions and cycles
int find_inversions(vector<int>& arr){
    int ans = find_inversions_internal(arr,0, arr.size()-1);
}

int find_inversions_internal(vector<int>& arr, int l, int r){
    if(l == r){
        return 0;
    }

    int mid = (l + r)/2;

    int invL = find_inversions_internal(arr, l, mid);
    int invR = find_inversions_internal(arr, mid+1, r);

    int invM = merge_sorted_arrays(arr, l, mid, r);
    return invL+ invR + invM;
}

int merge_sorted_arrays(vector<int>& arr, int l, int mid, int r){
    //handle for zero arrays
    if(l == mid || r == mid + 1){
        return 0;
    }

    vector<int> merge_sorted_array (r-l+1);

    int invCnt =0;

    int p = l;
    int q = mid+1;

    for(int i=0;i<=r-l;i++){
        merge_sorted_array[i] = min(arr[p], arr[q]);
        if(arr[p] > arr[q]){
            invCnt += (q-(mid+1)+1);
            q++;
        }
        else{
            p++;
        }
    }

    //finally copy this into final array
    for(int i=l;i<r;i++){
        arr[i] = merge_sorted_array[i+l];
    }

    return invCnt;
}

int find_min_swaps(vector<int>& arr){
    int n = arr.size();
    vector<pair<int, int>> pairs;

    for(int i=0;i<n;i++){
        pairs.push_back(make_pair(arr[i], i));
    }

    int ans =0;
    vector<bool> visisted(n, false);

    for(int i=0;i<n;i++){
        if(visisted[i]) continue;

        int cnt =0;
        int curr = i;
        while(curr != i){
            curr = pairs[curr].second;
            cnt++;
        }
        ans+=cnt;
    }

    return ans;
}
