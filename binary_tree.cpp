#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data = 0, Node *left = nullptr, Node *right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

void insertNode(Node *&root, int data)
{
    if (!root)
    {
        root = new Node(data);
        return;
    }
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node *temp = Q.front();
        Q.pop();

        if (temp->left)
        {
            Q.push(temp->left);
        }
        else
        {
            temp->left = new Node(data);
            return;
        }

        if (temp->right)
        {
            Q.push(temp->right);
        }
        else
        {
            temp->right = new Node(data);
            return;
        }
    }
}

bool searchNodeDfs(Node *root, int data)
{
    if (!root)
    {
        return false;
    }
    if (root->data == data)
    {
        return true;
    }
    return searchNodeDfs(root->left, data) || searchNodeDfs(root->right, data);
}

bool searchNodeBfs(Node *root, int data)
{
    if (!root)
    {
        return false;
    }
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node *temp = Q.front();
        Q.pop();
        if (temp->data == data)
        {
            return true;
        }
        if (temp->left)
        {
            Q.push(temp->left);
        }
        if (temp->right)
        {
            Q.push(temp->right);
        };
    }
    return false;
}

void deleteNode(Node *&root, int data)
{
}

void preOrderTraversal(Node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node *root)
{
    if (!root)
    {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    if (!root)
    {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(Node *root)
{
    if (!root)
    {
        return;
    }
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node *temp = Q.front();
        Q.pop();
        cout << temp->data << " ";
        if (temp->left)
        {
            Q.push(temp->left);
        }
        if (temp->right)
        {
            Q.push(temp->right);
        }
    }
}

int main()
{
    Node *root = nullptr;
    bool flag = true;
    while (flag)
    {
        int choice;
        char ch;
        cout << endl
             << "1. Insert 2. DFS Search 3. BFS Search 4. Delete 5. Preorder traversal 6. Inorder traversal 7. Postorder traversal 8. Level order traversal 9. Exit" << endl;
        cout
            << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int n;
            cout << "Enter value to be inserted: ";
            cin >> n;
            insertNode(root, n);
            break;
        }
        case 2:
        {
            int n;
            cout << "Enter value to be searched: ";
            cin >> n;
            if (searchNodeDfs(root, n))
            {
                cout << n << " is present in the binary tree" << endl;
            }
            else
            {
                cout << n << " is not present in the binary tree" << endl;
            }
            break;
        }
        case 3:
        {
            int n;
            cout << "Enter value to be searched: ";
            cin >> n;
            if (searchNodeBfs(root, n))
            {
                cout << n << " is present in the binary tree" << endl;
            }
            else
            {
                cout << n << " is not present in the binary tree" << endl;
            }
            break;
        }
        case 4:
        {
            int n;
            cout << "Enter value to be deleted: ";
            cin >> n;
            deleteNode(root, n);
            break;
        }

        case 5:
        {
            cout << "The preorder traversal is: ";
            preOrderTraversal(root);
            cout << endl;
            break;
        }

        case 6:
        {
            cout << "The inorder traversal is: ";
            inOrderTraversal(root);
            cout << endl;
            break;
        }

        case 7:
        {
            cout << "The postorder traversal is: ";
            postOrderTraversal(root);
            cout << endl;
            break;
        }

        case 8:
        {
            cout << "The level order traversal is: ";
            levelOrderTraversal(root);
            cout << endl;
            break;
        }

        case 9:
        {
            cout << "Exiting...";
            flag = false;
            break;
        }

        default:
        {
            cout << "Wrong choice" << endl;
            break;
        }
        }
    }
}