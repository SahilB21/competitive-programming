#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    int swaps = 0;
    std::map<char, int> frequency;
    std::pair<char, int> map_pair;
    int temp_max = 0;
    char repeated_char;
    int index_1;
    int index_2;
    cin >> n >> s;

    // Calculates base number of swaps needed and records frequency of each letter in string
    for (int i = 0; i < n; i++) {
        swaps += i;
        frequency[s[i]] += 1;
    }

    for (int j = 0; j < n; j++) {
        map_pair.first = s[j];
        map_pair.second  = frequency[s[j]];
        if (map_pair.second > temp_max) {
            temp_max = map_pair.second;
            repeated_char = map_pair.first;
        }
        else {
            continue;
        }
    }

    // Finds the first index of the repeated letter
    for (int k = 0; k < n; k++) {
        if (s[k] == repeated_char) {
            index_2 = k;
        }
    }

    // Finds the second index of the repeated letter
    for (int l = n-1; l >= 0; l--) {
        if (s[l] == repeated_char) {
            index_1 = l;
        }
    }

    cout << swaps - ((index_2 - index_1) * 2) << endl;

    return 0;
}