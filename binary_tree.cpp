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

void insert(Node *&root, int data)
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
             << "1. Insert 2. Delete 3. Preorder traversal 4. Inorder traversal 5. Postorder traversal 6. Level order traversal 7. BFS 8. DFS 9. Exit" << endl;
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
            insert(root, n);
            break;
        }
        case 2:
        {
            break;
        }

        case 3:
        {
            cout << "The preorder traversal is: ";
            preOrderTraversal(root);
            break;
        }

        case 4:
        {
            cout << "The inorder traversal is: ";
            inOrderTraversal(root);
            break;
        }

        case 5:
        {
            cout << "The postorder traversal is: ";
            postOrderTraversal(root);
            break;
        }

        case 6:
        {
            cout << "The level order traversal is: ";
            levelOrderTraversal(root);
            break;
        }

        case 7:
        {
            break;
        }

        case 8:
        {
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