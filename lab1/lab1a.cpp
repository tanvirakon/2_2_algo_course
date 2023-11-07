// In the name of Allah the most beneficent the most merciful - sūrat l-naml(27:30)
#include <bits/stdc++.h>
using namespace std;
#define f0(n) for (int i = 0; i < n; i++)
#define pb push_back
#define all(_a) _a.begin(), _a.end()


int main()
{
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
    int size = 20000;
    while (in >> i and count < size)
    {
        a.pb(i);
        count++;
    }
    in.close();
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
    out.close();
}
