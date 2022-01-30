#include </Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1/bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    vector<int> desiredTemps;
    vector<int> initialTemps;
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        desiredTemps.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        cin >> temp;
        initialTemps.push_back(temp);
    }
    //moves += *max_element(desiredTemps.begin(), desiredTemps.end()) - *max_element(initialTemps.begin(), initialTemps.end());
    vector<int> differences;
    for (int i = 0; i < n; i++) {
        differences[i] = desiredTemps[i] - initialTemps[i];
    }
    int moves = 0;
    int* i1;
    i1 = max_element(differences, differences + 4);
    for (int i = 0; i < n; i++) {
        if (differences[i] == 0) {
            moves += *max_element(differences.begin(), differences.end());
        }
    }    
    
    

    return 0;
}
