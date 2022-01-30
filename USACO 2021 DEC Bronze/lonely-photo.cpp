#include </Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1/bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string cows;
    cin >> n >> cows;
    int gCount = 0;
    int hCount = 0;
    string substring;
    for (int i = 0; i <= cows.length()-3; i++) {
        substring = cows.substr(i, 3);
        for (int j = 0; j < substring.length(); j++) {
            if (substring[j] == "H") {
                cout << "Found a H";
            }
            else {
                cout << "Found a G";
            }
        }
    }
    return 0;
}
