#include <bits/stdc++.h>

#include <algorithm>
#include <map>
#include <vector>
#include <string>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n;
    cin >> n;

    if (n % 2 != 0)
        return 0;
    
    map<int, vector<string>> mp;
    mp[1].push_back("()");

    for (int i = 2; i <= n/2; i++) {
        for (auto s : mp[i-1]) {
            mp[i].push_back("()" + s);
            int j = 0;
            while (s[j] != ')') {
                if (s[j] == '(') {
                    auto tmp = s;
                    mp[i].push_back(tmp.insert(j+1, "()"));
                }
                j++;
            }
        }
    }

    sort(mp[n/2].begin(), mp[n/2].end());
    for (auto s : mp[n/2])
        cout << s << endl;

    return 0;
}
