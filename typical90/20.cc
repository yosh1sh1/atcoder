#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

namespace {
// a^n
ll pow(ll a, ll n) {
	ll res = 1;
	while (n > 0) {
		if (n & 1)
			res = res * a;
		a = a * a;
		n >>= 1;
	}

	return res;
}
} // namespace

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    ll a, b, c;
    cin >> a >> b >> c;

    if (a < pow(c, b))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
