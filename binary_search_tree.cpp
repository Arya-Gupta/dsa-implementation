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

bool searchNodeDfs(Node *root, int data)
{
}

bool searchNodeBfs(Node *root, int data)
{
}

void deleteNode(Node *&root, int data)
{
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
             << "1. Insert 2. DFS Search 3. BFS Search 4. Delete 5. Exit" << endl;
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