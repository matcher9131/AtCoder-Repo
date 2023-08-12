#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
#include <string>
#include <cctype>
using namespace std;

int main() {
    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<int> lastWritten(n, -1);
    int lastLower = -1;
    int lastUpper = -1;
    for (int qi = 0; qi < q; ++qi) {
        int t, x;
        char c;
        cin >> t >> x >> c;
        --x;
        if (t == 1) {
            s[x] = c;
            lastWritten[x] = qi;
        } else if (t == 2) {
            lastLower = qi;
        } else if (t == 3) {
            lastUpper = qi;
        }
    }

    if (lastLower == -1 && lastUpper == -1) {
        cout << s << endl;
        return 0;
    }

    if (lastLower > lastUpper) {
        for (int i = 0; i < n; ++i) {
            if (lastWritten[i] < lastLower) {
                s[i] = tolower(s[i]);
            }
        }
    } else {
        for (int i = 0; i < n; ++i) {
            if (lastWritten[i] < lastUpper) {
                s[i] = toupper(s[i]);
            }
        }
    }
    cout << s << endl;

    return 0;
}