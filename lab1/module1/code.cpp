#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define f0(n) for (int i = 0; i < n; i++)
void bubble(vector<int> a, int n)
{
    int i, j;
    int flag = 0;
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                flag = 1;
            }
        }

        if (!flag)
            break;
    }
    // cout << a.size();
    for (auto i : a)
        cout << i << " ";
}

void selection(vector<int> a, int n)
{
    f0(n - 1)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
                continue;
            else
            {
                swap(a[i], a[j]);
            }
        }
    }
    for (auto i : a)
        cout << i << " ";
}

void insertion(vector<int> a, int n)
{
    f0(n)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 and a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    for (auto i : a)
        cout << i << " ";
}
int32_t main()
{
    srand(time(0));

    // generate input
    ofstream write("search.txt");
    int n = 50000;
    f0(n)
    {
        int k = rand() % 1000 + 1;
        write << k << endl;
    }

    vector<int> a;
    ifstream in("search.txt");
    int i;
    int count = 0;
    int size = 10;
    while (in >> i and count < size)
    {
        a.pb(i);
        count++;
    }
    in.close();
    clock_t start = clock();
    bubble(a, size);
    clock_t end = clock();
    cout << (float)(end - start) / CLOCKS_PER_SEC << endl;
    selection(a, size);
    end = clock()-end;
    cout << (float)(end - start) / CLOCKS_PER_SEC << endl;
    insertion(a, size);
    end = clock()-end;
    cout << (float)(end - start) / CLOCKS_PER_SEC << endl;
}
