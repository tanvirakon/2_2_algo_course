#include <bits/stdc++.h>
using namespace std;
#define ll long double
#define vl vector<ll>
#define ff first
#define Optimization()       \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);             \
	cerr.tie(0)
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
#define N 2000005
#define ok cout << "OK" << nn;

ll area(pl z, pl a, pl b)
{
	return z.ff * (a.ss - b.ss) + a.ff * (b.ss - z.ss) + b.ff * (z.ss - a.ss);
}
ll dis(pl a, pl b)
{
	return sqrt((a.ff - b.ff) * (a.ff - b.ff) + (a.ss - b.ss) * (a.ss - b.ss));
}
// bool oriention(pl a, pl b)
// {
//     ll aa = area(ara[0], a, b);
//     if (aa > 0)
//         return 1;
//     else if (aa < 0)
//         return 0;
//     else
//     {
//         cout << "oriention=" << nn;
//         cout << a.ff << " " << a.ss << nn;
//         cout << b.ff << " " << b.ss << nn;
//         cout << "f=" << dis(ara[0], a) << " " << dis(ara[0], b) << nn << nn;
//         return dis(ara[0], a) < dis(ara[0], b);
//     }
// }
bool possible(pl a, pl b, pl c)
{
	ll aa = area(a, b, c);
	if (aa > 0)
		return 1;
	else if (aa < 0)
		return 0;
	else
		return dis(a, b) < dis(a, c);
}
int main()
{
	ll n, i, m, a, b, j, k, sm = 0;
	// cin >> n;
	// for (i = 0; i < n; i++)
	// {
	//     cin >> a >> b;
	//     ara.pb({a, b});
	// }
	bool cnt = 0;
	vpl ara;
	fstream file;
	file.open("convex_file.txt");
	while (!file.eof())
	{
		if (!cnt)
		{
			file >> n;
		}
		if (file.peek() == '\n')
			cnt = 1;
		if (cnt)
		{
			file >> a >> b;
			ara.pb({a, b});
		}
	}
	file.close();
	// for(auto x:ara)
	// cout<<x.ff<<" "<<x.ss<<endl;
	ll ind = 0;
	for (i = 1; i < n; i++)
	{
		if (ara[ind].ff > ara[i].ff)
			ind = i;
		else if (ara[ind].ff == ara[i].ff && ara[ind].ss > ara[i].ss)
			ind = i;
	}
	swap(ara[ind], ara[0]);
	sort(ara.begin(), ara.end(), [](const pl &a, const pl &b)
		 { return (a.ff == b.ff) ? (a.ss < b.ss) : (a.ff < b.ff); });
	vector<pl> ans;
	ans.push_back(ara[0]);
	ans.push_back(ara[1]);
	for (i = 2; i < n; i++)
	{
		pl tem = ans.back();
		ans.pop_back();
		while (ans.size() > 0 && (!possible(ans.back(), tem, ara[i])))
		{
			tem = ans.back();
			ans.pop_back();
		}
		ans.push_back(tem);
		ans.push_back(ara[i]);
	}

	sort(ara.begin(), ara.end(), [](const pl &a, const pl &b)
		 { return (a.ff == b.ff) ? (a.ss > b.ss) : (a.ff > b.ff); });

	vector<pl> ans2;
	ans2.push_back(ara[0]);
	ans2.push_back(ara[1]);
	for (i = 2; i < n; i++)
	{
		pl tem = ans2.back();
		ans2.pop_back();
		while (ans2.size() > 0 && (!possible(ans2.back(), tem, ara[i])))
		{
			tem = ans2.back();
			ans2.pop_back();
		}
		ans2.push_back(tem);
		ans2.push_back(ara[i]);
	}
	for (i = 1; i < ans2.size(); i++)
	{
		if (ans2[i] == ans[0])
			break;
		ans.push_back(ans2[i]);
	}
	cout << ans.size() << nn;
	for (i = 0; i < ans.size(); i++)
		cout << fixed << setprecision(0) << round(ans[i].ff) << " " << round(ans[i].ss) << nn;
}