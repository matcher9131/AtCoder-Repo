#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void judge(string& s) {
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] > s[0]) {
            cout << "Yes" << endl;
            return;
        } else if (s[i] == s[0]) {
            string t1 = s.substr(0, i);
            string t2 = s.substr(i);
            if (t1 < t2) {
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
    return;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        judge(s);
    }

    return 0;
}