#include </Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1/bits/stdc++.h>

int main(int argc, char *argv[]) {
  int problems, person1, person2, person3;
  int problems_solvable = 0;

  std::cin >> problems;

  for (int i=0; i < problems; i++) {
    std::cin >> person1 >> person2 >> person3;
    if (person1 + person2 + person3 >= 2) {
      problems_solvable += 1;
    }
  }

  std::cout << problems_solvable;
  return 0;
}
