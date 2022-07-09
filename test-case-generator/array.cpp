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
    srand (time(NULL));

    int n = stoi(argv[1]), min = stoi(argv[2]), max = stoi(argv[3]);

    printf("%d\n", n);

    for(int i=0;i<n;i++){
        int next = (rand()%(max-min+1))+min;
        printf("%d ", next);
    }

    printf("\n");
}
