#include <iostream>
#include <vector>
using namespace std;


void display(const vector<int>& v, string split = ", ", bool showsBracket = true, bool outputsNewLine = true) {
    if (showsBracket) cout << "[";
    if (!v.empty()) cout << v[0];
    for (int i = 1; i < v.size(); ++i) {
        cout << split << v[i];
    }
    if (showsBracket) cout << "]";
    if (outputsNewLine) cout << endl;
}

void display(const vector<int>& v) {
    if (!v.empty()) cout << v[0];
    for (int i = 1; i < v.size(); ++i) {
        cout << " " << v[i];
    }
    cout << endl;
}
