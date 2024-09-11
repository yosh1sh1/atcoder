#include <bits/stdc++.h>

#include <algorithm>
#include <vector>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n;
    cin >> n;

    if (n%2 != 0)
        return 0;

    vector<char> v;
    rep(i, 0, n) {
        if (i < n/2)
            v.push_back('(');
        else
            v.push_back(')');
    }

    // 有効な(, )の付き方にならない
    /*
        N = 4
        ()()
        ())(
        )(()
        )()(
        ))((
    */
    while (next_permutation(v.begin(), v.end())) {
        for (auto c : v) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}
