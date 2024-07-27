#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

	int xa, ya, xb, yb, xc, yc;
	cin >> xa >> ya >> xb >> yb >> xc >> yc;

	int xab = abs(xa - xb);
	int yab = abs(ya - yb);
	int xac = abs(xa - xc);
	int yac = abs(ya - yc);
	int xbc = abs(xb - xc);
	int ybc = abs(yb - yc);

	vector<int> edge;
	edge.push_back(xab * xab + yab * yab); // ab2
	edge.push_back(xac * xac + yac * yac); // ac2
	edge.push_back(xbc * xbc + ybc * ybc); // bc2

	sort(edge.begin(), edge.end());

	if (edge[0] + edge[1] == edge[2])
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
