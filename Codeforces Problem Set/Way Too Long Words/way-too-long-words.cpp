#include <bits/stdc++.h>

int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::string word;
    std::cin >> word;
    if (word.size() > 10) {
      char firstLetter = word[0];
      char lastLetter = word.back();
      int betweenLetters = word.size() - 2;
      std::cout << firstLetter << betweenLetters << lastLetter << std::endl;
    }
    else {
      std::cout << word << std::endl;
    }
  }

  return 0;
}
