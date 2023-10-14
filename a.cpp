Md Touhidul Islam
#include <bits/stdc++.h>
    using namespace std;
#define ll long long
#define vl vector<ll>
#define ff first
#define ss second
#define pb push_back
#define pl pair<ll, ll>
#define vpl vector<pl>
#define fileread(x) freopen(x, "r", stdin)
#define filewrite(x) freopen(x, "w", stdout)
#define read(_a, _n)              \
    for (auto i = 0; i < _n; i++) \
        cin >> _a[i];
#define show(_a)            \
    for (auto &val : _a)    \
    {                       \
        cout << val << " "; \
    }                       \
    cout << endl;
#define all(_a) _a.begin(), _a.end()
#define mx(_a) *max_element(all(_a))
#define mn(_a) *min_element(all(_a))
#define sum(_a) accumulate(all(_a), 0);
#define pi = 2 * acos(0.0);
#define nn '\n'
#define inf 1e18
#define N 100005
#define ok cout << "OK" << nn;
ll ara[N];
ll tara[N];
void merge(ll low, ll mid, ll high)
{
    ll i = low, j = mid + 1;
    ll ind = low;
    while (i <= mid && j <= high)
    {
        if (ara[i] <= ara[j])
        {
            tara[ind++] = ara[i];
            i++;
        }
        else
        {
            tara[ind++] = ara[j];
            j++;
        }
    }
    if (i <= mid)
    {
        for (; i <= mid; i++)
            tara[ind++] = ara[i];
    }
    else
    {
        for (; j <= high; j++)
            tara[ind++] = ara[j];
    }
    for (i = low; i <= high; i++)
        ara[i] = tara[i];
}
void sortt(ll low, ll high)
{
    if (low == high)
        return;

    ll mid = low + (high - low) / 2;
    sortt(low, mid);
    sortt(mid + 1, high);
    merge(low, mid, high);
}
int main()
{
    ll n, i, m, a, b, j, k, sm = 0;
    cout << "How many numbers:";
    cin >> n;
    for (i = 1; i <= n; i++)
        ara[i] = rand();
    sortt(1, n);
    cout << "After sorting" << nn;
    for (i = 1; i <= n; i++)
        cout << ara[i] << " ";
    cout << nn;
    return 0;
}