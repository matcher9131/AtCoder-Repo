#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <climits>
#include <cfloat>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <numeric>
using namespace std;
using ll = long long;


void display(const vector<int>& v) {
    if (!v.empty()) cout << v[0];
    for (int i = 1; i < v.size(); ++i) {
        cout << " " << v[i];
    }
    cout << endl;
}

struct Node {
    int value;
    int parent;
};

int main() {
    int cq;
    cin >> cq;
    vector<Node> nodes;
    nodes.reserve(cq);
    nodes.push_back({-1, 0});
    int current = 0;
    // page, nodeIndex
    unordered_map<int, int> note;

    vector<int> answer(cq);
    string s;
    int x;
    for (int i = 0; i < cq; ++i) {
        cin >> s;
        if (s == "ADD") {
            cin >> x;
            nodes.push_back({x, current});
            current = nodes.size() - 1;
            answer[i] = x;
        } else if (s == "DELETE") {
            current = nodes[current].parent;
            answer[i] = nodes[current].value;
        } else if (s == "SAVE") {
            cin >> x;
            note[x] = current;
            answer[i] = nodes[current].value;
        } else if (s == "LOAD") {
            cin >> x;
            auto it = note.find(x);
            if (it == note.end()) {
                current = 0;
                answer[i] = -1;
            } else {
                current = it->second;
                answer[i] = nodes[current].value;
            }
        }
    }

    display(answer);

    return 0;
}