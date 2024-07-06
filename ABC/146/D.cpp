#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int memo[100000 + 1];

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<pair<int, int>> input(n - 1);

  vector<vector<pair<int, int>>> tree(n);
  rep (i, 0, n - 1) {
    cin >> input[i].first >> input[i].second;
    input[i].first--;
    input[i].second--;
    tree[input[i].first].push_back(make_pair(input[i].second, -1));
    tree[input[i].second].push_back(make_pair(input[i].first, -1));
  }

  
  int k = 0;
  queue<pair<int, int>> que; // id, p_color
  que.push(make_pair(0, -1));
  while (!que.empty()) {
    pair<int, int> id = que.front();
    que.pop();

    memo[id.first] = 1;

    int cur_c = 1;
    k = max(k, (int)tree[id.first].size());
    //    for (pair<int, int> next : tree[id.first]) {
    for (int i = 0; i < tree[id.first].size(); i++) {
      pair<int, int> next = tree[id.first][i];
      if (memo[next.first] != 0)
        continue;

      if (cur_c == id.second)
        cur_c++;
      tree[id.first][i].second = cur_c;
      tree[next.first][id.first].second = cur_c;
      que.push(make_pair(next.first, cur_c));
      cur_c++;
    }
  }

  cout << k << endl;
  rep (i, 0, n - 1) {
    for (pair<int, int> tmp : tree[input[i].first]) {
      if (tmp.first == input[i].second) {
        cout << tmp.second << endl;
        break;
      }
    }
  }



	return 0;
}
