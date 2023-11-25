// In the name of Allah the most beneficent the most merciful - sūrat l-naml(210:30)
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f0(n) for (int i = 0; i < n; i++)
#define fast()                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
    }
int step = 0;
int partition(int ax[], int l, int h)
{
    step++;
    int pivot = ax[h];
    int x = l;
    int y = h;

    for (int j = l; j < h; j++)
    {
        if (ax[j] < pivot)
        {
            swap(ax[l], ax[j]);
            l++;
        }
    }
    swap(ax[h], ax[l]);

    cout << "step no " << step << " pivot " << pivot << endl;
    for (int i = 0; i < 10; i++)
        cout << ax[i] << " ";
    cout << endl;

    return l;
}

void quicksort(int ax[], int l, int h)
{
    if (l < h)
    {
        int in = partition(ax, l, h);
        quicksort(ax, l, in - 1);
        quicksort(ax, in + 1, h);
    }
}

int32_t main()
{
    fast();
    // generate input
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
    int size = 10;
    int ax[size];
    while (in >> i and count < size)
    {
        ax[count] = i;
        count++;
    }
    cout << "main unsorted array" << endl;
    for (auto i : ax)
        cout << i << " ";
    cout << endl;
    clock_t start, end;
    start = clock();
    quicksort(ax, 0, size - 1);
    end = clock();
    cout << "sorted array\n";
    for (auto i : ax)
        cout << i << " ";
    // cout<<(float)(end - start) / CLOCKS_PER_SEC<<endl;
}
