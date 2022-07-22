#include <bits/stdc++.h>
using namespace std;   

/**
 * @brief 
 * 
 * @param argc 
 * @param argv[1] length of the array
 * @param argv[1] min_value
 * @param argv[2] max_value
 * @return int 
 */

int main(int argc, char **argv){
    
    mt19937 mt(time(nullptr)); 


    int n = stoi(argv[1]), min = stoi(argv[2]), max = stoi(argv[3]);

    int k = (mt()%(max - min+1))+min;

    printf("%d %d\n", n, k);

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        arr[i] = (mt()%(max-min+1))+min;
    }

    sort(arr.begin(), arr.end());

    for(int i: arr){
        printf("%d ", i);
    }

    printf("\n");
}
