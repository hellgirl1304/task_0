#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> mergeArrays(const vector<int>& array_a, const vector<int>& array_b) {
    int a = static_cast<int>(array_a.size());
    int b = static_cast<int>(array_b.size());
    vector<int> res(a + b);

    int i = 0;
    --a;
    --b;
    while (a >= 0 || b >= 0) {
        if (a < 0 || (b >= 0 && array_a[a] <= array_b[b])) {
            res[i] = array_b[b];
            --b;
        }
        else {
            res[i] = array_a[a];
            --a;
        }
        ++i;
    }
    return res;
}

int main() {
    int a, b;
    cin >> a >> b;
    vector<int> array_a(a);
    vector<int> array_b(b);

    int value = 1;
    std::generate(array_a.begin(), array_a.end(), [&value]() {
        int currentValue = value;
        value += 2;
        return currentValue;
        });

    value = 2;
    std::generate(array_b.begin(), array_b.end(), [&value]() {
        int currentValue = value;
        value += 2;
        return currentValue;
        });

    cout << "array_a: ";
    for (auto item : array_a) {
        cout << item << " ";
    }
    cout << "\narray_b: ";
    for (auto item : array_b) {
        cout << item << " ";
    }
    cout << "\nres: ";

    vector<int> res = mergeArrays(array_a, array_b);
    for (auto item : res) {
        cout << item << " ";
    }
}