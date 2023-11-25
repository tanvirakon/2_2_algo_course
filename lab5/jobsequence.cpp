// In the name of Allah the most beneficent the most merciful - sūrat l-naml(27:30)
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define ff first
#define ss second

#define all(_a) _a.rbegin(), _a.rend()
#define fast()                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
    }
int32_t main()
{
    ifstream in("jobsequence.txt");
    int i;
    in >> i;
    int job = i;
    int profit[job];
    int count = 0;
    while (count < job and in >> i)
    {
        profit[count] = i;
        count++;
    }
    cout << "profits: ";
    for (auto i : profit)
        cout << i << " ";
    cout << endl;

    int deadline[job];
    count = 0;
    while (count < job and in >> i)
    {
        deadline[count] = i;
        count++;
    }
    cout << "deadlines: ";
    for (auto i : deadline)
        cout << i << " ";
    cout << endl;

    vector<pair<int, int>> v;
    for (int i = 0; i < job; i++)
        v.pb({profit[i], deadline[i]});
    sort(all(v));

    vector<int> dayslimit;
    for (auto i : deadline)
        dayslimit.pb(i);

    sort(dayslimit.begin(), dayslimit.end());
    int maxdeadline = dayslimit[job - 1];

    int maxprofit = 0;
    vector<int> days(maxdeadline, 0);
    for (int i = 0; i < job; i++)
    {
        int pft = v[i].ff;
        int limit = v[i].ss;
        if (days[limit - 1] == 0)
        {
            days[limit - 1] = pft;
            maxprofit += pft;
        }
        else
        {
            for (int j = limit - 2; j >= 0; j--)
            {
                // cerr << j << " " << pft << endl;
                if (days[j] == 0)
                {
                    maxprofit += pft;
                    days[j] = pft;
                    break;
                }
            }
        }
    }
    vector<int> pp;
    for (auto i : profit)
        pp.pb(i);

    for (int i = 0; i < days.size(); i++)
    {
        for (int j = 0; j < pp.size(); j++)
        {

            if (pp[j] == days[i])
            {
                cout << "deadline " << i + 1 << " = ";
                cout << j + 1 << "th job" << endl;
            }
        }
    }
    cout << "maxprofit: " << maxprofit << endl;
}
