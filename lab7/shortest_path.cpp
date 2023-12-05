// In the name of Allah the most beneficent the most merciful - sūrat l-naml(27:30)
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
#define nn 107
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define f0(n) for (int i = 0; i < n; i++)
#define f1(n) for (int i = 1; i < n; i++)
#define all(_a) _a.begin(), _a.end()
#define debug(x) cerr << (#x) << " " << (x) << endl
#define fast()                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
    }
vector<pair<int, int>> g[nn];
vector<int> dist(nn);

void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    f0(nn) dist[i] = 1e5;

    dist[src] = 0;

    pq.push({0, src});
    while (!pq.empty())
    {
        int top_dis = pq.top().ff;
        int top_node = pq.top().ss;
        pq.pop();

        for (auto i : g[top_node])
        {
            int wgt = i.ss;
            int node = i.ff;
            if (top_dis + wgt < dist[node])
            {
                dist[node] = top_dis + wgt;
                pq.push({dist[node], node});
            }
        }
    }
}

int32_t main()
{
    fast();
    int sum = 0, flag = 0;
    ifstream file("input.txt");
    int a, b, w;
    int c = 0;
    int k = 0;
    int ll = 0;
    while (!file.eof())
    {
        file >> a;
        // cout << a << endl;
        if (a != 100)
            g[k].push_back({ll, a});
        ll++;
        c++;
        if (c == 7)
        {
            c = 0;
            k++;
            ll = 0;
        }
    }
    int n = 7;
    // cout << g.size();
    // // int n = sum;
    dijkstra(0);
    cout << "shortest distence from source:\n";
    for (int i = 0; i < n; i++)
        cout << "node " << i << ": " << dist[i] << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << path[i] << " ";
}
