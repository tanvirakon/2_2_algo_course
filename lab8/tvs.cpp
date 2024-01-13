#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

map<int, vector<int>> graph;
ll tolerance;
set<ll> boosterPlacement;
ll weight[500][500] = {-1};
ll dfs(ll node, ll par)
{
    if (graph.find(node) == graph.end()) // mane er kno child nai...so no iterate
    {
        return 0;
    }
    ll d = 0;
    for (auto it : graph[node])
    {
        // cout << it << " " << node << endl;
        d = max(weight[node][it] + dfs(it, node), d); // jtogula chind ase tader mddhe max
        // cout << node << " " << it << " " << weight[node][it] << " " << d << endl;
        if (par != -1 && (d + weight[par][node] > tolerance))
        {
            boosterPlacement.insert(node);
            d = 0;
        }
        // for (auto i : boosterPlacement)
        //     cout << i << " ";
        // cout << endl;
    }
    return d;
}
int main()
{
    ll u, v, w;
    ifstream in("tvs.txt");
    while (in >> u >> v >> w)
    {
        graph[u].pb(v);
        weight[u][v] = w;
    }

    cout << "Enter Tolerance: ";
    cin >> tolerance;
    dfs(1, -1);
    cout << "Booster Placements: ";
    for (auto it : boosterPlacement)
    {
        cout << it << " ";
    }
}
