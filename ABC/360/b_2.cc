#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    if (s == t) {
        cout << "Yes" << endl;
        return 0;
    }

    for (int w = 2; w < s.size() - 1; w++) {
        // vector<string> vec;    
        // for (int st = 0; st < s.size(); st += w) {
        //     int n = w;
        //     if (st + n >= s.size())
        //         n = s.size() - st;
        //     vec.push_back(s.substr(st, n));
        // }

        for (int c = 0; c < w; c++) {
            string gen;
            // for (auto v : vec) {
            //     if (c >= v.size())
            //         break;
            //     gen += v[c];
            // }
            for (int i = c; i < s.size(); i += w) {
                gen += s[i];
            }
            if (gen == t) {
                cout << "Yes" << endl;
                return 0;
            }
        }   
    }

    cout << "No" << endl;

    return 0;
}

