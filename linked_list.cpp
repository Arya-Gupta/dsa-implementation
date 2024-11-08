#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data = 0, Node *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

void handleInsert(char, int, Node *&);
void handleDelete(char, Node *&);
void handleReverse(char, Node *&);
void handlePrint(char, Node *);

void insertAtHead(int data, Node *&head)
{
    if (!head)
    {
        head = new Node{data};
    }
    else
    {
        Node *newNode = new Node{data, head};
        head = newNode;
    }
}

void insertAtTail(int data, Node *&head)
{
    if (!head)
    {
        insertAtHead(data, head);
    }
    else
    {
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        Node *newNode = new Node{data};
        temp->next = newNode;
    }
}

void insertAtKth(int data, Node *&head, int K)
{
    if (!head && K > 1)
    {
        cout << "Error: K has invalid value" << endl;
        return;
    }
    else if (K <= 0)
    {
        cout << "Error: K has invalid value" << endl;
        return;
    }
    else if (K == 1)
    {
        insertAtHead(data, head);
        return;
    }

    int len = 0;
    Node *temp = head;
    while (temp)
    {
        len++;
        temp = temp->next;
    }

    if (K == len + 1)
    {
        insertAtTail(data, head);
        return;
    }
    else if (K > len + 1)
    {
        cout << "Error: K has invalid value" << endl;
        return;
    }

    temp = head;
    for (int i = 1; i < K - 1; i++)
    {
        temp = temp->next;
    }
    Node *newNode = new Node{data};
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertBeforeValue(int data, Node *&head, int x)
{
    if (!head)
    {
        cout << "Error: The linked list is empty" << endl;
        return;
    }
    else if (head->data == x)
    {
        insertAtHead(data, head);
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        if (temp->next->data == x)
        {
            Node *newNode = new Node{data, temp->next};
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    }
    cout << "Error: The value " << x << " is not present in the linked list" << endl;
}

void deleteHead(Node *&head)
{
    if (!head)
    {
        cout << "Error: The linked list is empty" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}

void deleteTail(Node *&head)
{
    if (!head)
    {
        cout << "Error: The linked list is empty" << endl;
        return;
    }
    else if (!head->next)
    {
        deleteHead(head);
        return;
    }

    Node *temp = head;
    while (temp->next->next)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void deleteAtKth(Node *&head, int K)
{
    if (!head || K < 1)
    {
        cout << "Error: K has invalid value" << endl;
        return;
    }
    else if (K == 1)
    {
        deleteHead(head);
        return;
    }

    int count = 0;
    Node *prev = nullptr, *curr = head;
    while (curr && count < K - 1)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }

    if (!curr)
    {
        cout << "Error: K has invalid value" << endl;
        return;
    }
    prev->next = curr->next;
    delete curr;
}

void deleteAtValue(Node *&head, int x)
{
    if (!head)
    {
        cout << "Error: The linked list is empty" << endl;
        return;
    }
    else if (head->data == x)
    {
        deleteHead(head);
        return;
    }

    Node *prev = nullptr, *curr = head;
    while (curr)
    {
        if (curr->data == x)
        {
            prev->next = curr->next;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    cout << "Error: The value " << x << " is not present in the linked list" << endl;
}

void iterativeReverse(Node *&head)
{
    Node *prev = nullptr, *curr = head, *next = nullptr;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void recursiveReverse(Node *&head)
{
}

void printForward(Node *temp)
{
    if (!temp)
    {
        cout << "Error: The linked list is empty" << endl;
        return;
    }
    cout << "The linked list is: ";
    while (temp->next)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

void printReverse(Node *&head)
{
    if (!head)
        return;
    printReverse(head->next);
    cout << head->data << "->";
}

int main()
{
    Node *head = nullptr;
    bool flag = true;
    while (flag)
    {
        int choice;
        char ch;
        cout << endl
             << "1. Insert 2. Delete 3. Reverse 4. Print 5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int n;
            cout
                << "a. Insert at head b. Insert at tail c. Insert at Kth position d. Insert before value x" << endl;
            cout << "Enter your choice: ";
            cin >> ch;
            cout << "Enter value to be inserted: ";
            cin >> n;
            handleInsert(ch, n, head);

            break;
        }
        case 2:
        {
            cout
                << "a. Delete head b. Delete tail c. Delete node at Kth position d. Delete node with value x" << endl;
            cout << "Enter your choice: ";
            cin >> ch;
            handleDelete(ch, head);
            break;
        }

        case 3:
        {
            cout
                << "a. Reverse iteratively b. Reverse recursively" << endl;
            cout << "Enter your choice: ";
            cin >> ch;
            handleReverse(ch, head);
            break;
        }

        case 4:
        {
            cout
                << "a. Print in forward order b. Print in reverse order" << endl;
            cout << "Enter your choice: ";
            cin >> ch;
            handlePrint(ch, head);
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
            cout << "Wrong choice";
            break;
        }
        }
    }
}

void handleInsert(char ch, int n, Node *&head)
{
    switch (ch)
    {
    case 'a':
    {
        insertAtHead(n, head);
        break;
    }
    case 'b':
    {
        insertAtTail(n, head);
        break;
    }
    case 'c':
    {
        int K;
        cout << "The value of K is: ";
        cin >> K;
        insertAtKth(n, head, K);
        break;
    }
    case 'd':
    {
        int x;
        cout << "The value of x is: ";
        cin >> x;
        insertBeforeValue(n, head, x);
        break;
    }
    default:
    {
        cout << "Wrong choice" << endl;
        break;
    }
    }
}

void handleDelete(char ch, Node *&head)
{
    switch (ch)
    {
    case 'a':
    {
        deleteHead(head);
        break;
    }
    case 'b':
    {
        deleteTail(head);
        break;
    }
    case 'c':
    {
        int K;
        cout << "The value of K is: ";
        cin >> K;
        deleteAtKth(head, K);
        break;
    }
    case 'd':
    {
        int x;
        cout << "The value of x is: ";
        cin >> x;
        deleteAtValue(head, x);
        break;
    }
    default:
    {
        cout << "Wrong choice" << endl;
        break;
    }
    }
}

void handleReverse(char ch, Node *&head)
{
    switch (ch)
    {
    case 'a':
    {
        iterativeReverse(head);
        break;
    }
    case 'b':
    {
        recursiveReverse(head);
        break;
    }
    default:
    {
        cout << "Wrong choice" << endl;
        break;
    }
    }
}

void handlePrint(char ch, Node *head)
{
    switch (ch)
    {
    case 'a':
    {
        printForward(head);
        break;
    }
    case 'b':
    {
        printReverse(head);
        break;
    }
    default:
    {
        cout << "Wrong choice" << endl;
        break;
    }
    }
}