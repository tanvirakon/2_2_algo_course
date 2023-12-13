// In the name of Allah the most beneficent the most merciful - sūrat l-naml(27:30)
#include <bits/stdc++.h>
using namespace std;
#define nn 107
#define pb push_back
#define ff first
#define ss second
#define fast()                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
    }
vector<pair<int, int>> g[nn];
vector<int> vis(nn,0);
int prims(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    int sum = 0;
    while (!pq.empty())
    {
        int top_wt = pq.top().ff;
        int tp_nde = pq.top().ss;
        pq.pop();
        if (vis[tp_nde])
            continue;
        sum += top_wt;
        vis[tp_nde] = 1;
        // cout << sum << " " << tp_nde << " " << top_wt << endl;
        for (auto i : g[tp_nde])
        {
            int adj_nde = i.ff;
            int adj_nde_wt = i.ss;
            if (!vis[adj_nde])
            {
                pq.push({adj_nde_wt, adj_nde});
            }
        }
    }
    return sum;
}
int32_t main()
{
    fast();
    int sum = 0, flag = 0;
    ifstream file("input.txt");
    int a = 0, b = 0, c = 0;
    while (!file.eof())
    {
        file >> a >> b >> c;
        // ,2nd node,weight
        g[a].pb({b, c});
        g[b].pb({a, c});
    }
    sum = prims(1);
    cout <<"sum of minimum spanning tree "<< sum << endl;
}
