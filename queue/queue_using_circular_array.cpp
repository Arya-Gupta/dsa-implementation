#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define max_size 20
vector<int> q(max_size);
int front = -1, rear = -1;

bool isFull()
{
    return ((rear + 1) % max_size == front);
}

bool isEmpty()
{
    return (front == -1 && rear == -1);
}

void giveFront()
{
    if (front == -1)
        cout << "Error: The queue is empty" << endl;
    else
        cout << q[front];
}

void enqueue(int n)
{
    if (isEmpty())
    {
        front = rear = 0;
    }

    else if (isFull())
    {
        cout << "Error: The queue is full" << endl;
        return;
    }
    else
    {
        rear = (rear + 1) % max_size;
    }
    q[rear] = n;
}

void dequeue()
{
    if (isEmpty())
        cout << "Error: The queue is empty" << endl;
    else if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % max_size;
}

void print()
{
    cout << "The queue is: ";
    if (isEmpty())
    {
        cout << "empty" << endl;
        return;
    }
    int no_of_elements = (rear + max_size - front) % max_size + 1;
    for (int i = 0; i < no_of_elements; i++)
    {
        int index = (front + i) % max_size;
        cout << q[index] << " ";
    }
}

int main()
{
    bool flag = true;
    while (flag)
    {
        int choice;
        cout << endl
             << "1. Enqueue 2. Dequeue 3. Front 4. Is the queue full 5. Is the queue empty 6. Print 7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int n;
            cout << "Enter the element: ";
            cin >> n;
            enqueue(n);
            break;
        }
        case 2:
        {
            dequeue();
            break;
        }

        case 3:
        {
            giveFront();
            break;
        }

        case 4:
        {
            if (isFull())
                cout << "The queue is full" << endl;
            else
                cout << "The queue is not full" << endl;
            break;
        }

        case 5:
        {
            if (isEmpty())
                cout << "The queue is empty" << endl;
            else
                cout << "The queue is not empty" << endl;
            break;
        }

        case 6:
        {
            print();
            break;
        }

        case 7:
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