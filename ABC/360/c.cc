#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> a;
    vector<vector<int>> w(n);
    int res = 0;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    for (auto i : a) {
        int tmp;
        cin >> tmp;
        w[i - 1].push_back(tmp);
    }

    for (int i = 0; i < n; i++) {
        if (w[i].size() > 1) {
            sort(w[i].begin(), w[i].end());  
            for (int j = 0; j < w[i].size() - 1; j++) {
                res += w[i][j];
            }
        }
    }    


    cout << res << endl;

    return 0;
}