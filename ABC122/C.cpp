#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

  int n, q;
  string s;
  cin >> n >> q >> s;

  vector<pair<int, int>> quest(q);
  rep (i, 0, q)
    cin >> quest[i].first >> quest[i].second;

  int ac[n] = {};
  int count = 0;
  rep (i, 0, n - 1) {
    ac[i] = count;
    if (s[i] == 'A' && s[i+1] == 'C') {
      count++;
    }
  }
  ac[n - 1] = count;

  rep (i, 0, q) {
    cout << ac[quest[i].second - 1] - ac[quest[i].first - 1] << endl;
  }

	return 0;
}
