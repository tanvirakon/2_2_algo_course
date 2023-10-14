// take numbers from a file a comparison between algo 3.6 and 3.7
//  In the name of Allah the most beneficent the most merciful - sūrat l-naml(27:30)
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
void StraightMaxMin(vector<int> a, int n)
{
    int max = a[0];
    int min = a[0];
    int count1 = 0;
    int count2 = 0;
    for (int i = 1; i < n; i++)
    {
        // ctg++;
        if (count1++ and a[i] > max)
        {
            max = a[i];
        }
        if (count2++ and a[i] < min)
        {
            min = a[i];
        }
    }
    cout << count1 << " " << count2 << endl;
}
void OptimisedStraightMaxMin(vector<int> a, int n)
{
    int max = a[0];
    int min = a[0];
    int count1 = 0;
    int count2 = 0;
    for (int i = 1; i < n; i++)
    {
        // ctg++;
        if (count1++ and a[i] > max)
        {
            max = a[i];
        }
        else if (count2++ and a[i] < min)
        {
            min = a[i];
        }
    }
    cout << count1 << " " << count2 << endl;
}
void MaxMin(vector<int> a, int n)
{
    int i = 0;
    int j = n - 1;
    int max = 0;
    int min = 0;
    if (i == j)
    {
        max = a[i];
        min = a[i];
    }
    else if (i == j - 1)
    {
        if (a[i] < a[j])
        {
            max = a[j];
            min = a[i];
        }
    }
    else{
        
    }
}
int32_t main()
{
    fast();
    // int sum = 0, flag = 0;
    // ofstream file("input.txt");
    // vector<int> a;
    // int n = 200000;
    // f0(n)
    // {
    //     int b = rand() % 500 + 1;
    //     file << b << endl;
    // }

    // taking vector from file
    vector<int> a;
    int i;
    ifstream open("input.txt");
    int n = 5000;
    int count = 0;
    while (open >> i and count != n)
    {
        a.pb(i);
        count++;
    }
    // sort(all(a));

    // 3.6
    StraightMaxMin(a, n);
    // 3.6 optimised
    OptimisedStraightMaxMin(a, n);
}
