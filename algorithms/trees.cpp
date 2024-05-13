#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data): data(data){}
};



/// @brief Finds the InOrder or PreOrder in O(1) space
/// @param root 
/// @return 
vector<int> MorrisTraversal(Node* root)
{
    vector<int> inOrder;

    Node* curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            inOrder.push_back(root->data);
            curr = curr-> right;
        }
        else{
            //find the right most of the left subtree
            Node* prev = curr->left;

            while(prev->right != NULL && prev->right !=curr){
                prev = prev->right;
            }

            if(prev->right == curr){
                //already visited left of curr, so go right
                inOrder.push_back(root->data);
                prev->right = NULL;
                curr = curr->right;
            }
            else{
                prev->right = curr;
                curr = curr->left;
            }
        }
    }
}