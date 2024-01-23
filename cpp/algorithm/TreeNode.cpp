#include <iostream>

class TreeNode
{
public:
    int value;
    TreeNode* leftNode;
    TreeNode* rightNode;
    TreeNode (int value) : value(value), leftNode(nullptr), rightNode(nullptr) {} 
};

void perOrderTraversal(TreeNode* root)
{
    if (root == nullptr) return;
    std::cout << root->value << std::endl;
    perOrderTraversal(root->leftNode);
    perOrderTraversal(root->rightNode);
}

void postOrderTraversal(TreeNode* root)
{
    if (root == nullptr) return;
    postOrderTraversal(root->leftNode);
    postOrderTraversal(root->rightNode);
    std::cout << root->value << std::endl;
}

void inOrderTraversal(TreeNode* root)
{
    if (root == nullptr) return;
    inOrderTraversal(root->leftNode);
    std::cout << root->value << std::endl;
    inOrderTraversal(root->rightNode);
}

TreeNode* createNode(int value)
{
    if (value == -1)
    {
        return nullptr;
    }

    TreeNode* root = new TreeNode(value);
    return root;
}

void deleteNode(TreeNode* root)
{
    if (root == nullptr) return;
    deleteNode(root->leftNode);
    deleteNode(root->rightNode);
    delete root;
}

int main()
{
    TreeNode* root = createNode(5);
    std::cout << "root->value = " << root->value << std::endl;

    deleteNode(root);
    return 0;
}