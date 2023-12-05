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
    int sum = 0, flag = 0;
    int n = 10;
    ofstream write("input.txt");
    for (int i = 0; i < n; i++)
    {
        int a = rand() % 10 + 1;
        int b = rand() % 10 + 1;
        int c = rand() % 10;
        write << a << " " << b << " " << c << endl;
    }
}
