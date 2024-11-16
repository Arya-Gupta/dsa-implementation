#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void selectionSort(vector<int> &A)
{
    int n = A.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            swap(A[i], A[min_idx]);
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

    selectionSort(A);
    cout << "The array after sorting is: ";
    for (auto i : A)
    {
        cout << i << " ";
    }
}
