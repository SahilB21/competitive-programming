#include </Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1/bits/stdc++.h>
#include <string>

using namespace std;

int main() {
    ifstream input;
    input.open("beads.in");
    int numbers;
    string beads;
    input >> numbers;
    input >> beads;
    cout << numbers;
    cout << beads;

    // go thru each possible split location
    for (int i = 1; i < beads.length(); i++) {
        // right side of split
        // set the color and look for string of those
        char rightColor = beads[i+1];
        // go thru the rest of the beads and count until it reaches diff color
        int rightAmount = 0;
        int j = i+1;
        while (beads[j] == rightColor) {
            if (j > beads.length()) {
                j = 0;
            }
            rightAmount++;
            j++;
        }
        cout << rightAmount;
    }
}