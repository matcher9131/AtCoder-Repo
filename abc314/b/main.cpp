#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<set<int>> a(n, set<int>());
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        for (int j = 0; j < c; ++j) {
            int tmp;
            cin >> tmp;
            a[i].insert(tmp);
        }
    }
    int x;
    cin >> x;
    
    vector<pair<int, int>> target;
    for (int i = 0; i < n; ++i) {
        if (a[i].find(x) != a[i].end()) {
            target.emplace_back(a[i].size(), i + 1);
        }
    }

    int minCount = 100;
    for (const auto& [c, i] : target) {
        if (c < minCount) minCount = c;
    }

    vector<int> answer;
    for (const auto& [c, i] : target) {
        if (c == minCount) answer.push_back(i);
    }

    cout << answer.size() << endl;
    if (answer.size() > 0) {
        for (int i = 0; i < answer.size() - 1; ++i) {
            cout << answer[i] << " ";
        }
        cout << answer.back() << endl;
    }

    return 0;
}