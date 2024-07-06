#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

  string s;
  cin >> s;

  if (s[0] == 'S')
    cout << "Cloudy" << endl;
  else if (s[0] == 'C')
    cout << "Rainy" << endl;
  else
    cout << "Sunny" << endl;

	return 0;
}
