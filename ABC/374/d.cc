#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, s, t;
    cin >> n >> s >> t;

    vector<pair<int, int>> st(n);
    vector<pair<int, int>> ed(n);
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >>d;

        st[i] = make_pair(a, b);
        ed[i] = make_pair(c, d);
    }

    // 順列の準備
    vector<int> idx;
    for (int i = 0; i < n; i++)
        idx.push_back(i);

    double t_time = 0;

    // auto calc_len = [&](int x1, int y1, int x2, int y2) -> double {
    //     lambda_x = x1 - x2;
    //     lambda_y = y1 - y2;
    //     return sqrt(x * x + y * y);
    // }

    // 線分を引く時間の計算
    for (int i = 0; i < n; i++) {
        int x = st[i].first - ed[i].first;
        int y = st[i].second - ed[i].second;
        t_time += sqrt(x * x + y * y) / t;
    }

    double s_time = numeric_limits<double>::max();
    // 始点の探査
    do {
        for (int bit = 0; bit < (1<<n); bit++) {
            pair<int, int> pre = make_pair(0, 0);
            double tmp = 0;
            for (int i = 0; i < n; i++) {
                if (bit & (1 << i)) { // c, d を始点
                    int x = ed[idx[i]].first - pre.first;
                    int y = ed[idx[i]].second - pre.second;
                    tmp += sqrt(x * x + y * y) / s;
                    pre = st[idx[i]];
                } else { // a, b を始点
                    int x = st[idx[i]].first - pre.first;
                    int y = st[idx[i]].second - pre.second;
                    tmp += sqrt(x * x + y * y) / s;
                    pre = ed[idx[i]];
                }
            }
            s_time = min(s_time, tmp);
        }
    } while (next_permutation(idx.begin(), idx.end()));

    std::cout << std::fixed;
    std::cout << setprecision(6) << t_time + s_time << endl;

    return 0;
}