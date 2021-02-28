#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
  int n;
  std::cin >> n;
  std::string words;
  std::vector<std::string> all_words;
  std::vector<std::string> key_words;
  std::string year_cycle[12] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
  bool elsie = false;
  int years = 0;
  int bessie_index;
  bool bessie_found = false;

  for (int i = 0; i < n*8; i++) {
    std::cin >> words;
    all_words.push_back(words);
  }
  for (int t = 0; t < n; t++) {
    key_words.push_back(all_words[t*8]);
    key_words.push_back(all_words[3+(t*8)]);
    key_words.push_back(all_words[4+(t*8)]);
    key_words.push_back(all_words[7+(t*8)]);
  }

  for (int k = 0; k < n; k++) {
    if (bessie_found == false) {
      if (key_words[3+(k*4)] == "Bessie") {
        bessie_index = k;
        if (key_words[1+(k*4)] == "previous") {
          for (int s = 0; s < 12; s++) {
            if (year_cycle[s] == key_words[2+(k*4)]) {
              years += 12-s;
              bessie_found = true;
            }
          }
        }
        else {
          for (int s = 0; s < 12; s++) {
            if (year_cycle[s] == key_words[2+(k*4)]) {
              years -= 12-s;
            }
          }
        }
      }
    }
  }

  while (elsie == false) {
    for (int f = 0; f < n; f++) {
      //std::cout << "incrementing f";
      if (key_words[f*4] == "Elsie") {
        elsie = true;
      }
      if (key_words[3+(f*4)] == key_words[bessie_index*4]) {
        bessie_index = f;
        if (key_words[1+(f*4)] == "previous") {
          for (int r = 0; r < 12; r++) {
            if (year_cycle[r] == key_words[2+(f*4)]) {
              for (int o = 0; o < 12; o++) {
                if (year_cycle[o] == key_words[2+((f-1)*4)]) {
                  years += o+(12-r);
                }
              }
            }
          }
        }
        else {
          for (int r = 0; r < 12; r++) {
            if (year_cycle[r] == key_words[2+(f*4)]) {
              for (int o = 0; o < 12; o++) {
                if (year_cycle[o] == key_words[2+((f-1)*4)]) {
                  years -= abs(o-(12-r));
                }
              }
            }
          }
        }
      }
    }
  }

  std::cout << years;

  return 0;
}
