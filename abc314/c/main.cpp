#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
#include <string>
using namespace std;

int main() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<vector<int>> position(m, vector<int>());
    vector<vector<char>> chars(m, vector<char>());
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        --c;
        position[c].push_back(i);
        chars[c].push_back(s[i]);
    }

    for (int i = 0; i < m; ++i) {
        int last = chars[i].back();
        chars[i].pop_back();
        chars[i].insert(chars[i].begin(), last);
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < position[i].size(); ++j) {
            s[position[i][j]] = chars[i][j];
        }
    }

    cout << s << endl;

    return 0;
}