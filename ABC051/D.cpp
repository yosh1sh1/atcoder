#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int n, m;

void bfs(int st_n, int st_c, vector<vector<pair<int, int>>> &pass, vector<pair<int, vector<int>>> &route, vector<vector<int>> &id)
{
  queue<pair<int, int>> que; // first: current_node, second: current_cost
  que.push(make_pair(st_n, st_c));

  while (!que.empty()) {
    pair<int, int> front = que.front();
    que.pop();

    rep (i, 0, pass[front.first].size()) {
      pair<int, int> tmp = pass[front.first][i];

      if (front.second + tmp.second < route[tmp.first].first) {
        route[tmp.first].first = front.second + tmp.second;
        route[tmp.first].second = route[front.first].second;
        route[tmp.first].second.push_back(id[front.first][i]);
        que.push(make_pair(tmp.first, route[tmp.first].first));
      }
    }
  }
}

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

  cin >> n >> m;

  vector<vector<pair<int, int>>> pass(n);
  vector<vector<int>> id(n);
  rep (i, 0, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    pass[a].push_back(make_pair(b, c));
    pass[b].push_back(make_pair(a, c));
    id[a].push_back(i);
    id[b].push_back(i);
  }

  vector<vector<pair<int, vector<int>>>> route(n, vector<pair<int, vector<int>>>(n));
  rep (i, 0, n) {
    rep (j, 0, n) {
      if (i == j)
        route[i][j].first = 0;
      else
        route[i][j].first = INF;
    }
  }

  rep (i, 0, n) {
      bfs(i, 0, pass, route[i], id);
  }

  set<int> s;
  rep (i, 0, n) {
    rep (j, 0, n) {
      for (int tmp : route[i][j].second)
        s.insert(tmp);
    }
  }

  cout << m - s.size() << endl;
	return 0;
}
