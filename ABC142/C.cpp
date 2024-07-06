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

  vector<pair<int, int>> a(n);
  rep (i, 0, n) {
    int tmp;
    cin >> tmp;
    a[i].first = tmp;
    a[i].second = i + 1;
  }

  sort(a.begin(), a.end());

  rep (i, 0, n)
    cout << a[i].second << " ";

  cout << "\n";



	return 0;
}
