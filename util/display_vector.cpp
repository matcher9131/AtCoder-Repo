#include <iostream>
#include <vector>
using namespace std;

void display(const vector<int>& v) {
    cout << "[";
    if (!v.empty()) cout << v[0];
    for (int i = 1; i < v.size(); ++i) {
        cout << ", " << v[i];
    }
    cout << "]" << endl;
}