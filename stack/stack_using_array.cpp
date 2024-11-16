#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define max_size 100
vector<int> st(max_size);
int top = -1;

void push(int n)
{
    if (top == max_size - 1)
    {
        cout << "Error: stack overflow";
        return;
    }
    st[++top] = n;
}

bool isEmpty()
{
    return top == -1;
}

int pop()
{
    if (isEmpty())
        return -1;
    return st[top--];
}

void printTop()
{
    if (top == -1)
        cout << "Error: stack is empty";
    else
        cout << "The element at the top is: " << st[top];
}

void print()
{
    if (isEmpty())
    {
        cout << "empty";
    }
    else
    {
        for (int i = 0; i <= top; i++)
            cout << st[i] << " ";
    }
}

int main()
{
    bool flag = true;
    while (flag)
    {
        int choice;
        cout << endl
             << "1. Push 2. Pop 3. Top 4. Is the stack empty 5. Print 6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int n;
            cout << "Enter the element to be pushed: ";
            cin >> n;
            push(n);
            cout << n << " has been pushed into the stack";
            break;
        }
        case 2:
        {
            int n = pop();
            if (n == -1)
                cout << "Error: stack underflow";
            else
                cout << n << " has been popped from the stack";
            break;
        }

        case 3:
        {
            printTop();
            break;
        }

        case 4:
        {
            cout << (isEmpty() ? "The stack is empty" : "The stack is not empty");
            break;
        }

        case 5:
        {
            cout << "The stack is: ";
            print();
            break;
        }

        case 6:
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