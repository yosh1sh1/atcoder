#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

/**
 *  問題を解くのに必要な経路を数直線で表現
 *  2->1というケースを表現したいため、n*2の配列を用意
 * 
 * 配列内は休憩場1から各休憩所（n*2 - 1）までのコストを格納
 *  1->1(0), 1->2, 1->3, 1->4, 1->1 ... 1->1->4
 */

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> a(n+1);
    rep(i, 0, n)
        cin >> a[i];

    vector<int> r;
    r.push_back(0); // 0 -> 0 のケース

    rep(i, 0, n*2) {
        r.push_back((r[i] + a[i % n]) % m);
    }

    vector<int> b(m, 0);
    rep(i, 0, n) {
        b[r[i]]++;
    }

    ll res = 0;
    rep(i, 0, n) {
        b[r[i]]--; // 不要なケース（1周分）の削除
        res += b[r[i]];
        b[r[i+n]]++; // 次の判定に必要なケースを追加
    }

    cout << res << endl;

    return 0;
}
