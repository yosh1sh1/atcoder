#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

void one2dst(vector<ll> &a, vector<vector<pair<ll, ll>>> &route,
             vector<pair<ll, ll>> &cost)
{

  queue<pair<int, int>> que; // <now id, next id>
  rep (i, 0, route[0].size()) {
    que.push(make_pair(0, route[0][i].first)); // node id push
  }

  while (!que.empty()) {
    pair<int, int> id = que.front();
    que.pop();

    if (cost[id.second].first == 0) {
      cost[id.second].second = cost[id.first].first + route[id.first]
    }
  }
}

void dst2one(vector<ll> &a, vector<vector<pair<ll, ll>>> &route,
             vector<pair<ll, ll>> &cost)
{

}

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

  int n, m, t;
  cin >> n >> m >> t;

  vector<ll> a(n);
  rep (i, 0, n)
    cin >> a[i];

  vector<vector<pair<ll, ll>>> route(m);
  rep (i, 0, m) {
    int tmpa, tmpb, tmpc;
    cin >> tmpa >> tmpb >> tmpc;
    tmpa--; tmpb--;
    route[tmpa].push_back(make_pair(tmpb, tmpc));
  }


  vector<pair<ll, ll>> cost(n, pair<ll, ll>(0, 0));
  // 1 to dst


  // dst to 1


	return 0;
}
