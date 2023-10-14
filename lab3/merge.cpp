#include <bits/stdc++.h>
using namespace std;

void merge(int array[], int left, int mid, int right)
{
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSort(int array[], int begin, int end)
{
    if (begin >= end)
        return;
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main()
{
    // // generate input
    // ofstream write("search.txt");
    // int n = 50000;
    // f0(n)
    // {
    //     int k = rand() % 500 + 1;
    //     write << k << endl;
    // }

    ifstream in("search.txt");
    int i;
    int count = 0;
    int size = 1000;
    int a[size];
    while (in >> i and count < size)
    {
        a[count] = i;
        count++;
    }
    int a_size = size;
    mergeSort(a, 0, a_size - 1);

    printArray(a, a_size);
}
