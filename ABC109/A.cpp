#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;


int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

  int a, b;
  cin >> a >> b;

  if (a & 1 && b & 1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;


	return 0;
}
