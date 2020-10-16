#include <iostream>

using namespace std;

int main() {
    int n;
    string s;
    string reverse;
    cin >> n >> s;
    
    for (int i = n; i >= 0; i--) {
        reverse += s[i];
    }

    cout << reverse << endl;

    return 0;
}