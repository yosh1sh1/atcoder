#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<pair<int, int>> input(n - 1);
  vector<vector<int>> tree(n);
  rep (i, 0, n - 1) {
    cin >> input[i].first >> input[i].second;
    input[i].first--;
    input[i].second--;

    tree[input[i].first].push_back(input[i].second);
    tree[input[i].second].push_back(input[i].first);
  }

  int memo[n];
  memset(memo, 0, sizeof(memo));
  queue<pair<int, int>> que;
  que.push(make_pair(0, -1));
  map<pair<int, int>, int> mp;
  int k = 0;

  while (!que.empty()) {
    pair<int, int> id = que.front();
    que.pop();

    memo[id.first] = 1;
    k = max(k, (int)tree[id.first].size());

    int cur_c = 1;
    for (int tmp : tree[id.first]) {
       if (memo[tmp] != 0)
        continue;

      if (cur_c == id.second)
        cur_c++;
      mp[make_pair(id.first, tmp)] = cur_c;
      mp[make_pair(tmp, id.first)] = cur_c;
      que.push(make_pair(tmp, cur_c));
      cur_c++;
    }
  }

  cout << k << endl;
  rep (i, 0, n - 1) {
    cout << mp[input[i]] << endl;
  }
	return 0;
}
