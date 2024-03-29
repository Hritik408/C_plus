#include <iostream>
// given BT, search k init

struct node
{
    int data;
    node *left;
    node *right;

    node(int value) : data(value), left(nullptr), right(nullptr) {}
};

node *insert(node *root, int value)
{
    if (root == nullptr)
        return new node(value);

    if (rand() % 2 == 0)
    {
        root->left = insert(root->left, value);
    }
    else{
        root->right = insert(root->right, value);
    }

    return root;

}

void inorder(node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
}

bool search(node* root, int k){
    if(root == nullptr) return false;

    if(root->data == k) return true;

    return search(root->left, k) || search(root->right, k);
}

int main()
{
   node *root = insert(nullptr, 20);
for (int value : {18, 15, 27, 12, 19, 10, 24, 30, 7, 1, 11, 29, 35, 5, 13, 33})
    insert(root, value);

    int k = 27;

  bool ans = search(root, k);

    std::cout<< std::boolalpha << ans ;

    // std::cout<< "Inorder traversal: ";
    // inorder(root);

    return 0;
}