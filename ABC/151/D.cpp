#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int bfs(vector<vector<char>> &s, int st_h, int st_w, int ed_h, int ed_w)
{
  queue<pair<int, int>> que;
  queue<int> score;
  que.push(make_pair(st_h, st_w));
  score.push(0);

  int res = INT_MAX;
  bool goal = false;
  pair<int, int> dt[4] = {
                          make_pair(-1, 0),
                          make_pair(0, -1),
                          make_pair(1, 0),
                          make_pair(0, 1)
  };
  vector<vector<int>> memo(s.size(), vector<int>(s[0].size(), 0));
  while (!que.empty()) {
    pair<int, int> pt = que.front();
    int now_score = score.front();
    que.pop();
    score.pop();

    memo[pt.first][pt.second] = 1;

    if (pt.first == ed_h && pt.second == ed_w) {
      res = min(res, now_score);
      goal = true;
      break;
    }

    rep (i, 0, 4) {
      int new_h = pt.first + dt[i].first;
      int new_w = pt.second + dt[i].second;
      if (new_h < 0 || new_h >= s.size()
          || new_w < 0 || new_w >= s[0].size())
        continue;

      if (s[new_h][new_w] == '.' && memo[new_h][new_w] == 0) {
        que.push(make_pair(new_h, new_w));
        score.push(now_score + 1);
      }
    }
  }

  if (goal)
    return res;
  else
    return -1;
}

vector<vector<int>> bfs2(vector<vector<char>> &s, int st_h, int st_w)
{
  int h = s.size();
  int w = s[0].size();

  queue<pair<int, int>> que;
  que.push(make_pair(st_h, st_w));

  vector<vector<int>> memo(h, vector<int>(w, -1));
  memo[st_h][st_w] = 0;

  pair<int, int> dt[4] = {
                          make_pair(-1, 0),
                          make_pair(0, -1),
                          make_pair(1, 0),
                          make_pair(0, 1)
  };

  while (!que.empty()) {
    pair<int, int> pt = que.front();
    que.pop();

    int score = memo[pt.first][pt.second];
    rep (i, 0, 4) {
      int new_h = pt.first + dt[i].first;
      int new_w = pt.second + dt[i].second;
      if (new_h < 0 || new_h >= s.size()
          || new_w < 0 || new_w >= s[0].size())
        continue;

      if (s[new_h][new_w] == '#' || memo[new_h][new_w] != -1) {
        continue;
      } else {
        que.push(make_pair(new_h, new_w));
        memo[new_h][new_w] = score + 1;
      }
    }
  }

  return memo;
}

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

  int h, w;
  cin >> h >> w;

  vector<vector<char>> s(h, vector<char>(w));
  rep (i, 0, h)
    rep (j, 0, w)
    cin >> s[i][j];

  int res = 0;
  /*
  rep (i, 0, h)
    rep (j, 0, w)
    rep (k, 0, h)
    rep (l , 0, w)
    if (s[i][j] == '.' && s[k][l] == '.') {
      int ret = max(res, bfs(s, i, j, k, l));
      if (ret == -1)
        continue;
      else
        res = max(res, ret);
    }
  */

  rep (i, 0, h) {
    rep (j, 0, w) {
      vector<vector<int>> memo = bfs2(s, i, j);
      rep (k, 0, h) {
        rep (l, 0, w) {
          if (s[i][j] == '.' && memo[k][l] != -1)
            res = max(res, memo[k][l]);
        }
      }
    }
  }
  cout << res << endl;

	return 0;
}


