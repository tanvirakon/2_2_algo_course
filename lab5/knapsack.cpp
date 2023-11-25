// In the name of Allah the most beneficent the most merciful - sūrat l-naml(27:30)
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(_a) _a.rbegin(), _a.rend()
int main()
{
    int sum = 0, flag = 0;
    ifstream in("knapsack.txt");
    int i;
    in >> i;
    sum = i;
    int size = sum;
    double weight[size];
    int count = 0;
    while (count < size and in >> i)
    {
        weight[count] = i;
        count++;
    }
    cout << "weights: ";
    for (auto i : weight)
        cout << i << " ";
    cout << endl;

    double profit[size];
    count = 0;
    while (count < size and in >> i)
    {
        profit[count] = i;
        count++;
    }
    cout << "profits: ";
    for (auto i : profit)
        cout << i << " ";
    cout << endl;
    in >> i;
    int capacity = i;
    cout << "capacity: " << capacity << endl;

    vector<pair<double, int>> v;
    for (int i = 0; i < size; i++)
    {
        v.pb({profit[i] / weight[i], i});
    }
    sort(all(v));
    double maxProfit = 0;
    vector<pair<int, double>> v2;
    for (auto j : v)
    {
        if (capacity <= 0)
        {
            v2.pb({j.ss, 0});
            continue;
        }
        if (capacity >= weight[j.ss])
        {
            v2.pb({j.ss, 1});
            maxProfit += profit[j.ss];
            capacity -= weight[j.ss];
        }
        else
        {
            // cout<<j.ff<<" "<<j.ss;
            double share = (capacity * 1.0) / weight[j.ss];
            v2.pb({j.ss, share});
            maxProfit += (profit[j.ss] * share);
            capacity -= weight[j.ss];
        }
    }
    sort(v2.begin(), v2.end());
    cout << "percentage: ";
    for (auto i : v2)
        cout << i.ss << " ";
    cout << endl;
    cout << "maxProfit: " << maxProfit << endl;
}
