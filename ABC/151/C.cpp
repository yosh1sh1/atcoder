#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  vector<pair<int, string>> result(m);
  rep (i, 0, m) {
    int p;
    string s;
    cin >> p >> s;
    p--;
    result[i] = make_pair(p, s);
  }

  vector<int> memo(n, 0);
  vector<int> pe(n, 0);
  vector<int> ac(n, 0);
  rep (i, 0, m) {
    if (result[i].second == "AC" && memo[result[i].first] != 1) {
      ac[result[i].first] = 1;
      memo[result[i].first] = 1;
    } else if (result[i].second == "WA" && memo[result[i].first] != 1) {
      pe[result[i].first]++;
    }
  }

  int res_ac = 0;
  int res_pe = 0;
  rep (i, 0, n) {
    if (ac[i]) {
      res_ac++;
      res_pe += pe[i];
    }
  }

  cout << res_ac << " " << res_pe << endl;

	return 0;
}
