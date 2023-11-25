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
#define all(_a) _a.begin() + 1, _a.end()
#define fast()                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
    }
vector<pair<int, int>> vp;
stack<pair<int, int>> st;
pair<int, int> tp;

int det(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    return a.ff * (b.ss - c.ss) + b.ff * (c.ss - a.ss) + c.ff * (a.ss - b.ss);
}

int dis(pair<int, int> a, pair<int, int> b)
{
    return sqrt((a.ff - b.ff) * (a.ff - b.ff) + (a.ss - b.ss) * (a.ss - b.ss));
}
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (det(vp[0], a, b) < 0)
        return false;
    else if (det(vp[0], a, b) > 0)
        return true;
    return dis(vp[0], a) < dis(vp[0], b);
}
int32_t main()
{
    fast();
    int sum = 0, flag = 0;
    int i;
    int a, b;
    ifstream file("convex_file.txt");
    // in >> i;
    // int n = i;
    // cout << "number of points : " << n << endl;

    while (!file.eof())
    {
        // int a, b;
        file >> a >> b;
        // cout << a << " " << b << endl;
        vp.pb({a, b});
        // if (i)
        // {
        //     if (vp[i].ff < vp[0].ff) // jar x choto -> left most point detemined by less x
        //         swap(vp[i], vp[0]);
        // }
        sum++;
    }
    int n = sum;
    f1(n)
    {
        if (vp[i].ff < vp[0].ff) // jar x choto -> left most point detemined by less x
                swap(vp[i], vp[0]);
    }
    // cout << n << endl;
    sort(vp.begin() + 1, vp.end(), cmp);
    // for (int i = 0; i < n; i++)
    //     cout << "i = " << i << " " << vp[i].ff << " " << vp[i].ss << endl;
    st.push(vp[0]);
    st.push(vp[1]);
    for (int i = 2; i < n; i++)
    {
        tp = st.top();
        st.pop();
        // cout << i << " " << tp.ff << " " << tp.ss << endl;
        while (st.size() and (det(st.top(), tp, vp[i]) < 0))
        {
            // cout << "i = " << i << " " << tp.ff << " " << st.top().ff << " " << vp[i].ff << " " << det(st.top(), tp, vp[i]) << endl;
            tp = st.top();
            st.pop();
        }
        st.push(tp);
        st.push(vp[i]);
    }
    cout << "convex hall contains\n";
    while (!st.empty())
    {
        cout << st.top().ff << " " << st.top().ss << endl;
        st.pop();
    }
    set<int>set;
}
