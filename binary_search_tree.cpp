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

Node *insertNode(Node *root, int data)
{
    if (!root)
    {
        return new Node(data);
    }
    if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    else if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    return root;
}

bool search(Node *root, int data)
{
    if (!root)
    {
        return false;
    }
    if (root->data == data)
    {
        return true;
    }
    return (data > root->data) ? search(root->right, data) : search(root->left, data);
}

void deleteNode(Node *&root, int data)
{
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

int main()
{
    Node *root = nullptr;
    bool flag = true;
    while (flag)
    {
        int choice;
        char ch;
        cout << endl
             << "1. Insert 2. Search 3. Delete 4. Print (Inorder traversal) 5. Exit" << endl;
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
            root = insertNode(root, n);
            break;
        }
        case 2:
        {
            int n;
            cout << "Enter value to be searched: ";
            cin >> n;
            if (search(root, n))
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
            cout << "Enter value to be deleted: ";
            cin >> n;
            deleteNode(root, n);
            break;
        }

        case 4:
        {
            cout << "The inorder traversal is: ";
            inOrderTraversal(root);
            cout << endl;
            break;
        }

        case 5:
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