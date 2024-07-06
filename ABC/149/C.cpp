#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;
const int MAX = 1e5 + 1;
int prime[MAX];

using namespace std;

void era()
{
  prime[0] = prime[1] = 0;
  rep (i, 2, MAX)
    prime[i] = 1;

  rep (i, 2, MAX) {
    if (prime[i] == 1) {
      for (int j = i + 1; j < sqrt(MAX); j++) {
        if (j % i == 0)
          prime[j] = 0;
      }
    }
  }
}

bool judge(int x)
{
  if (x < 2)
    return false;

  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0)
      return false;
  }
  return true;
}

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

  int x;
  cin >> x;

  era();

  rep (i, x, INF) {
    if (judge(i)) {
      cout << i << endl;
      break;
    }
  }

	return 0;
}
