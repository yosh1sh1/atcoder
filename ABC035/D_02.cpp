#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;
const int MAX = 1e5 + 1;
using namespace std;

ll n, m, t;

void bfs(int st_node, int st_cost, vector<vector<pair<ll, ll>>> &p, vector<ll> &dst)
{
  queue<pair<ll, ll>> que;
  que.push(make_pair(st_node, st_cost));

  while (!que.empty()) {
    pair<ll, ll> front = que.front();
    que.pop();

    rep (i, 0, p[front.first].size()) {
      pair<ll, ll> tmp = p[front.first][i];
      if (front.second + tmp.second < dst[tmp.first]) {
        dst[tmp.first] = front.second + tmp.second;
        que.push(make_pair(tmp.first, dst[tmp.first]));
      }
    }
  }

}

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

  cin >> n >> m >> t;
  vector<ll> A(n);
  vector<vector<pair<ll, ll>>> pass(n); // pass[i]: 町iから町firstまでsecond分かかる
  vector<vector<pair<ll, ll>>> rev_pass(n);

  rep (i, 0, n)
    cin >> A[i];

  rep (i, 0, m) {
    ll tmp_a, tmp_b, tmp_c;
    cin >> tmp_a >> tmp_b >> tmp_c;
    tmp_a--; tmp_b--;
    pass[tmp_a].push_back(make_pair(tmp_b, tmp_c));
    rev_pass[tmp_b].push_back(make_pair(tmp_a, tmp_c));
  }

  vector<ll> one2n(n, INF);
  vector<ll> n2one(n, INF);

  one2n[0] = 0;
  n2one[0] = 0;

  bfs(0, 0, pass, one2n);
  bfs(0, 0, rev_pass, n2one);

  ll res = 0;
  rep (i, 0, n) {
    ll travel = one2n[i] + n2one[i];
    if (travel > t)
      continue;

    res = max(res, (t - travel) * A[i]);
  }

  cout << res << endl;

	return 0;
}
