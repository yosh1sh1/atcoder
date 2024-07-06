#include <iostream>
#include <string>

using namespace std;

int main() {  
    int m_flg = -1;
    int r_flg = -1;

    string input;
    cin >> input;


    for (int i = 0; i < input.size(); i++) {
        if (input[i] == 'M')
            m_flg = i;    
        if (input[i] == 'R')
            r_flg = i;
    }

    if (m_flg == -1 || r_flg == -1)
        cout << "No" << endl;

    if (r_flg < m_flg)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
        
    return 0;
}