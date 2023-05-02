struct Node
{
    int l, r;
    Node *left = nullptr;
    Node *right = nullptr;
    bool state;

    Node(int l, int r, bool state) : l(l), r(r), state(state) {}
};

class RangeModule
{
public:
    Node *root;

    RangeModule()
    {
        root = new Node(0, 1e9, false);
    }

    bool update(int left, int right, bool state, Node *node)
    {
        if (node->l >= left && node->r <= right)
        {
            node->state = state;
            if (node->left != nullptr)
                delete node->left;
            if (node->right != nullptr)
                delete node->right;

            node->left = nullptr;
            node->right = nullptr;
            return state;
        }

        if (node->l >= right || node->r <= left)
            return node->state;

        int mid = (node->r - node->l) / 2 + node->l;
        if (node->left == nullptr)
        {
            node->left = new Node(node->l, mid, node->state);
            node->right = new Node(mid, node->r, node->state);
        }
        bool leftState = update(left, right, state, node->left);
        bool rightState = update(left, right, state, node->right);
        node->state = leftState & rightState;
        return node->state;
    }

    bool query(int left, int right, Node *node)
    {
        if ((node->l >= left && node->r <= right) || node->left == nullptr)
            return node->state;

        int mid = (node->r - node->l) / 2 + node->l;

        if (right <= mid)
        {
            return query(left, right, node->left);
        }
        else if (left >= mid)
        {
            return query(left, right, node->right);
        }
        else
        {
            return query(left, right, node->left) & query(left, right, node->right);
        }
    }

    void addRange(int left, int right)
    {
        update(left, right, true, root);
    }

    bool queryRange(int left, int right)
    {
        return query(left, right, root);
    }

    void removeRange(int left, int right)
    {
        update(left, right, false, root);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */