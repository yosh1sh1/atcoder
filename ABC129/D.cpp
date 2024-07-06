#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int L[2000][2000];
int R[2000][2000];
int U[2000][2000];
int D[2000][2000];

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

  int h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep (i, 0, h)
    cin >> s[i];

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') {
        L[i][j] = 0;
        U[i][j] = 0;
        continue;
      }

      if (j != 0)
        L[i][j] = L[i][j - 1] + 1;
      else
        L[i][j] = 1;

      if (i != 0)
        U[i][j] = U[i - 1][j] + 1;
      else
        U[i][j] = 1;
    }
  }

  for (int i = h - 1; i >= 0; i--) {
    for (int j = w - 1; j >= 0; j--) {
      if (s[i][j] == '#') {
        R[i][j] = 0;
        D[i][j] = 0;
        continue;
      }

      if (j != w - 1)
        R[i][j] = R[i][j + 1] + 1;
      else
        R[i][j] = 1;

      if (i != h - 1)
        D[i][j] = D[i + 1][j] + 1;
      else
        D[i][j] = 1;
    }
  }

  int res = 0;
  rep (i, 0, h) {
    rep (j, 0, w) {
      res = max(res, L[i][j] + R[i][j] + D[i][j] + U[i][j] - 3);
    }
  }

  cout << res << endl;

	return 0;
}
