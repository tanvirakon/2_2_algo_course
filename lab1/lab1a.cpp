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
int32_t main()
{
    fast();
    srand(time(0));

    // // generate input
    // ofstream write("search.txt");
    // int n = 50000;
    // f0(n)
    // {
    //     int k = rand() % 500 + 1;
    //     write << k << endl;
    // }

    vector<int> a;
    ifstream in("search.txt");
    int i;
    int count = 0;
    int size = rand() % 50000 + 1;
    while (in >> i and count < size)
    {
        a.pb(i);
        count++;
    }
    ofstream out("soln.txt");

    // linear
    int flag = 0;
    int key = rand() % 500 + 1;
    out << "key: " << key << endl;
    out << "size: " << size << endl;
    int steps1 = 0;
    f0(size)
    {
        steps1++;
        if (key == a[i])
        {
            flag = 1;
            break;
        }
    }
    // liner
    out << "linear search: ";
    if (flag)
        out << "yes\n";
    else
        out << "NO\n";
    out << "steps taken for linear search: " << steps1 << endl;

    // binary
    sort(all(a));
    flag = 0;
    int high = size - 1;
    int low = 0;
    int steps2 = 0;
    while (low <= high)
    {
        steps2++;
        int mid = (high + low) / 2;
        if (a[mid] == key)
        {
            flag = 1;
            break;
        }
        if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    // binary
    out << "binary search: ";
    if (flag)
        out << "yes\n";
    else
        out << "NO\n";
    out << "steps taken for binary search: " << steps2 << endl;
}
