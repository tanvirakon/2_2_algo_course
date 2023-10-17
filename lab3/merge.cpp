// In the name of Allah the most beneficent the most merciful - sūrat l-naml(27:30)
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
#define nn 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define f0(n) for (int i = 0; i < n; i++)
#define f1(n) for (int i = 1; i < n; i++)
#define all(_a) _a.begin(), _a.end()
#define fast()                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
    }
int bx[7];
void merge(int ax[], int l, int mid, int h)
{
    int i = l;
    int j = mid + 1;
    int k = l;
    while (i <= mid and j <= h)
    {
        if (ax[i] >= ax[j])
        {
            bx[k] = ax[j];
            k++;
            j++;
        }
        else
        {
            bx[k] = ax[i];
            k++;
            i++;
        }
    }
    while (i <= mid)
    {
        bx[k] = ax[i];
        k++;
        i++;
    }
    while (j <= h)
    {
        bx[k] = ax[j];
        j++;
        k++;
    }
    for (int i = l; i <= h; i++)
        ax[i] = bx[i];
}
void mergesort(int ax[], int l, int h)
{
    if (l >= h)
        return;
    else
    {
        int mid = (l + h) / 2;
        mergesort(ax, l, mid);
        mergesort(ax, mid + 1, h);
        merge(ax, l, mid, h);
    }
}
int32_t main()
{
    fast();
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
    int size = 10;
    int ax[size];
    while (in >> i and count < size)
    {
        ax[count] = i;
        count++;
    }
    int a_size = size;
    mergesort(ax, 0, a_size - 1);
    for (auto i : bx)
        cout << i << " ";
}
