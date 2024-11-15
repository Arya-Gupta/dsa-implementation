#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int> &A)
{
    int n = A.size();
    bool swapped = false;

    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}

int main()
{
    int size;
    vector<int> A;
    cout << "Enter the size of the array to be sorted: ";
    cin >> size;
    cout << "Enter the array:" << endl;
    for (int i = 0; i < size; i++)
    {
        int n;
        cin >> n;
        A.push_back(n);
    }

    bubbleSort(A);
    cout << "The array after sorting is: ";
    for (auto i : A)
    {
        cout << i << " ";
    }
}
