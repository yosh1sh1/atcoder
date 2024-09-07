 #include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

    int n;
    vector<int> l;
    vector<int> r;

    cin >> n;
    rep(i, 0, n) {
        int tmp_l, tmp_r;
        cin >> tmp_l >> tmp_r;
        l.push_back(tmp_l);
        r.push_back(tmp_r);
    }

    ll suml = accumulate(l.begin(), l.end(), 0LL);
    ll sumr = accumulate(r.begin(), r.end(), 0LL);
    if (suml > 0 || sumr < 0) {
        cout << "No" << endl;
        return 0;
    }

    vector<int> x;
    ll sumx = suml;
    rep(i, 0, n) { // l[i]をできるだけ大きくしていく
        ll d = min((ll)(r[i] - l[i]), -sumx); // l[i]がr[i]に至るまでの値、sumxを0にする値の最小
        sumx += d;
        x.push_back(l[i] + d);
    }

    cout << "Yes" << endl;
    rep(i, 0, n)
        cout << x[i] << " ";
    cout << endl;

	return 0;
}
