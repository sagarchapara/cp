#include<bits/stdc++.h>
using namespace std;

// generate random numbers in between l an r
int ran(int l, int r)
{
    return l + (rand() % (r - l + 1));
}
 
// Prints edges of tree
// represented by give Prufer code
void printTreeEdges(vector<int> prufer, int m, bool hasWeight, int maxWeight)
{
    int vertices = m + 2;

    cout << vertices << endl;

    vector<int> vertex_set(vertices);
 
    // Initialize the array of vertices
    for (int i = 0; i < vertices; i++)
        vertex_set[i] = 0;
 
    // Number of occurrences of vertex in code
    for (int i = 0; i < vertices - 2; i++)
        vertex_set[prufer[i] - 1] += 1;
  
    int j = 0;
 
    // Find the smallest label not present in
    // prufer[].
    for (int i = 0; i < vertices - 2; i++)
    {
        for (j = 0; j < vertices; j++)
        {
 
            // If j+1 is not present in prufer set
            if (vertex_set[j] == 0)
            {
 
                // Remove from Prufer set and print
                // pair.
                vertex_set[j] = -1;
                // cout << (j + 1) << " "
                //                 << prufer[i] << endl;

                printf("%d %d ", j+1, prufer[i]);
                if(hasWeight){
                    printf("%d", ran(0, maxWeight));
                }
                printf("\n");

                vertex_set[prufer[i] - 1]--;
 
                break;
            }
        }
    }
 
    j = 0;
 
    // For the last element
    for (int i = 0; i < vertices; i++)
    {
        if (vertex_set[i] == 0 && j == 0)
        {
            printf("%d ", i+1);
            j++;
        }
        else if (vertex_set[i] == 0 && j == 1){
            printf("%d ", i+1);
            if(hasWeight){
                printf("%d", ran(0, maxWeight));
            }
            printf("\n");
        }
            
    }
}
  
// Function to Generate Random Tree
void generateRandomTree(const int n, const bool hasWeight = false, const int maxWeight = 0)
{
 
    int length = n - 2;
    vector<int> arr(length);
 
    // Loop to Generate Random Array
    for (int i = 0; i < length; i++)
    {
        arr[i] = ran(0, length + 1) + 1;
    }
    printTreeEdges(arr, length, hasWeight, maxWeight);
}
 
/**
 * @brief 
 * 
 * @param argc 
 * @param argv[1] n number of nodes
 * @param argv[2] weigth maxWeight of edges 
 * @return int 
 */
int main(int argc, char **argv)
{
    srand(time(0));

    int n = stoi(argv[1]); int maxWeight = 0; bool hasWeight = false;

    if(argc>=3){
        maxWeight = stoi(argv[2]);
        hasWeight = true;
    }

    generateRandomTree(n, hasWeight, maxWeight);
 
    return 0;
}