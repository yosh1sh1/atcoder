#include <bits/stdc++.h>

#define rep(i, x, n) for (ll i = x; i < n; i++)
typedef long long ll;

const ll INF = 1e9 + 7;

using namespace std;

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

	ll n, t;
	cin >> n >> t;
	
	string s;
	cin >> s;

	vector<ll> x_pos;
	vector<ll> x_neg;
	ll ans = 0;
	rep(i, 0, n) {
		ll tmp;
		cin >> tmp;

		if (s[i] == '0')
			x_neg.push_back(tmp);
		else
			x_pos.push_back(tmp);
	}

	sort(x_pos.begin(), x_pos.end());
	sort(x_neg.begin(), x_neg.end());

	ll l = 0; // 加算条件のx_neg配列の左端のインデックス
	ll r = 0; // 加算条件のx_neg配列の右端のインデックス
	rep(i, 0, (ll)x_pos.size()) {
		rep (j, l, x_neg.size()) {
			if (x_pos[i] < x_neg[j])
				break;
			l++;
		}
		if (r < l)
			r = l;
		rep (j, r, x_neg.size()) {
			ll tmp = x_neg[j] - t * 2;
			if (x_pos[i] >= tmp)
				r++;
			else
				break;
		}
		ans += r - l;
	}

	cout << ans << endl;
	return 0;
}
