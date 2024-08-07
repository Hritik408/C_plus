#include <iostream>
#include <climits>
#include <algorithm>
// it is range method from which we check it is bst or not

struct node{
    int data;
    node* left;
    node* right;

    node(int value) : data(value), left(nullptr), right(nullptr) {}
};


bool isBST(node* root, int l, int r){
    if(root == nullptr) return true;

    if(l <= root->data && root->data <= r){
        bool left = isBST(root->left, l, root->data - 1);
        bool right = isBST(root->right, root->data + 1, r);

        return left && right;
    }
    return false;
}


node* insert(node* root, int value){
    if(root == nullptr) return new node(value);

    if(value < root->data){
        root->left = insert(root->left, value);
    }
    else 
    root->right = insert(root->right, value);
    
    return root;
}


int main(){
    node* root = insert(nullptr, 10);

    for(int value : {5, 15, 3, 7, 14, 9, 13, 20})
    insert(root, value);
     
    bool ans = isBST(root, INT_MIN, INT_MAX);

    std::cout << std::boolalpha << ans;

    return 0;
}