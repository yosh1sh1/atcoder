#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

  int n, k ,m;
  cin >> n >> k >> m;

  vector<int> a(n);
  int sum = 0;
  rep (i, 0, n - 1) {
    cin >> a[i];
    sum += a[i];
  }

  int score = (m * n) - sum;
  if (score > k)
    cout << -1 << endl;
  else
    cout << ((score >= 0) ? score : 0) << endl;


	return 0;
}
