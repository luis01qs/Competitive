#include <iostream>
#include <algorithm>

class AVL
{
private:
    class Node
    {
    public:
        int data;
        Node *left;
        Node *right;
        int height;

        Node(int x)
        {
            data = x;
            left = nullptr;
            right = nullptr;
            height = 1;
        }
    };

    Node *root;

    int height(Node *node)
    {
        return node ? node->height : 0;
    }

    int getBalance(Node *node)
    {
        return node ? height(node->left) - height(node->right) : 0;
    }

    void rotateright(Node *&y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = 1 + std::max(height(y->left), height(y->right));
        x->height = 1 + std::max(height(x->left), height(x->right));

        // Update root of this subtree
        y = x;
    }

    void rotateleft(Node *&y)
    {
        Node *x = y->right;
        Node *T2 = x->left;

        // Perform rotation
        x->left = y;
        y->right = T2;

        // Update heights
        y->height = 1 + std::max(height(y->left), height(y->right));
        x->height = 1 + std::max(height(x->left), height(x->right));

        // Update root of this subtree
        y = x;
    }

    void insert(Node *&node, int val)
    {
        if (node == nullptr)
        {
            node = new Node(val);
            return;
        }

        if (val < node->data)
            insert(node->left, val);
        else if (val > node->data)
            insert(node->right, val);
        else
            return;

        node->height = 1 + std::max(height(node->left), height(node->right));
        int b = getBalance(node);

        // Balancing cases
        if (b > 1 && val < node->left->data)
            rotateright(node);
        else if (b < -1 && val > node->right->data)
            rotateleft(node);
        else if (b > 1 && val > node->left->data)
        {
            rotateleft(node->left);
            rotateright(node);
        }
        else if (b < -1 && val < node->right->data)
        {
            rotateright(node->right);
            rotateleft(node);
        }
    }

    void inorder(Node *node)
    {
        if (!node)
            return;
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }

public:
    AVL() { root = nullptr; }

    void insert(int x)
    {
        insert(root, x);
    }

    void print()
    {
        inorder(root);
        std::cout << std::endl;
    }
};

int main()
{
    AVL t;
    t.insert(30);
    t.insert(20);
    t.insert(10);
    t.insert(25);
    t.insert(40);
    t.insert(50);
    t.insert(35);

    t.print();
}
