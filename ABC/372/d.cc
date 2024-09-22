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

    vector<int> h(n);
    rep(i, 0, n)
        cin >> h[i];

    stack<int> st;
    st.push(h[n-1]);

    vector<int> res(n, 0);
    res[n-1] = 0;
    for (int i = n - 2; i >= 0; --i) {
        res[i] = st.size();

        while (!st.empty()) {
            int pre = st.top();
            if (pre < h[i]) {
                st.pop();
            } else {
                break;
            }
        }
        st.push(h[i]);
    }

    rep(i, 0, n)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}
