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

  vector<string> w(n);
  rep (i, 0, n)
    cin >> w[i];

  set<string> st;
  st.insert(w[0]);
  char last = w[0][w[0].size() - 1];
  rep (i, 1, n) {
    if (st.find(w[i]) != st.end()) {
      cout << "No" << endl;
      return 0;
    }

    if (last != w[i][0]) {
      cout << "No" << endl;
      return 0;
    }

    st.insert(w[i]);
    last = w[i][w[i].size() - 1];
  }

  cout << "Yes" << endl;

	return 0;
}
