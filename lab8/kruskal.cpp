// In the name of Allah the most beneficent the most merciful - sūrat l-naml(27:30)
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define nn 1e5 + 5
#define all(_a) _a.begin(), _a.end()

#define fast()                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
    }
vector<int> parent(nn);
vector<int> sizee;
int ultimateParent(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = ultimateParent(parent[v]);
}
void unionn(int a, int b)
{
    a = ultimateParent(a);
    b = ultimateParent(b);
    if (a != b)
    {
        if (sizee[a] < sizee[b])
            swap(a, b);
        parent[b] = a;
        sizee[a] += sizee[b];
    }
}

int32_t main()
{
    // fast();
    ifstream file("input.txt");
    int a = 0, b = 0, c = 0, sum = 0;
    vector<pair<int, pair<int, int>>> edges;
    vector<int> v;
    while (!file.eof())
    {
        file >> a >> b >> c;
        v.push_back(a);
        v.push_back(b);
        edges.push_back({c, {a, b}});
    }
    sort(all(edges));
    sort(all(v));
    int n = v[v.size() - 1];
    sizee.resize(n + 1, 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (auto i : edges)
    {
        int wt = i.first;
        a = i.second.first;
        b = i.second.second;
        if (ultimateParent(a) == ultimateParent(b))
            continue;
        cout << a << " " << b << endl;
        unionn(a, b);
        sum += wt;
    }
    cout << "minimum spanning tree by kruskal : " << sum << endl;
}
