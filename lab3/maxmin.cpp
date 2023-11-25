// In the name of Allah the most beneficent the most merciful - sūrat l-naml(27:30)
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f0(n) for (int i = 0; i < n; i++)
#define fast()                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
    }
int maxx, minn;
int max_min_normal(int arr[], int size)
{
    maxx = minn = arr[0];
    int comp = 0;

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxx)
        {
            maxx = arr[i];
            comp++;
        }
        else if (arr[i] < minn)
        {
            minn = arr[i];
            comp++;
        }
    }
    return comp;
}

int MaxMin(int i, int j, int arr[], int &max, int &min)
{
    int comp = 0;
    if (i == j)
    {
        max = min = arr[i];
        comp++;
    }
    else if (i == j - 1)
    {
        if (arr[i] < arr[j])
        {
            max = arr[j];
            min = arr[i];
            comp++;
        }
        else
        {
            max = arr[i];
            min = arr[j];
            comp++;
        }
    }
    else
    {
        int mid = (i + j) / 2;
        int max1, min1;
        int comp1 = MaxMin(i, mid, arr, max, min);
        int comp2 = MaxMin(mid + 1, j, arr, max1, min1);

        comp += (comp1 + comp2);

        if (max1 > max)
        {
            max = max1;
            comp++;
        }
        if (min1 < min)
        {
            min = min1;
            comp++;
        }
    }
    return comp;
}

int32_t main()
{
    int n = 9000;
    int arr[n + 1];
    // int rand_n;
    // // generate input
    // ofstream write("search.txt");
    // f0(n)
    // {
    //     int k = rand() % 500 + 1;
    //     write << k << endl;
    // }
    ifstream in("search.txt");
    for (int i = 0; i < n; i++)
    {
        in >> arr[i];
    }
    in.close();
    clock_t start, end;
    start = clock();
    int comp1 = max_min_normal(arr, n);
    end = clock();
    cout << "Normal Method:\n";
    cout << "Max: " << maxx << ", Min: " << minn << endl;
    int max2 = arr[0];
    int min2 = arr[0];
    int comp2 = MaxMin(0, n - 1, arr, max2, min2);
    cout << "Comparisons: " << comp1 << endl;
    cout << "Divide and Conquer Method:\n";
    cout << "Max: " << max2 << ", Min: " << min2 << ", Comparisons: " << comp2 << endl;
}
