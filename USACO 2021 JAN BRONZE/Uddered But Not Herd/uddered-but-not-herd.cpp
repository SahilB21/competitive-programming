#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
  std::string alphabet = "";
  std::string letters = "";
  int times_sang = 0;
  int counted = 0;
  int current_letter = 0;

  std::cin >> alphabet;
  std::cin >> letters;

  while (counted < letters.length()) {
    for (int i = 0; i < 26; i++) {
      if (alphabet[i] == letters[current_letter]) {
        counted += 1;
        current_letter += 1;
      }
    }
    times_sang += 1;
  }

  std::cout << times_sang;

  return 0;
}
