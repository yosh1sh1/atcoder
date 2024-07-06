#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> res;

void dfs(int p, int id, int c) {
  res[id] = c;
  for (auto tmp : graph[id]) {
    if (tmp.first == p)
      continue;

    if (tmp.second & 1)
      dfs(id, tmp.first, 1 - c);
    else
      dfs(id, tmp.first, c);
  }
}

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

  int n;
  cin >> n;

  graph.assign(n, vector<pair<int, int>>());
  rep (i, 0, n - 1) {
    int u, v, w;
    cin >> u >> v >> w;

    u -= 1;
    v -= 1;
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
  }

  res.assign(n, 0);
  dfs(-1, 0, 0);

  rep (i, 0, n)
    cout << res[i] << endl;

	return 0;
}
