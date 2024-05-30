struct Node
{
    int data;
    Node *left;
    Node *right;
};

int floor(Node *root, int key)
{
    // Your code goes here
    if (root == nullptr)
        return -1;

    if (root->data == key)
        return key;
    else if (root->data > key)
    {
        return floor(root->left, key);
    }
    int floorVal = floor(root->right, key);

    return (floorVal != -1 && floorVal <= key) ? floorVal : root->data;
}