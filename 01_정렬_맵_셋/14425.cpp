#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    map<string, bool> stringMap;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        stringMap[s] = true;
    }

    int count = 0;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (stringMap[s]) {
            count++;
        }
    }

    cout << count << '\n';

    return 0;
}