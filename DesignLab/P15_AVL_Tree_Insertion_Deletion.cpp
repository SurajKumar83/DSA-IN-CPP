
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    int height;
    Node(int nodeval)
    {
        val = nodeval;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class AVL
{

public:
    int height(Node *N)
    {
        if (N == NULL)
            return 0;
        return N->height;
    }

    Node *rightRotate(Node *c)
    {
        Node *Y = c->left;
        Node *YR = Y->right;

        // Perform rotation
        Y->right = c;
        c->left = YR;

        // Update height
        c->height = max(height(c->left), height(c->right)) + 1;
        Y->height = max(height(Y->left), height(Y->right)) + 1;

        return Y;
    }

    Node *leftRotate(Node *c)
    {
        Node *Y = c->right;
        Node *YL = Y->left;

        // Perform rotation
        Y->left = c;
        c->right = YL;

        // Update height
        c->height = max(height(c->left), height(c->right)) + 1;
        Y->height = max(height(Y->left), height(Y->right)) + 1;

        return Y;
    }

    int BalanceFactor(Node *N)
    {
        if (N == NULL)
            return 0;
        return height(N->left) - height(N->right);
    }

    Node *insert(Node *node, int val)
    {

        if (node == NULL)
            return new Node(val);

        if (val < node->val)
            node->left = insert(node->left, val);

        else if (val > node->val)
            node->right = insert(node->right, val);

        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = BalanceFactor(node);

        // Left Left Case
        if (balance > 1 && val < node->left->val)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && val > node->right->val)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && val > node->left->val)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && val < node->right->val)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node *successor(Node *node)
    {
        Node *current = node;

        while (current->left != NULL)
            current = current->left;

        return current;
    }

    Node *deleteNode(Node *root, int val)
    {

        if (root == NULL)
            return root;

        if (val < root->val)
            root->left = deleteNode(root->left, val);

        else if (val > root->val)
            root->right = deleteNode(root->right, val);

        else
        {
            // only one child or no child
            if ((root->left == NULL) || (root->right == NULL))
            {
                Node *temp = root->left ? root->left : root->right;
                // No child case
                if (temp == NULL)
                {
                    temp = root;
                    root = NULL;
                }
                else // One child case
                    *root = *temp;
                free(temp);
            }
            else
            {
                Node *temp = successor(root->right);

                root->val = temp->val;

                root->right = deleteNode(root->right, temp->val);
            }
        }

        if (root == NULL)
            return root;

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = BalanceFactor(root);

        // Left Left Case
        if (balance > 1 && BalanceFactor(root->left) >= 0)
            return rightRotate(root);

        // Left Right Case
        if (balance > 1 && BalanceFactor(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && BalanceFactor(root->right) <= 0)
            return leftRotate(root);

        // Right Left Case
        if (balance < -1 && BalanceFactor(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void Postorder(Node *root)
    {
        if (root != NULL)
        {
            Postorder(root->left);
            Postorder(root->right);
            cout << root->val << " ";
        }
    }
};

int main()
{
    AVL obj;
    Node *root = NULL;
    int n;
    cout << "Enter the Number of nodes ";
    cin >> n;
    cout << endl;
    cout << "Insert the nodes: " << endl;
    int nodeval;
    for (int i = 0; i < n; i++)
    {
        cin >> nodeval;
        root = obj.insert(root, nodeval);
    }

    cout << "Postorder traversal of the constructed AVL tree is" << endl;
    obj.Postorder(root);
    cout << endl;

    cout << "Do you Want to delete any Node: 1/0" << endl;

    bool flag;
    cin >> flag;

    if (flag)
    {
        int nodeval;
        cout << "Enter the node value: ";
        cin >> nodeval;

        obj.deleteNode(root, nodeval);
        cout << "Your Postorder Traversal After deleting the node: " << nodeval << endl;
        obj.Postorder(root);
    }

    else
        cout << "Thank You" << endl;

    return 0;
}
