struct Node
{
    int data;
    Node *left;
    Node *right;
};

int findCeil(Node *root, int input)
{
    // Your code here
    if (root == nullptr)
        return -1;

    if (root->data == input)
        return input;
    else if (root->data < input)
        return findCeil(root->right, input);

    int ceilVal = findCeil(root->left, input);
    return (ceilVal != -1 && ceilVal >= input) ? ceilVal : root->data;
}