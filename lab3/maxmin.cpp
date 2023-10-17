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
int a[15];
void maxmin(int i, int j, int &max, int &min)
{
    if (i == j)
    {
        max = a[i];
        min = a[i];
        return;
    }
    else if (i == j - 1)
    {
        if (a[i] < a[j])
        {
            max = a[j];
            min = a[i];
        }
        else
        {
            min = a[j];
            max = a[i];
        }
        return;
    }
    else
    {
        int max1, min1, mid;
        mid = (i + j) / 2;
        maxmin(i, mid, max, min);
        maxmin(mid + 1, j, max1, min1);
        if (max < max1)
            max = max1;
        if (min > min1)
            min = min1;
    }
}
int32_t main()
{
    fast();
    int sum = 0, flag = 0;
    ifstream in("search.txt");
    int i;
    int count = 0;
    int size = 15;
    while (in >> i and count < size)
    {
        a[count] = i;
        count++;
    }
    int a_size = size;
    int max, min;
    maxmin(0, a_size - 1, max, min);
    cout << max << " " << min;
}
