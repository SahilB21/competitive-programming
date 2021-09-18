#include </Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1/bits/stdc++.h>

int main(int argc, char *argv[]) {

  int w;
  std::cin >> w;


  if (w > 2 && w % 2 == 0) {
    std::cout << "YES" << std::endl;
    return 0;
  }
  std::cout << "NO" << std::endl;


  return 0;
}
